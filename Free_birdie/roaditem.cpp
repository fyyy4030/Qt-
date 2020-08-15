#include "roaditem.h"
#include <QPainter>
#include <QPropertyAnimation>

#define ROAD_ITEM_HEIGHT 38

RoadItem::RoadItem(QGraphicsScene *scene):m_scene(scene)
{
    m_scene->addItem(this);//将当前道路图形项添加到游戏场景
    startMove();//道路开始移动
}

RoadItem::~RoadItem()
{

}

QRectF RoadItem::boundingRect() const
{
    //584*448,游戏场景;384*64,道路
    return QRectF(0,m_scene->height()-ROAD_ITEM_HEIGHT,m_scene->width()*2,ROAD_ITEM_HEIGHT);
}

void RoadItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //画两条马路
    //前段
    painter->drawImage(QRectF(0,m_scene->height()-ROAD_ITEM_HEIGHT,m_scene->width(),ROAD_ITEM_HEIGHT)
                       ,QImage(":/BirdGame/Resources/image/road.png"));
    //后段
    painter->drawImage(QRectF(m_scene->width(),m_scene->height()-ROAD_ITEM_HEIGHT,m_scene->width(),ROAD_ITEM_HEIGHT)
                       ,QImage(":/BirdGame/Resources/image/road.png"));

}

void RoadItem::startMove()
{
    //位置属性动画
    QPropertyAnimation *moveAnimation = new QPropertyAnimation(this,"pos");
    //设置动画的循环次数,0不启动,-1则一直循环
    moveAnimation->setLoopCount(-1);
    moveAnimation->setDuration(4000);//动画时长
    moveAnimation->setStartValue(QPoint(0,pos().y()));//设置动画启动值(动画运动位置)
    //设置动画结束值,往前(左)移出了整个场景
    moveAnimation->setEndValue(QPoint(0-m_scene->width(),pos().y()));
    moveAnimation->setEasingCurve(QEasingCurve::Linear);//线性曲线
    moveAnimation->start();
}
