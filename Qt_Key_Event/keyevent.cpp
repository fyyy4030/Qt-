#include "keyevent.h"
#include "ui_keyevent.h"
#include <QPainter>
#include <QPen>
#include <QKeyEvent>

KeyEvent::KeyEvent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KeyEvent)
{
    ui->setupUi(this);
    setWindowTitle("键盘事件");
    setAutoFillBackground(true);//背景填充自动
    setFixedSize(800,800);
    m_width=size().width();
    m_height=size().height();

    m_pix=new QPixmap(m_width,m_height);
    m_pix->fill(Qt::white);//填充白色

    m_image.load("tai.png");
    m_startX=100;
    m_startY=100;
    m_step=20;
    drawPix();
}

KeyEvent::~KeyEvent()
{
    delete ui;
}

void KeyEvent::drawPix()
{
    m_pix->fill(Qt::white);

    QPainter painter(this);//画家
    QPen pen(Qt::DotLine);//笔,虚线的笔

    painter.begin(m_pix);//指定m_pix为绘图设备
    painter.setPen(pen);

    //按照步长画纵向网格线
    for(int i =m_step;i<m_width;i+=m_step){
      painter.drawLine(QPoint(i,0),QPoint(i,m_height));
    }

    //按照步长画横向网格线
    for(int i =m_step;i<m_height;i+=m_step){
      painter.drawLine(QPoint(0,i),QPoint(m_width,i));
    }
    painter.end();

    //画图片
    painter.begin(m_pix);
    painter.drawImage(QPoint(m_startX,m_startY),m_image);
    painter.end();
}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    //用户按下修饰键 == CTRL键
    if(event->modifiers()==Qt::ControlModifier){
        //用户按下键 == 键盘左,右,上,下键值
        if(event->key()==Qt::Key_Left)//m_startX=(m_startX-1)<0 ?m_startX:m_startX-1;
            m_startX-=m_startX<=0 ? 0:1;
        if(event->key()==Qt::Key_Right)
            m_startX+=m_startX+m_image.width()>=m_width ? 0:1;
        if(event->key()==Qt::Key_Up)
            m_startY-=m_startY<=0 ? 0:1;
        if(event->key()==Qt::Key_Down)
            m_startY+=m_startY+m_image.height()>=m_height ? 0:1;
    }else{//没有按CTRL键,每次移动为一个步长
        //调整图标左上角位置到网格顶点上
        m_startX-=m_startX % m_step;
        m_startY-=m_startY % m_step;

        if(event->key()==Qt::Key_Left)
            m_startX-=m_startX<=0 ? 0:m_step;
        if(event->key()==Qt::Key_Right)
            m_startX+=m_startX+m_image.width()>=m_width ? 0:m_step;
        if(event->key()==Qt::Key_Up)
            m_startY-=m_startY<=0 ? 0:m_step;
        if(event->key()==Qt::Key_Down)
            m_startY+=m_startY+m_image.height()>=m_height ? 0:m_step;
    }

    drawPix();//根据调整后的图标位置重新在m_pix上绘制图像
    update();//触发窗口重绘
}

void KeyEvent::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*m_pix);
    painter.end();
}

