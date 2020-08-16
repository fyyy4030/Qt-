#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QWidget>
//按钮,单按钮
class MyPushButton : public QPushButton
{
public:
    MyPushButton(QWidget *parent=0);
    ~MyPushButton();
};

#endif // MYPUSHBUTTON_H
