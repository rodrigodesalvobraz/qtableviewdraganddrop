#include "mainwindow.h"

#include <QAbstractTableModel>
#include <qabstractitemmodel.h>
#include "tablemodel.h"

using std::vector;


QModelIndex TableModel::index(int row, int column, const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return createIndex(row, column);
}

QModelIndex TableModel::parent(const QModelIndex &child) const {
    Q_UNUSED(child);
    return QModelIndex();
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole)
        return dataList[index.row()][index.column()];
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(role);
    dataList[index.row()][index.column()] = value;
    emit dataChanged(index, index);
    return true;
}

int TableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return dataList.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    Q_UNUSED(index);
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
}

Qt::DropActions TableModel::supportedDropActions() const {
    return Qt::CopyAction | Qt::MoveAction;
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent) {
    if (row != -1 and count > 0) {
        beginInsertRows(parent, row, row + count - 1);
        for (int i = 0; i != count; i++)
            dataList.emplace(dataList.begin() + row, columnCount());
        endInsertRows();
        emit dataChanged(index(row, 0), index(row + count - 1, columnCount()));
        emit layoutChanged();
        return true;
    }
    else {
        return false;
    }
}

bool TableModel::removeRows(int row, int count, const QModelIndex &parent) {
    if (row > 0 and count > 0) {
        beginRemoveRows(parent, row, row + count - 1);
        dataList.erase(dataList.begin() + row, dataList.begin() + row + count);
        endRemoveRows();
        emit dataChanged(index(row, 0), index(row + count - 1, columnCount()));
        emit layoutChanged();
        return true;
    }
    else {
        return false;
    }
}
