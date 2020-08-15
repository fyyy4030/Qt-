#ifndef PIPEITEM_H
#define PIPEITEM_H

#include <QGraphicsObject>
#include <QGraphicsScene>

//管道图形项
class PipeItem : public QGraphicsObject
{
    Q_OBJECT
public:
    PipeItem(QGraphicsScene* scene);
    ~PipeItem();
protected:
    //重写绘图区域
    QRectF boundingRect()const;
    //重写绘图事件
    void paint(QPainter* painter,const QStyleOptionGraphicsItem*,QWidget*);
    //返回形状
    QPainterPath shape()const;//重写返回图形项形状,可用与图形碰撞检测等多用途,F1
private:
    void startMove();//管道移动
    void createPipeHeight();//创建管道的高度
private:
    QGraphicsScene* m_scene;
    int m_upPipeHeight;//上管道高度
    int m_downPipeHeight;//下管道高度
};

#endif // PIPEITEM_H
