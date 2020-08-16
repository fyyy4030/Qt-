#include "mylayout.h"
#include <QDebug>

MyLayout::MyLayout(QWidget *parent):QGridLayout(parent)
{
    qDebug()<<"MyLayout构造"<<this;
}

MyLayout::~MyLayout()
{
     qDebug()<<"MyLayout析构"<<this;
}
