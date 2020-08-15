#include "buttonitem.h"
#include <QGraphicsScene>
#include <QCursor> //鼠标
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

ButtonItem::ButtonItem(QPixmap& pix,QGraphicsScene* scene)
{
    m_pix=pix;
    scene->addItem(this);//场景中添加当前按钮图形对象
    setCursor(QCursor(Qt::PointingHandCursor));//设置鼠标指针形状(手指形状)
}

ButtonItem::~ButtonItem()
{

}

QRectF ButtonItem::boundingRect() const
{
    return QRectF(QPoint(0,0),m_pix.size());
}

void ButtonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0,0,m_pix);
}

void ButtonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){//按下左键
        emit clicked();
    }
}
