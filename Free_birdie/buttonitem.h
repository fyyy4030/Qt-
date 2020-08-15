#ifndef BUTTONITEM_H
#define BUTTONITEM_H

#include <QGraphicsObject>

//游戏开始按钮
class ButtonItem : public QGraphicsObject
{
    Q_OBJECT
public:
    ButtonItem(QPixmap& pix,QGraphicsScene* scene);
    ~ButtonItem();
signals:
    void clicked();//点击信号
protected:
    //重写图形项的绘图区域
    QRectF boundingRect()const;
private:
    //重写绘图事件
    void paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*);
    //重写鼠标按下事件
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
    QPixmap m_pix;//按钮的图片
};

#endif // BUTTONITEM_H


