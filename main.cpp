#include "mainwindow.h"

#include <QApplication>
#include "buttonsboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumSize(300,300);

    w.show();
    return a.exec();
}
