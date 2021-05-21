#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>
#include <QDropEvent>


class MyTableView: public QTableView {

    Q_OBJECT

    int m_dropRow;

public:

    MyTableView(QWidget *parent)
        :  QTableView(parent), m_dropRow(0)
    {
       setSelectionMode(QAbstractItemView::SingleSelection);
       setSelectionBehavior(QAbstractItemView::SelectRows);
       setDragEnabled(true);
       setAcceptDrops(true);
       setDragDropMode(QAbstractItemView::DragDrop);
       setDefaultDropAction(Qt::MoveAction);
       setDragDropOverwriteMode(false);
       setDropIndicatorShown(true);
    }

    Q_INVOKABLE int selectedRow() const
    {
       QItemSelectionModel *selection = selectionModel();
       return selection->hasSelection() ? selection->selectedRows().front().row() : -1;
    }

    void reset()
    {
       QTableView::reset();

       QObject::connect(model(), &QAbstractTableModel::rowsInserted, this, [this](const QModelIndex &parent, int first, int last) {
           m_dropRow = first;
       });
    }

    void dropEvent(QDropEvent *e)
    {
       if (e->source() != this || e->dropAction() != Qt::MoveAction)
          return;

       int dragRow = selectedRow();

       QTableView::dropEvent(e);  // m_dropRow is set by inserted row

       if (m_dropRow > dragRow)
          --m_dropRow;

       QMetaObject::invokeMethod(this,
                                 std::bind(&MyTableView::selectRow, this, m_dropRow),
                                 Qt::QueuedConnection);  // Postpones selection
    }


};

#endif // MYTABLEVIEW_H
