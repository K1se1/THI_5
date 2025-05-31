#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include "Stone.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static double calaculateAverageValue(const double sum, const unsigned int num);
private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_editButton_clicked();
    void updateObjectsList();
    void updateAverageValue();

private:
    Ui::MainWindow *ui;
    QVector<Stone*> objects;
};

#endif // MAINWINDOW_H
