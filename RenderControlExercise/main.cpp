//#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include "qquickeditorwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QQuickEditorWidget editor;
    editor.resize(500, 500);
    editor.show();

    editor.renderMovie();


//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
