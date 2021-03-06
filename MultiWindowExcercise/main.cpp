#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QMetaObject>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject* obj = engine.rootObjects()[0];
    qDebug() << obj->metaObject()->className();
    qDebug() << obj->children()[0]->metaObject()->className();
    qDebug() << obj->children()[0]->property("title");
    qDebug() << obj->children()[0]->children()[0]->metaObject()->className();

    return app.exec();
}
