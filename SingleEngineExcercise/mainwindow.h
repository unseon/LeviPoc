#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QQuickWidget>
#include <QQmlEngine>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QQuickWidget* m_outliner;
    QQmlEngine m_engine;
};

#endif // MAINWINDOW_H
