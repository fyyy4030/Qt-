#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QBitmap> //使用mask函数要加
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap *pixmap =new QPixmap;
    pixmap->load(":/flower.png");

    ui->label->resize(pixmap->size());//设置大小
    this->resize(pixmap->size());//设置大小

    this->setMask(pixmap->mask());//设置遮罩,遮罩的图片背景必须要透明的
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/flower.png"));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    close();
}

