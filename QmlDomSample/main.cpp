#include <QtCore/qdebug.h>
#include <QtCore/qfile.h>
#include <QtCore/qfileinfo.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qdir.h>
#include <QtCore/QTextStream>
#include <QtCore/QThread>

#include <QtQmlDom/private/qqmldomtop_p.h>
#include <QtQmlDom/private/qqmldomfilewriter_p.h>
#include <QtQmlDom/private/qqmldomoutwriter_p.h>
#include <QtQmlDom/private/qqmldomelements_p.h>
#include <QtQmlDom/private/qqmldomfieldfilter_p.h>

#include <cstdio>
#include <optional>

#include <QCoreApplication>

#include <QtCore/qlibraryinfo.h>
using namespace QQmlJS::Dom;

int main(int argc, char *argv[])
{
    FieldFilter filter = FieldFilter::defaultFilter();
    QStringList qmltypeDirs = QStringList { QLibraryInfo::path(QLibraryInfo::Qml2ImportsPath) };;
    DomEnvironment::Options options = DomEnvironment::Option::SingleThreaded;
    std::shared_ptr<DomEnvironment> envPtr(new DomEnvironment(qmltypeDirs, options));
    DomItem env(envPtr);
    DomItem qmlFile;
    QString s("Sample.qml");
    env.loadFile(
                s, QString(),
                [&qmlFile](Path path, const DomItem &, const DomItem &newIt) {
                    qDebug() << "Path: " << path;
                    qmlFile = newIt;
                },
                LoadOption::DefaultLoad, DomType::QmlFile);
    envPtr->loadPendingDependencies(env);

    qDebug() << "qmlFile";
    qDebug() << qmlFile.canonicalFilePath();


    qDebug() << "will dump\n";

    QTextStream ts(stdout);
    auto sink = [&ts](QStringView v) {

        ts << v; /* ts.flush(); */
    };
    env.dump(sink, 0, filter);

    //ts << "\n";
    //ts << qmlFile.fields()[0];
    //ts << qmlFile.field(QStringView("currentVersion"));

    DomItem comp = qmlFile.component(GoTo::MostLikely);
    //DomItem comp = qmlFile.fileObject(GoTo::MostLikely);
    //comp.dump(sink, 0, filter);

    //ts << comp.canonicalPath().toString();
    Qt::endl(ts).flush();




    //qmlFile.field("type");


    return 0;
}
