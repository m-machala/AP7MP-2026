#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_calculateButton_clicked();

    void on_inputLine_textChanged(const QString &arg1);

    void on_lowPercent_clicked();

    void on_highPercent_clicked();

private:
    Ui::MainWindow *ui;
    void calculatePrice();
};
#endif // MAINWINDOW_H
