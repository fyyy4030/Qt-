#include "mylabel.h"
#include <QLabel>
#include <QDebug>

MyLabel::MyLabel(QWidget* parent):QLabel(parent)
{
    qDebug()<<"MyLabel构造"<<this;
}

MyLabel::~MyLabel()
{
     qDebug()<<"MyLabel析构"<<this;
}
