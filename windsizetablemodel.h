#ifndef WINDSIZETABLEMODEL_H
#define WINDSIZETABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QModelIndex>
#include <QSet>

#include "sailsizemodel.h"

class WindSizeTableModel : public QAbstractTableModel
{

    Q_OBJECT

protected:
    SailSizeModel *model;

public:
    WindSizeTableModel(QObject * parent = 0, SailSizeModel *model = 0);
    ~WindSizeTableModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

public slots:
    void modelUpdated();

};


#endif // WINDSIZETABLEMODEL_H
