#include "mainwindow.h"
#include <QApplication>
#include <QtTest/qtestcase.h>
#include<cassert>
#include "test_main_windows.h"

int main(int argc, char *argv[])
{

    TestAverage();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
