    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <tablemodel.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTableView *tableView;
    TableModel *model;
    QCheckBox *dragDropOverwriteModeCheckbox;
    QCheckBox *itemsAreDropEnabledCheckbox;
    QCheckBox *moveActionEnabledCheckbox;
    QCheckBox *copyActionEnabledCheckbox;
    QVBoxLayout *layout;
    QWidget* mainWidget;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void dragDropOverwriteModeCheckboxClicked();
    void itemsAreDropEnabledCheckboxClicked();
    void moveActionEnabledCheckboxClicked();
    void copyActionEnabledCheckboxClicked();
};
#endif // MAINWINDOW_H
