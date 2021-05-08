#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <qabstractitemmodel.h>
#include <qvariant.h>
#include <vector>

using std::vector;

class TableModel : public QAbstractTableModel {

    vector<vector<QVariant>> dataList;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &child) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


};

#endif // TABLEMODEL_H
