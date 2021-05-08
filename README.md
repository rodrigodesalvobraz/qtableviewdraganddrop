An attempt at a minimal example of defining a model for QTableView in Qt 5.15.

Currently the project cannot be built by Qt Creator 4.14.2 Based on Qt 5.15.2 (Clang 11.0 (Apple), 64 bit).

I've created the repository for getting help. The linker complains that there is no vtable for class `TableModel`. It says:

```
/Users/rodrigobraz/Documents/Qt Projects/build-tabledraganddrop-Desktop_Qt_5_15_2_clang_64bit-Debug/mainwindow.o:-1: error: Undefined symbols for architecture x86_64:
  "vtable for TableModel", referenced from:
      TableModel::TableModel() in mainwindow.o
  NOTE: a missing vtable usually means the first non-inline virtual member function has no definition.
```

`TableModel` is derived from `QAbstractTableModel`, which does not have pure virtual methods. The base class for `QAbstractItemModel` does have four pure virtual models:
  
```
int QAbstractItemModel::rowCount(const QModelIndex &parent = QModelIndex()) const

int QAbstractItemModel::columnCount(const QModelIndex &parent = QModelIndex()) const

QVariant QAbstractItemModel::data(const QModelIndex &index, int role = Qt::DisplayRole) const

QModelIndex QAbstractItemModel::index(int row, int column, const QModelIndex &parent = QModelIndex()) const

QModelIndex QAbstractItemModel::parent(const QModelIndex &index) const
```

but my class implements them all, so I am not sure why the vtable is not being generated.
