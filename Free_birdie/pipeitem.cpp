#include "pipeitem.h"
#include  <QPainter>
#include <QPropertyAnimation>
#include "QPainterPath"

#define PIPE_WIDTH_ 64

PipeItem::PipeItem(QGraphicsScene* scene)
{
    m_scene=scene;
    scene->addItem(this);//游戏场景添加管道图形项
    createPipeHeight();//创建管道高度
    startMove();//管道开始移动

}

PipeItem::~PipeItem()
{

}

QRectF PipeItem::boundingRect() const
{
    //高度是因管道上下动,所以绘图区域限度整个游戏场景高
    return QRectF(m_scene->width(),0,PIPE_WIDTH_,m_scene->height());
}

void PipeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //绘制上管道
    painter->drawImage(QRectF(m_scene->width(),0,PIPE_WIDTH_,m_upPipeHeight)
                       ,QImage(":/BirdGame/Resources/image/tubeup.png"));
    //绘制下管道
    painter->drawImage(QRectF(m_scene->width(),m_upPipeHeight + 140,PIPE_WIDTH_,m_downPipeHeight)
                       ,QImage(":/BirdGame/Resources/image/tubedown.png"));
}

QPainterPath PipeItem::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(m_scene->width(),0,PIPE_WIDTH_,m_upPipeHeight));
    path.addRect(QRectF(m_scene->width(),m_upPipeHeight+140,PIPE_WIDTH_,m_downPipeHeight));
    return path;
}

void PipeItem::startMove()
{
    //移动动画(位置属性动画)
    QPropertyAnimation*  moveAnimation=new QPropertyAnimation(this,"pos");
    moveAnimation->setLoopCount(-1);//一直循环
    moveAnimation->setDuration(3000);//动画时长
    moveAnimation->setStartValue(QPoint(0,pos().y()));//起始值
    moveAnimation->setEndValue(QPoint(0-m_scene->width() - PIPE_WIDTH_,pos().y()));//结束值
    moveAnimation->start();//启动动画

    //动画循环次数改变时则创建管道
    connect(moveAnimation,&QPropertyAnimation::currentLoopChanged,[this](){createPipeHeight();});
}

void PipeItem::createPipeHeight()
{
     //随机数据0-100
     m_upPipeHeight =  qrand() % 100+80;//上管道的高度
     m_downPipeHeight = m_scene->height() - m_upPipeHeight - 178;//下管道的高度
}
