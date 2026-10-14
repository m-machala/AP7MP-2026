#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_withoutDPH_textChanged(const QString &arg1);

    void on_twelvePercent_clicked();

    void on_twentyOnePercent_clicked();

    void setToCzech();

    void setToEnglish();

private:
    Ui::MainWindow *ui;
    void updateValue(QString inputString);
    QTranslator *translator;

};
#endif // MAINWINDOW_H
