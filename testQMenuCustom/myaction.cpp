#include "myaction.h"
#include <QSplitter> //分类器
#include <QLabel>

MyAction::MyAction(QObject *parent):QWidgetAction(parent)
{
    lineEdit = new QLineEdit;//行编辑器
    //用户点击回车后就连接sendText()槽
    connect(lineEdit,&QLineEdit::returnPressed,this,&MyAction::sendText);
}

QWidget *MyAction::createWidget(QWidget *parent)
{
    //判断部件有无菜单栏,工具栏,状态栏
    //inherits继承 //判断父部件是否继承自菜单或者工具栏
    if(parent->inherits("QMenu") || parent->inherits("QToolBar")){
        //创建父部件的子部件
        QSplitter *splitter = new QSplitter(parent);//分类器
        QLabel *label =new QLabel("插入文本:");//标签
        splitter->addWidget(label);//将标签添加到分类器
        splitter->addWidget(lineEdit);//将行编辑器添加到分类器
        return splitter;//返回子部件
    }
    return 0;
}

void MyAction::sendText()
{
    emit getText(lineEdit->text());//发射信号 //接收到用户的字符串后在菜单项显示
    lineEdit->clear();//文本编辑器清空
}
