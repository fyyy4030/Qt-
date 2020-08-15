#include "mouseevent.h"
#include "ui_mouseevent.h"
#include <QMouseEvent>

MouseEvent::MouseEvent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MouseEvent)
{
    ui->setupUi(this);
    setWindowTitle("鼠标事件");

    m_statusLabel=new QLabel("当前位置:");
    m_statusLabel->setFixedWidth(100);

    m_posLabel=new QLabel("");
    m_posLabel->setFixedWidth(100);
    ui->statusbar->addPermanentWidget(m_statusLabel);//添加永久部件
    ui->statusbar->addPermanentWidget(m_posLabel);
    //ui->statusbar->addWidget(m_posLabel);//默认三秒就消失
    resize(400,200);
}

MouseEvent::~MouseEvent()
{
    delete ui;
}

void MouseEvent::mousePressEvent(QMouseEvent *event)
{
    QString str="("+QString::number(event->x())+","+QString::number(event->y())+")";
    if(event->button()==Qt::LeftButton)
        statusBar()->showMessage(QString("左键:")+str);
    else if(event->button() == Qt::MidButton)
        statusBar()->showMessage(QString("中键:")+str);
    else if(event->button() == Qt::RightButton)
        statusBar()->showMessage(QString("右键:")+str);
}

void MouseEvent::mouseMoveEvent(QMouseEvent *event)
{
    QString strPos="("+QString::number(event->x())+","+QString::number(event->y())+")";
    m_posLabel->setText(strPos);
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *event)
{
    QString strPos="("+QString::number(event->x())+","+QString::number(event->y())+")";
    statusBar()->showMessage(QString("释放在:")+strPos,3000);
}

