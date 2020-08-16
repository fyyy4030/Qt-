#include "widget.h"
#include "ui_widget.h"

extern int gPies;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//启动
void Widget::on_pushButton_clicked()
{
    gPies=0;
    m_MyThread1.start();
    m_MyThread2.start();
    m_MyThread3.start();
}

//停止
void Widget::on_pushButton_2_clicked()
{
    m_MyThread1.stop();
    m_MyThread2.stop();
    m_MyThread3.stop();
}
