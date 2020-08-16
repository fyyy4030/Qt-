#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"Widget构造"<<this;
}

Widget::~Widget()
{

    delete ui;
    qDebug()<<"Widget析构"<<this;
}
