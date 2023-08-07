#ifndef QMLMETA_H
#define QMLMETA_H

#include <QObject>

class QmlMeta : public QObject
{
    Q_OBJECT
public:
    explicit QmlMeta(QObject *parent = nullptr);

signals:

public:
    Q_INVOKABLE QString

};

#endif // QMLMETA_H
