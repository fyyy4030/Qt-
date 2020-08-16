#include "widget.h"
#include <QApplication>
#include "mylabel.h"
#include "mylayout.h"
#include "mypushbutton.h"
#include "myradiobutton.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;


    MyLabel *mylabel=new MyLabel(&w);
    MyPushButton *mybtn=new MyPushButton(&w);
    MyRadioButton *myradiobutton=new MyRadioButton(&w);
    MyLayout *mylayout=new MyLayout(&w);

    MyLayout *sunlayout=new MyLayout(mylabel);
    MyPushButton *mybtn1=new MyPushButton;//自动以layout为副窗体
    MyPushButton *mybtn2=new MyPushButton;
    MyPushButton *mybtn3=new MyPushButton;

    //孙类布局
    mybtn1->setText("孙按钮1");
    mybtn2->setText("孙按钮2");
    mybtn3->setText("孙按钮3");
    sunlayout->addWidget(mybtn1);
    sunlayout->addWidget(mybtn2);
    sunlayout->addWidget(mybtn3);
    //成一颗倒立树,mylabel为根(mylabel的子类为树枝,树叶[孙按钮那些]),销毁mylabel,孙按钮那些也会随之而去
    mylabel->setLayout(sunlayout);//上面那些123按钮会重新以mylabel为自己的副窗体

    mylabel->setText("子标签");
    mybtn->setText("子按钮");
    myradiobutton->setText("子单选");

    //布局
    mylayout->addWidget(mylabel,0,0);
    mylayout->addWidget(mybtn,1,0);
    mylayout->addWidget(myradiobutton,2,0);


    //设置布局
    w.setLayout(mylayout);

    w.show();
    //父类是QObject的,不用销毁,有机制回收

    const QObjectList list=w.children();
    const QObjectList list1=mylabel->children();

    qDebug()<<"mylabel->children";
    foreach(QObject* obj,list1)
        qDebug()<<obj;
    //对象树是一课倒立的树,QObject为根
    mylabel->deleteLater();//销毁树

    qDebug()<<"w.children";
    //这是一个循环(接收器,被循环容器)
   foreach(QObject* obj,list)
       qDebug()<<obj;

    return a.exec();
}
