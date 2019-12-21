#include "mainwindow.h"
#include <QQuickItem>
#include <QQmlComponent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_outliner(new QQuickWidget(this))
{
    m_outliner->setSource(QUrl::fromLocalFile(":/main.qml"));


    QQmlComponent component(&m_engine, QUrl::fromLocalFile(":/BasicItem.qml"), QQmlComponent::PreferSynchronous);

    if (component.isError()) {
        const QList<QQmlError> errorList = component.errors();
        for (const QQmlError &error : errorList)
            qWarning() << error.url() << error.line() << error;
        return;
    }

    QObject *rootObject = component.create();
    if (component.isError()) {
        const QList<QQmlError> errorList = component.errors();
        for (const QQmlError &error : errorList)
            qWarning() << error.url() << error.line() << error;
        return;
    }

    QQuickItem* rootItem = qobject_cast<QQuickItem *>(rootObject);
    if (!rootItem) {
        qWarning("run: Not a QQuickItem");
        delete rootObject;
        return;
    }

    // The root item is ready. Associate it with the window.
    rootItem->setParentItem(m_outliner->quickWindow()->contentItem());
}

MainWindow::~MainWindow()
{

}
