#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings;
    QString language = settings.value("general/language", "cz_CS").toString();

    if (language == "en_US") {
        ui->actionEnglish->setChecked(true);
        ui->actionCzech->setChecked(false);
    }

    translator = new QTranslator();
    translator->load("CV4_" + language + ".qm");
    qApp -> installTranslator(translator);
    ui->retranslateUi(this);

    connect(ui->actionCzech, &QAction::triggered, this, &MainWindow::setToCzech);
    connect(ui->actionEnglish, &QAction::triggered, this, &MainWindow::setToEnglish);

    ui->withoutDPH->setText(tr("Ahoj"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_withoutDPH_textChanged(const QString &arg1)
{
    MainWindow::updateValue(arg1);
}

void MainWindow::updateValue(QString inputString) {
    float inputValue = (float)inputString.toInt();
    if(ui->twelvePercent->isChecked()) {
        ui->withDPH->setText(QVariant(inputValue + inputValue * 0.12).toString());
    }
    else {
        ui->withDPH->setText(QVariant(inputValue + inputValue * 0.21).toString());
    }
}


void MainWindow::on_twelvePercent_clicked()
{
    QString currentValue = ui->withoutDPH->text();
    MainWindow::updateValue(currentValue);
}


void MainWindow::on_twentyOnePercent_clicked()
{
    MainWindow::on_twelvePercent_clicked();
}

void MainWindow::setToCzech() {
    QSettings settings;
    settings.setValue("general/language", "cs_CZ");
    translator->load("CV4_cs_CZ.qm");
    ui->actionCzech->setChecked(true);
    ui->actionEnglish->setChecked(false);
    ui->retranslateUi(this);
}

void MainWindow::setToEnglish() {
    QSettings settings;
    settings.setValue("general/language", "en_US");
    translator->load("CV4_en_US.qm");
    ui->actionCzech->setChecked(false);
    ui->actionEnglish->setChecked(true);
    ui->retranslateUi(this);
}
