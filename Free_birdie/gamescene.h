#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene> //场景类

//游戏场景
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    //(父类指针,场景大小)
    GameScene(QObject* parent,const QRectF& sceneRect);
    ~GameScene();
};

#endif // GAMESCENE_H

//设定游戏场景进行地方,游戏场景大小
