#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "property.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Property *mypc=new Property;
    connect(mypc,SIGNAL(maskChanged(QString)),this,SLOT(maskChanged(QString)));
    mypc->setMask("100000亿个口罩");//属性虽然注册到了元对象系统,但只针对当前实例
    qDebug()<<"当前口罩属性:"<<mypc->mask();

    QObject *obj=mypc;

    qDebug()<<"QObject进行属性读取:"<<obj->property("mask").toString();

    obj->setProperty("mask","20005口罩");
    qDebug()<<"QObject进行第二次属性读取:"<<obj->property("mask").toString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::maskChanged(QString mask)
{
    qDebug()<<"新的口罩库存: "<<mask;
}
