#include "mainwindow.h"

#include <QAbstractTableModel>
#include <qabstractitemmodel.h>
using std::vector;


class TableModel : public QAbstractTableModel {

    vector<vector<QVariant>> dataList{{"Lion", "Tiger", "Bear"}};

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return createIndex(row, column);
    }

    QModelIndex parent(const QModelIndex &child) const override {
        Q_UNUSED(child);
        return QModelIndex();
    }

    QVariant virtual data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole)
            return dataList[index.row()][index.column()];
        return QVariant();
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override {
        Q_UNUSED(role);
        dataList[index.row()][index.column()] = value;
        emit dataChanged(index, index);
        return true;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return dataList.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return 3;
    }

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        Q_UNUSED(index);
        return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    }

    Qt::DropActions supportedDropActions() const override {
        return Qt::CopyAction | Qt::MoveAction;
    }

};
