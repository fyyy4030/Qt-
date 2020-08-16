#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton> //工具按键
#include <QSpinBox> //旋转箱
#include <QLabel> //标签

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    while(1){//菜单项的添加
        //菜单 //添加菜单项->
        QMenu *editMenu = ui->menuBar->addMenu("编辑(&E)");//可以指定图标的

        //添加下拉菜单
        QAction *action_copy = editMenu->addAction(QIcon("copy.png"),QString("复制(&C)"));
        action_copy->setShortcut(QKeySequence("CTRL + C"));//设置快捷键

        //主要的工具->添加功能(动作)
        ui->mainToolBar->addAction(action_copy);//工具栏中添加功能

        //添加动作分组 //分组里多功能,但应用的只能一个
        QActionGroup *group = new QActionGroup(this);//动作组
        QAction *action_L = group->addAction("左对齐(&L)");//将功能添加到动作组
        QAction *action_R = group->addAction("右对齐(&R)");
        QAction *action_C = group->addAction("居中对齐(&C)");
        QAction *action_J = group->addAction("两端对齐(&J)");

        //设置可选
        action_L->setCheckable(true);
        action_R->setCheckable(true);
        action_C->setCheckable(true);
        action_J->setCheckable(true);

        //添加到编辑菜单项中
        editMenu->addSeparator();//菜单栏中添加分割线
        editMenu->addAction(action_L);
        editMenu->addAction(action_R);
        editMenu->addAction(action_C);
        editMenu->addAction(action_J);
        break;
    }

    while(1){//工具按钮设置菜单
        QToolButton *toolbtn = new  QToolButton(this);//工具栏按钮 //0
        toolbtn->setText("颜色");//设置文本 //0

        QMenu *colorMenu =new QMenu(this);//菜单项 //1
        colorMenu->addAction("红色");//下拉动作 //1
        colorMenu->addAction("绿色");//下拉动作 //1
        toolbtn->setMenu(colorMenu);//设置菜单 //工具栏按钮增添了菜单项 //1
        //设置为弹出式菜单 //拥有下拉项 //1
        toolbtn->setPopupMode(QToolButton::MenuButtonPopup);//设置弹出模式(菜单按钮的弹出) //1

        //添加部件
        ui->mainToolBar->addWidget(toolbtn);//将工具栏按钮部件添加到工具栏项中 //0
        break;
    }

    while(1){//状态栏操作
        QSpinBox *spinBox = new QSpinBox(this);
        ui->mainToolBar->addWidget(spinBox);//添加旋转箱到工具栏

        //状态栏显示信息操作
        ui->statusBar->showMessage(QString("欢迎..."),3000);//显示信息

        QLabel *tag = new QLabel("www.www.com");//标签
        ui->statusBar->addPermanentWidget(tag);//界面->状态栏->添加永久性部件
        break;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


