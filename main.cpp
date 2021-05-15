#include "mainwindow.h"

#include <QApplication>
#include <QCheckBox>

using std::vector;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
