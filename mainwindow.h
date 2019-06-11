#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QProcess>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
void Ping();
void PingErr();
private slots:
    void on_pushButton_clicked();
void TimeProc();

void on_pushButton_2_clicked();

void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
   QProcess *timer;
   QProcess *ping;
};

#endif // MAINWINDOW_H
