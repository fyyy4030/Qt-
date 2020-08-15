#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QGraphicsObject> //图形对象


class QPropertyAnimation;//属性动画,用于小鸟飞行的实现

//自定义图形项,需重写paint,boundingRect
//小鸟图形对象(图形项)
class BirdItem : public QGraphicsObject
{
    Q_OBJECT
public:
    BirdItem(QGraphicsScene* scene);
    ~BirdItem();
public:
    QRectF boundingRect()const;//重写绘图区域
    void flyRaiseAnimation();//上升动画
    void flyLandfallAnmation();//下降动画
    bool checkIsCollided();//碰撞检测

private slots:
    void onRefreshBird();//定时刷新小鸟
    void onFlyRaiseAnimationFinished();//上升动画结束
private:
    void paint(QPainter* ,const QStyleOptionGraphicsItem* ,QWidget* );//重写绘图事件
public:
    void keyPressEvent(QKeyEvent* event);//重写键盘事件,空格键控制小鸟
private:
    bool m_IsLandFall;//下降标志
    bool m_IsRaise;//上升标志
    int m_curflyStatus;//当前飞行状态,上中下三种,/3
    QGraphicsScene* m_scene;//所在场景
    QTimer* m_birdRefreshTimer;//刷新小鸟的计时器
    QPropertyAnimation* m_flyAnimation;//飞行动画
};

#endif // BIRDITEM_H

//实现了'鸟儿'在'游戏场景中'上升下降&其中运行的动画效果&'鸟儿'翅膀扑通的动画效果&碰撞'游戏场景中'其它图形项的检测&空格控制'鸟儿'上升
//碰撞检测只需放在主角上就行了,还有就是碰到奖励的怎么办?,这可通过与其碰撞后所返回的形状界定
