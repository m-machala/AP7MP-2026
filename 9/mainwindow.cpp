#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);
    ui->listView->setModel(model);

    ui->listView->setContextMenuPolicy(Qt::ActionsContextMenu);

    QAction *actionDetail = new QAction("Show detail");
    ui->listView->addAction(actionDetail);

    QAction *actionClipboard = new QAction("Copy to clipboard");
    ui->listView->addAction(actionClipboard);

    connect(ui->treeView, &QTreeView::clicked, ui->listView, &QListView::setRootIndex);
    connect(ui->treeView, &QTreeView::clicked, [&](const QModelIndex &index){
        ui->textEdit->append(model->filePath(index));
    });
    connect(actionDetail, &QAction::triggered, this, &MainWindow::showDetail);
    connect(actionClipboard, &QAction::triggered, this, &MainWindow::copyToClipboard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDetail()
{
    QFileInfo fileInfo = model->fileInfo(ui->listView->currentIndex());

    QMessageBox::information(this, "File Browser", QString("File name: %1\nLast edited: %2\nSize: %3")
                                                       .arg(fileInfo.fileName())
                                                       .arg(fileInfo.lastModified().toString())
                                                       .arg(fileInfo.size())
                             );
}

void MainWindow::copyToClipboard()
{
    QString filePath = model->filePath(ui->listView->currentIndex());
    qApp->clipboard()->setText(filePath);
}
