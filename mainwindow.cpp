#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QProcess(this);
    ping=new QProcess(this);
    connect(timer,SIGNAL(readyReadStandardOutput()),SLOT(TimeProc()));
    connect(ping,SIGNAL(readyReadStandardOutput()),SLOT(Ping()));
    connect(ping,SIGNAL(readyReadStandardError()),SLOT(PingErr()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
ui->centralWidget->setCursor(Qt::WaitCursor);
ui->pushButton->setDisabled(true);
        timer->start("timer");
        timer->waitForFinished();

ui->centralWidget->setCursor(Qt::ArrowCursor);
ui->pushButton->setDisabled(false);

        //ui->statusBar->showMessage(timer->readAll());
}
void MainWindow::TimeProc()
{
    QString vihlop=timer->readAllStandardOutput();
    ui->statusBar->showMessage(vihlop);


}
void MainWindow::Ping()
{
//    if (ping->waitForReadyRead(2000))
//    {
//        ui->statusBar->showMessage("Дождплся");
//    }
    QString vihlop=ping->readAllStandardOutput();

    QStringList stroka=vihlop.split("time=");
    QString str=stroka.at(1);
    ui->statusBar->showMessage(vihlop);
     QStringList strList=str.split(".");
     //ui->statusBar->showMessage(strList.at(0));
     QString strPing=strList.at(0);

     bool ok;
     int PingInt=strPing.toInt(&ok,10);
     ui->lcdNumber->display(PingInt);
     ui->progressBar->setValue(1000-PingInt);

}
void MainWindow::PingErr()
{
    QString vihlop=ping->readAllStandardError();
    ui->statusBar->showMessage(vihlop);
}
void MainWindow::on_pushButton_2_clicked()
{
    ping->start("ping",QStringList()<<ui->lineEdit->text());
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    ping->close();
    ui->pushButton_2->setDisabled(false);
    ui->pushButton_3->setDisabled(true);
}
