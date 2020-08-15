#include "birditem.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QPropertyAnimation>
#include <QRectF>
#include <QPainter>
#include <QKeyEvent>

#define FLY_BIRD_SIZE 45

BirdItem::BirdItem(QGraphicsScene* scene)
{
    m_curflyStatus=0;
    m_IsRaise=true;
    m_IsLandFall=true;
    scene->addItem(this);//将当前的小鸟对象添加到游戏场景中
    m_scene=scene;

    //定时刷新小鸟
    m_birdRefreshTimer = new QTimer(this);//初始化计时器
    connect(m_birdRefreshTimer,SIGNAL(timeout()),this,SLOT(onRefreshBird()));
    m_birdRefreshTimer->start(10);//每间隔10毫秒

    //小鸟位置属性动画,通过设置小鸟的位置,不同位置属性值达到动画效果
    m_flyAnimation = new QPropertyAnimation(this,"pos");
    connect(m_flyAnimation,SIGNAL(finished()),this,SLOT(onFlyRaiseAnimationFinished()));

}

BirdItem::~BirdItem()
{

}

QRectF BirdItem::boundingRect() const
{
    //左上角位置,矩形大小
    return QRectF(60,FLY_BIRD_SIZE*5,FLY_BIRD_SIZE,FLY_BIRD_SIZE);
}

void BirdItem::flyRaiseAnimation()
{
    if(m_IsRaise)//小鸟往上升
    {
        m_IsRaise=false;
        m_flyAnimation->stop();

        int nMove=pos().y();//鸟儿移动的y值
        //因为小鸟图形项是以游戏场景的中心位置点显示,scene->addItem(this)此函数
        //中心点就为0,0了,而不是那游戏场景pos().x()/2这样
        if(nMove > -180)
        {
            m_flyAnimation->setDuration(300);//动画时长
            m_flyAnimation->setEndValue(QPoint(pos().x(),pos().y() - FLY_BIRD_SIZE));//动画的结束位置
        }
        else //小鸟飞到顶了
        {
            m_flyAnimation->setDuration(300);//动画时长
            m_flyAnimation->setEndValue(pos());//动画的结束位置
        }

        //动画运行的曲线属性
        //m_flyAnimation->setEasingCurve(QEasingCurve::Linear);//动画曲线效果,直线效果
        m_flyAnimation->setEasingCurve(QEasingCurve::InQuad);
        m_flyAnimation->start();

        //connect(m_flyAnimation,SIGNAL(finished()),this,SLOT(onFlyRaiseAnimationFinished()));
    }
}

void BirdItem::flyLandfallAnmation()
{
    if(m_IsLandFall)
    {
       m_flyAnimation->stop();
       m_flyAnimation->setDuration(1500);
       //m_flyAnimation->setEndValue(QPoint(pos().x(),pos().y()+FLY_BIRD_SIZE));//下降一个小鸟高度
       m_flyAnimation->setEndValue(QPoint(pos().x(),m_scene->height()));
       m_flyAnimation->setEasingCurve(QEasingCurve::InQuad);
       m_flyAnimation->start();
       m_IsLandFall=false;
    }
}

bool BirdItem::checkIsCollided()
{
    //返回与当前游戏项'冲突(碰撞)'的所有项
    if(!collidingItems().isEmpty())
        return true;
    else
        return false;
}

void BirdItem::onRefreshBird()
{
    update();//刷新小鸟
}

void BirdItem::onFlyRaiseAnimationFinished()
{
    m_IsLandFall=true;
    flyLandfallAnmation();//下降
}

void BirdItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(m_curflyStatus <10)//翅膀往上
    {
        m_curflyStatus++;
        painter->drawImage(boundingRect(),QImage(":/BirdGame/Resources/image/bird1.png"));
    }
    else if(m_curflyStatus < 20 )//翅膀居中
    {
        m_curflyStatus++;
        painter->drawImage(boundingRect(),QImage(":/BirdGame/Resources/image/bird2.png"));
    }
    else if(m_curflyStatus < 30)//翅膀往下
    {
        m_curflyStatus++;
        painter->drawImage(boundingRect(),QImage(":/BirdGame/Resources/image/bird3.png"));
    }
    else
    {
        m_curflyStatus=0;
    }
}

void BirdItem::keyPressEvent(QKeyEvent *event)
{
    //如果是空格键
    if(event->key() == Qt::Key_Space)
    {
        m_IsRaise = true;
        flyRaiseAnimation();//小鸟上升
    }
}
