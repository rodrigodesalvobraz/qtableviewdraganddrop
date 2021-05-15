#include "mainwindow.h"

#include <QAbstractTableModel>
#include <QFlags>
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
    auto flags = Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsDragEnabled;
    if (itemsAreDropEnabled)
        flags |=  Qt::ItemIsDropEnabled;
    return flags;
}

Qt::DropActions TableModel::supportedDropActions() const {
    auto flags = Qt::DropActions();
    if (moveActionEnabled)
        flags |= Qt::MoveAction;
    if (copyActionEnabled)
        flags |= Qt::CopyAction;
    return flags;
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
    if (row != -1 and count > 0) {
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

bool TableModel::moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) {
    std::exit(-1);
    if (sourceRow != -1 and destinationChild != -1 and count > 0) {
        if (destinationChild >= sourceRow and destinationChild < sourceRow + count) // destination is in the middle of origin range, so reject
            return false;
        beginMoveRows(sourceParent, sourceRow, sourceRow + count - 1, destinationParent, destinationChild);
        dataList.insert(dataList.begin() + destinationChild, dataList.begin() + sourceRow, dataList.begin() + sourceRow + count);
        dataList.erase(dataList.begin() + sourceRow, dataList.begin() + sourceRow + count);
        endMoveRows();
        emit dataChanged(index(sourceRow, 0), index(sourceRow + count - 1, columnCount()));
        emit dataChanged(index(destinationChild, 0), index(destinationChild + count - 1, columnCount()));
        emit layoutChanged();
        return true;
    }
    else {
        return false;
    }
}
