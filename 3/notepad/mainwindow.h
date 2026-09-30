#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

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

protected:
    QTextEdit *textEdit = NULL;

private:
    Ui::MainWindow *ui;

protected slots:
    void saveTextAs();
    void openText();
};
#endif // MAINWINDOW_H
