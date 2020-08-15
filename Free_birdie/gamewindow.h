#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "gamescene.h"
#include "birditem.h"
#include  <QParallelAnimationGroup>
#include <QTimer>
#include <QMediaPlayer> //媒体播放器
#include <QMediaPlaylist> //媒体播放列表

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    void initControl();//初始化控件
    void loadStyleSheet(const QString& sheetName);//加载样式
    void startWelcome();//启动欢迎
    void GameOver();//游戏结束
    void initBackgroundMusic();//初始化背景音乐
protected:
    void paintEvent(QPaintEvent *event) override;//重写绘图事件
    void keyPressEvent(QKeyEvent* event);//重写键盘事件
private slots:
    void onStartBtnClicked();
    void onCheckGameStartus();//检测游戏状态
private:
    Ui::GameWindow *ui;
    GameScene* m_scene;//游戏场景
    BirdItem* m_birdItem;//主角,小鸟对象
    bool m_startGame;//游戏开始标志
    QParallelAnimationGroup* m_lettersGroupFading;//渐渐消失动画组
    QTimer *m_checkGameStartusTimer;//检测游戏状态
    QMediaPlayer* m_welcomePlayer;//欢迎的音乐  //播放器
    QMediaPlaylist* m_welcomePlayerList;//播放列表
};
#endif // GAMEWINDOW_H

//所有游戏图形项必须重写绘图区域和绘图事件:
//    //重写绘图区域
//    QRectF boundingRect()const;
//    //重写绘图事件
//    void paint(QPainter* painter,const QStyleOptionGraphicsItem*,QWidget*);
