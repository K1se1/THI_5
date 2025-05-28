#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include "Stone.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Базовый класс объекта
class MyObject {
public:
    virtual ~MyObject() {}
    virtual QString getName() const = 0;
    virtual double getValue() const = 0;
    virtual void edit() = 0;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
