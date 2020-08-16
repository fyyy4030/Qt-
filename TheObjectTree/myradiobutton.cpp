#include "myradiobutton.h"
#include <QDebug>

MyRadioButton::MyRadioButton(QWidget *parent):QRadioButton(parent)
{
    qDebug()<<"MyRadioButton构造";
}

MyRadioButton::~MyRadioButton()
{
    qDebug()<<"MyRadioButton析构";
}
