#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QString>
#include "Amethyst.hpp"
#include "Diamond.hpp"


// Реализация MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateObjectsList();
    updateAverageValue();
}

MainWindow::~MainWindow()
{
    qDeleteAll(objects);
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QDialog dialog;
    dialog.setWindowTitle("Добавить камень");

    QComboBox typeComboBox;
    typeComboBox.addItem("Аметист");
    typeComboBox.addItem("Алмаз");

    QLineEdit nameEdit;
    QLineEdit valueEdit;
    QLineEdit param1Edit;
    QLineEdit descEdit;

    QFormLayout form(&dialog);
    form.addRow("Камень:", &typeComboBox);
    form.addRow("Вес:", &nameEdit);
    form.addRow("Цена:", &valueEdit);


    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        int name = nameEdit.text().toInt();
        int value = valueEdit.text().toInt();

        if (typeComboBox.currentIndex() == 0) {
            objects.append(new Amethyst(name, value));
        } else {
            objects.append(new Diamond(name, value));
        }

        updateObjectsList();
        updateAverageValue();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    int index = ui->objectsComboBox->currentIndex();
    if (index >= 0 && index < objects.size()) {
        delete objects.takeAt(index);
        updateObjectsList();
        updateAverageValue();
    }
}

void MainWindow::on_editButton_clicked()
{
    int index = ui->objectsComboBox->currentIndex();
    if (index >= 0 && index < objects.size()) {
        delete objects.takeAt(index);
        updateObjectsList();
        updateAverageValue();
        MainWindow::on_addButton_clicked();
        updateObjectsList();
        updateAverageValue();
    }
}

void MainWindow::updateObjectsList()
{
    ui->objectsComboBox->clear();
    for (Stone* obj : objects) {
        ui->objectsComboBox->addItem( QString::fromStdString(obj->GetInfo()));
    }
}



double MainWindow::calaculateAverageValue(const double sum, const unsigned int num)
{
    double average = sum / num;
    return average;
}


void MainWindow::updateAverageValue()
{
    if (objects.isEmpty()) {
        ui->averageLabel->setText("Средняя цена: N/A");
        return;
    }

    double sum = 0;
    for (Stone* obj : objects) {
        sum += obj->GetPrice();
    }

    double average = calaculateAverageValue(sum, objects.size());
    ui->averageLabel->setText(QString("Средняя цена: %1").arg(average));
}
