#include "digital_clock.h"
#include <QTimer> //定时器
#include <QTime>  //时间
#include <QMouseEvent>


Digital_Clock::Digital_Clock(QWidget *parent):QLCDNumber(parent)
{
    //设置蓝色背景:
    QPalette p=palette();//获取当前调色板
    p.setColor(QPalette::Window,Qt::blue);//设置颜色(窗体,色值)
    setPalette(p);

    //设置窗体风格
    setWindowFlag(Qt::FramelessWindowHint);//无边框窗体风格
    //设置窗体透明度
    setWindowOpacity(0.8);

    QTimer *timer=new QTimer(this);//定时器
    //每隔一秒就发射信号,timeout:时间到
    connect(timer,&QTimer::timeout,this,&Digital_Clock::showTime);
    timer->start(1000);//周期1000毫秒 启动

    showTime();//显示时间
    resize(150,60);//钟表像素大小
    m_showColon =true;
}

void Digital_Clock::mousePressEvent(QMouseEvent *event) //鼠标按下事件
{
    if(event->button() == Qt::LeftButton){//判断按的是否左键
        //鼠标点相对时钟窗体左上角的偏移值=鼠标总体位置-框架几何.顶端左
        m_dragPosition = event->globalPos()-frameGeometry().topLeft();//鼠标相对屏幕左上角位置-时钟窗体左上角位置
        event->accept();//接受事件
    }

    if(event->button() == Qt::RightButton){
        close();
    }
}

void Digital_Clock::mouseMoveEvent(QMouseEvent *event) //鼠标移动事件
{
    if(event->buttons() & Qt::LeftButton){//鼠标按钮 同时 是左键
        //注! event->button返回的是鼠标键位 ,event->buttons()返回的是鼠标按钮
        move(event->globalPos() - m_dragPosition);//移动(当前鼠标位置-之前的位置)
        event->accept();
    }
}

void Digital_Clock::showTime()//显示时间
{
    QTime time = QTime::currentTime();//获取当前时间
    QString strtime=time.toString("hh:mm");//将时间转换字符串

    if(m_showColon){//判断是否显示':'
        strtime[2]=':';
    }else{
        strtime[2]=' ';
    }

    display(strtime);//显示 //将字符串显示出来
    m_showColon = !m_showColon;//取反 造成 ':' 闪烁的效果
}
