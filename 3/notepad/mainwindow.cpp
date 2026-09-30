#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QFileDialog>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(100, 100, 640, 480);

    QMenu *fileMenu = new QMenu("File");
    menuBar()->addMenu(fileMenu);

    QAction *actionOpen = new QAction("Open text");
    actionOpen->setShortcut(QKeySequence::Open);
    fileMenu->addAction(actionOpen);
    connect(actionOpen, &QAction::triggered, this, &MainWindow::openText);

    QAction *actionSaveAs = new QAction("Save text as...");
    actionSaveAs->setShortcut(QKeySequence::SaveAs);
    fileMenu->addAction(actionSaveAs);
    connect(actionSaveAs, &QAction::triggered, this, &MainWindow::saveTextAs);

    fileMenu->addSeparator();

    QAction *actionQuit = new QAction("Quit");
    actionQuit->setShortcut(QKeySequence::Close);
    fileMenu->addAction(actionQuit);
    connect(actionQuit, &QAction::triggered, this, &MainWindow::close);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveTextAs() {
    qDebug() << "Saving text...";

    QString fileName = QFileDialog::getSaveFileName(this, "Save text as...", "", "Text (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        }
        else {
            QMessageBox::critical(this, "Simple Notepad", "Unable to open file.");
        }
    }
    else {
        QMessageBox::critical(this, "Simple Notepad", "File name empty.");
    }

}

void MainWindow::openText()
{
    qDebug() << "Opening text...";
    QString fileName = QFileDialog::getOpenFileName(this, "Open text file...", "", "Text (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            textEdit->setText(in.readAll());
            file.close();
        }
        else {
            QMessageBox::critical(this, "Simple Notepad", "Unable to open file.");
        }
    }
    else {
        QMessageBox::critical(this, "Simple Notepad", "File name empty.");
    }
}
