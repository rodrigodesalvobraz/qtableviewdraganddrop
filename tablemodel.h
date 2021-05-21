#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <qabstractitemmodel.h>
#include <qvariant.h>
#include <vector>

using std::vector;

class TableModel : public QAbstractTableModel {

    Q_OBJECT

public:

    bool itemsAreDropEnabled = true;
    bool moveActionEnabled = true;
    bool copyActionEnabled = false;


    vector<vector<QVariant>> dataList{
        {"Lion", "Tiger", "Bear"},
        {"Gazelle", "Ox", "Pig"},
        {"Mouse", "Cat", "Dog"},
        {"Cow", "Giraffe", "Rhino"},
    };

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &child) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Qt::DropActions supportedDropActions() const override;

    bool insertRows(int row, int count, const QModelIndex &parent) override;

    bool removeRows(int row, int count, const QModelIndex &parent) override;

    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override;

};

#endif // TABLEMODEL_H
