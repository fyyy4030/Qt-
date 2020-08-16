#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsOpacityEffect>
#include <QGraphicsDropShadowEffect>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    while(0){//设置样式表
    //ui->pushButton->setStyleSheet("background:yellow");//设置背景色:黄色
    //ui->pushButton->setStyleSheet("color:red");//设置前景色:红色
    //ui->pushButton->setStyleSheet("background:yellow;color:red");//样式分开设置会造成覆盖

    //窗体设置样式表(按钮{属性:值})
    //setStyleSheet("QPushButton{background:yellow;color:red}");

    //ui->horizontalSlider->setStyleSheet("background:blue");
        break;
    }

    while(1){//部件透明及阴影效果
        //窗口透明属性
        //setWindowOpacity(0.5);//此界面中的全部件

        //窗体背景透明,部件不透明,windows下需配合无边框风格
        //设置窗体风格
        setWindowFlags(Qt::FramelessWindowHint);//无边框风格
        setAttribute(Qt::WA_TranslucentBackground);

        //部件设置透明
//        QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
//        opacityEffect->setOpacity(0.1);
//        ui->label->setGraphicsEffect(opacityEffect);

        //阴影效果
//        QGraphicsDropShadowEffect *ShadowEffect=new QGraphicsDropShadowEffect;
//        //阴影色,透明度设置
//        ShadowEffect->setColor(QColor(100,100,100));
//        ShadowEffect->setBlurRadius(20);//阴影模糊半径
//        ShadowEffect->setOffset(20);//阴影偏移值
//        ui->label->setGraphicsEffect(ShadowEffect);//调用此函数后会覆盖上次设置的操作,所以上面的透明度失效

        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//重写绘图事件
void MainWindow::paintEvet(QPaintEvent *event)
{
    QPainter painter(this);//此透明度设置在0~255
    painter.fillRect(rect(),QColor(255,255,255,100));//透明度100
}

