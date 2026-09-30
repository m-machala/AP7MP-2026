#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>

void sayHello() {
    qDebug() << "hello";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button("Hello");
    button.setGeometry(500, 500, 300, 200);
    button.show();

    QObject::connect(&button, &QPushButton::clicked, sayHello);

    //MainWindow w;
    //w.show();
    return QApplication::exec();
}
