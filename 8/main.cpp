#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("m_machala_AP7MP");
    QCoreApplication::setApplicationName("CV5");

    QFile styleFile(":/styles.qss");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());

    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}
