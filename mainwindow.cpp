#include "mainwindow.h"
#include "tablemodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Drag and Drop app");

    tableView = new QTableView();

    TableModel *model = new TableModel();
    tableView->setModel(model);
    tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    tableView->setDragEnabled(true);
    tableView->viewport()->setAcceptDrops(true);
    tableView->setDropIndicatorShown(true);
    tableView->setDragDropMode(QAbstractItemView::DragDrop);
    tableView->setDragDropOverwriteMode(false);

    setCentralWidget(tableView);

}

MainWindow::~MainWindow()
{
    delete tableView;
}

