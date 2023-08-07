#include <QtQmlDom/private/qqmldomitem_p.h>
// comparisons of two DomItems
#include <QtQmlDom/private/qqmldomcompare_p.h>
// field filters to compare only selected fields (ignore for example location changes)
#include <QtQmlDom/private/qqmldomfieldfilter_p.h>
// needed to edit and cast to concrete type (PropertyDefinition, ScriptExpression,...)
#include <QtQmlDom/private/qqmldomelements_p.h>
// cast of the top level items (DomEnvironments,...)
#include <QtQmlDom/private/qqmldomtop_p.h>
#include <QtQmlDom/private/qqmldomoutwriter_p.h>
#include <QtQmlDom/private/qqmldomlinewriter_p.h>

#include <QCoreApplication>

#include <QDebug>

#include <QtCore/QLibraryInfo>

using namespace QQmlJS::Dom;

int main(int argc, char *argv[])
{
    // dumping with no filter takes to much time to finish
    FieldFilter defaultFilter = FieldFilter::defaultFilter();
    FieldFilter basicFilter = FieldFilter{};

    // Making the Envirionment node
    //  set import path
    QStringList qmltypeDirs = QStringList { QLibraryInfo::path(QLibraryInfo::Qml2ImportsPath) };;
    //  set options
    DomEnvironment::Options options = DomEnvironment::Option::SingleThreaded;
    //  create DomEnvironment
    std::shared_ptr<DomEnvironment> envPtr(new DomEnvironment(qmltypeDirs, options));

    DomItem env(envPtr);

    DomItem item = DomItem::fromCode(QString("import QtQuick 2.0; Rectangle { color: 'red'; width: 20; height: 20 }"));

    QTextStream ts(stdout);
    auto sink = [&ts](QStringView v) {

        ts << v; /* ts.flush(); */
    };
    item.dump(sink, 0, basicFilter);

    MutableDomItem dItem(item);
    MutableDomItem qmlObj = dItem.qmlObject(GoTo::MostLikely);

    PropertyDefinition b;
    b.name = QLatin1String("xx");
    b.typeName = QLatin1String("int");
    // if we make t true we also have to give a value...
    MutableDomItem addedPDef = qmlObj.addPropertyDef(b);

    dItem.commitToBase();

    QString outputString;
    QTextStream textStream(&outputString);
    LineWriter lw([&textStream](QStringView s) { textStream << s; textStream.flush();}, QString());
    OutWriter ow(lw);
    ow.indentNextlines = true;

    dItem.writeOut(ow);
    ow.eof();

    ts << outputString;
    ts.flush();
}



