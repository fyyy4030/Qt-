#ifndef MYLAYOUT_H
#define MYLAYOUT_H
#include <QGridLayout>//网格布局

//布局
class MyLayout : public QGridLayout
{
public:
    MyLayout(QWidget *parent=0);
    ~MyLayout();
};

#endif // MYLAYOUT_H
