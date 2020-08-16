#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //信号与槽连接
    //信号发送者,发送什么信号呢,谁接收,响应的槽方法,连接的类型(默认自动连接)
    connect(this,SIGNAL(Comeon(QString&)),this,SLOT(ComenGuys(QString&)));//自动响应了对应的
   // connect(this,&MainWindow::Comeon,this,&MainWindow::ComenGuys);//和上面的是一样的
    connect(this,SIGNAL(Comeon(QString&)),this,SLOT(ComenGuy()));//一对多响应
    connect(this,SIGNAL(Comeon(QString&)),this,SLOT(ComenG()));//可以信号连接信号
    //单信号连接多信号,单信号连接单槽;多信号连接单槽,多槽连接单信号;都是可以的
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zhbtn_clicked()
{
    QString strr="珠海加油";
    emit Comeon(strr);//发送信号
}

void MainWindow::on_szbtn_clicked()
{
    QString str="深圳加油";
    emit Comeon(str);//发送信号
}

void MainWindow::on_gzbtn_clicked()
{
    QString str="广州加油";
    emit Comeon(str);//发送信号
}

void MainWindow::ComenGuys(QString& str)
{
    qDebug()<<str;
    //打印调试信息
}

void MainWindow::ComenGuy()
{
    QString str="大广州加油";
    qDebug()<<str;
}

void MainWindow::ComenG()
{
    qDebug()<<"还幻化哈";
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"断开单信号和单槽连接";
    disconnect(this,SIGNAL(Comeon(QString&)),this,SLOT(ComenGuys(QString&)));
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"断开单信号和多槽连接";
    disconnect(this,SIGNAL(Comeon(QString&)),0,0);//0,响应的对象and槽
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug()<<"断开this所有信号与this所有槽的连接";
  //  disconnect(this,0,this,0);//断开目标对象
    disconnect(this,0,0,0);//断开所有this相关对象的槽响应
}
