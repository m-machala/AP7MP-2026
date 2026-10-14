#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("m_machala_AP7MP");
    QCoreApplication::setApplicationName("CV5");

    MainWindow w;
    w.show();
    return a.exec();
}
