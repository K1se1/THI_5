#include <QTest>
#include<cassert>
#include "test_main_windows.h"

void TestAverage()
{
    assert(MainWindow::calaculateAverageValue(100, 10) == 10);
    qDebug() << "Тест 1 пройден!";
    assert(MainWindow::calaculateAverageValue(50, 5) == 10);
     qDebug() << "Тест 2 пройден!";
    assert(MainWindow::calaculateAverageValue(1, 10) == 0.1);
      qDebug() << "Тест 3 пройден!";
    assert(MainWindow::calaculateAverageValue(100, 1) ==  100);
     qDebug() << "Тест 4 пройден!";
    try
    {
        MainWindow::calaculateAverageValue(100, 0);
        qDebug() << "Тест 5 провален(((";
        assert(false);
    }
    catch(std::logic_error ex)
    {
       qDebug() << "Тест 5 пройден!";
    }

}
