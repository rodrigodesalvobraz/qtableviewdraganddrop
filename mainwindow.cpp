#include "mainwindow.h"
#include "tablemodel.h"

#include <QCheckBox>
#include <QVBoxLayout>
#include <qmenubar.h>

#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Drag and Drop app");

    tableView = new QTableView();

    model = new TableModel();
    tableView->setModel(model);
    tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    tableView->setDragEnabled(true);
    tableView->viewport()->setAcceptDrops(true);
    tableView->setDropIndicatorShown(true);
    tableView->setDragDropMode(QAbstractItemView::DragDrop);
    tableView->setDragDropOverwriteMode(false);

    dragDropOverwriteModeCheckbox = new QCheckBox("DragDropOverwriteMode");
    itemsAreDropEnabledCheckbox = new QCheckBox("Items are drop-enabled");
    moveActionEnabledCheckbox = new QCheckBox("MoveAction enabled");
    copyActionEnabledCheckbox = new QCheckBox("CopyAction enabled");

    dragDropOverwriteModeCheckbox->setChecked(tableView->dragDropOverwriteMode());
    itemsAreDropEnabledCheckbox->setChecked(model->itemsAreDropEnabled);
    moveActionEnabledCheckbox->setChecked(model->moveActionEnabled);
    copyActionEnabledCheckbox->setChecked(model->copyActionEnabled);

    connect(dragDropOverwriteModeCheckbox, SIGNAL(clicked(bool)), this, SLOT(dragDropOverwriteModeCheckboxClicked()));
    connect(itemsAreDropEnabledCheckbox, SIGNAL(clicked(bool)), this, SLOT(itemsAreDropEnabledCheckboxClicked()));
    connect(moveActionEnabledCheckbox, SIGNAL(clicked(bool)), this, SLOT(moveActionEnabledCheckboxClicked()));
    connect(copyActionEnabledCheckbox, SIGNAL(clicked(bool)), this, SLOT(copyActionEnabledCheckboxClicked()));

    layout = new QVBoxLayout();

    layout->addWidget(tableView);
    layout->addWidget(dragDropOverwriteModeCheckbox);
    layout->addWidget(itemsAreDropEnabledCheckbox);
    layout->addWidget(moveActionEnabledCheckbox);
    layout->addWidget(copyActionEnabledCheckbox);

    mainWidget = new QWidget();

    mainWidget->setLayout(layout);

    setCentralWidget(mainWidget);

}

MainWindow::~MainWindow()
{
    delete tableView;
    delete model;
    delete dragDropOverwriteModeCheckbox;
    delete itemsAreDropEnabledCheckbox;
    delete moveActionEnabledCheckbox;
    delete copyActionEnabledCheckbox;
    delete layout;
    delete mainWidget;
}

void MainWindow::dragDropOverwriteModeCheckboxClicked()
{
    tableView->setDragDropOverwriteMode(dragDropOverwriteModeCheckbox->isChecked());
    cout << "tableView->dragDropOverwriteMode: " << tableView->dragDropOverwriteMode() << endl;
}

void MainWindow::itemsAreDropEnabledCheckboxClicked()
{
    model->itemsAreDropEnabled = itemsAreDropEnabledCheckbox->isChecked();
    cout << "model->itemsAreDropEnabled: " << model->itemsAreDropEnabled << endl;
}

void MainWindow::moveActionEnabledCheckboxClicked()
{
    model->moveActionEnabled = moveActionEnabledCheckbox->isChecked();
    cout << "model->moveActionEnabled: " << model->moveActionEnabled << endl;
}

void MainWindow::copyActionEnabledCheckboxClicked()
{
    model->copyActionEnabled = copyActionEnabledCheckbox->isChecked();
    cout << "model->copyActionEnabled: " << model->copyActionEnabled << endl;
}
