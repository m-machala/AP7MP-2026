#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    calculatePrice();
}

void MainWindow::calculatePrice()
{
    int basePrice = ui->inputLine->text().toInt();
    float taxPrice = 0;
    if (ui->lowPercent->isChecked()) {
        taxPrice = (float)basePrice * 1.12;
    }
    else {
        taxPrice = (float)basePrice * 1.21;
    }
    ui->outputLine->setText(QVariant(taxPrice).toString());
}

void MainWindow::on_inputLine_textChanged(const QString &arg1)
{
    calculatePrice();
}


void MainWindow::on_lowPercent_clicked()
{
    calculatePrice();
}


void MainWindow::on_highPercent_clicked()
{
    calculatePrice();
}

