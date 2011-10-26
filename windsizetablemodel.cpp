
#include "windsizetablemodel.h"
#include <iostream>

WindSizeTableModel::WindSizeTableModel(QObject *parent, SailSizeModel *model)
    : QAbstractTableModel(parent) {
    this->model = model;
    QObject::connect(this->model,SIGNAL(updated()), this, SLOT(modelUpdated()));
}

WindSizeTableModel::~WindSizeTableModel() {

}

void WindSizeTableModel::modelUpdated() {

    this->beginResetModel();
    this->endResetModel();

}

int WindSizeTableModel::rowCount(const QModelIndex &parent) const {
    return this->model->windSpeeds()->size();
}

int WindSizeTableModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant WindSizeTableModel::data(const QModelIndex &parent, int role) const {

    if (role == Qt::DisplayRole) {

        int windSpeed = this->model->windSpeeds()->at(parent.row());
        int weight    = this->model->weight();

        if (parent.column() == 0) {
            return QString("%1").arg(windSpeed);
        } else {
            double sailSize = (1.34*weight/(windSpeed*1.94384449));
            QString s;
            if (sailSize < 16) {
                s.sprintf("%.1f", sailSize);
            } else {
                s.sprintf("16+");
            }
            return s;
            //return QString("%1").arg(val);
        }

    } else if (role == Qt::TextAlignmentRole) {
        return Qt::AlignRight;
    } else {
        return QVariant();
    }
}

QVariant WindSizeTableModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        if (section == 0) {
            return QString("Wind Speed (m/s)");
        } else {
            return QString::fromUtf8("Sail Size (m\u00B2)");
        }
    else
        return QString("Row %1").arg(section);
}


