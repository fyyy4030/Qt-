#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent):QPushButton(parent)
{
    qDebug()<<"MyPushButton构造";
}

MyPushButton::~MyPushButton()
{
    qDebug()<<"MyPushButton析构";
}
