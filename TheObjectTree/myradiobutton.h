#ifndef MYRADIOBUTTON_H
#define MYRADIOBUTTON_H
#include <QRadioButton>
//单选按钮
class MyRadioButton : public QRadioButton
{
public:
    MyRadioButton(QWidget *parent=0);
    ~MyRadioButton();
};

#endif // MYRADIOBUTTON_H
