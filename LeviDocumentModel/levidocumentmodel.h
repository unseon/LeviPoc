#ifndef LEVIDOCUMENTMODEL_H
#define LEVIDOCUMENTMODEL_H

#include <QAbstractListModel>

class LeviDocumentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit LeviDocumentModel(QObject *parent = nullptr);
    void addItem(const QString typeName, const QString moduleName);
};

#endif // LEVIDOCUMENTMODEL_H
