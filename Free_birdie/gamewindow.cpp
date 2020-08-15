#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QFile>
#include <QGraphicsView> //游戏视图
#include <QSequentialAnimationGroup> //动画组
#include <QPropertyAnimation> //属性动画
#include <QStyleOption> //风格选择
#include <QDebug>
#include "buttonitem.h"
#include "roaditem.h"
#include "pipeitem.h"
#include <QKeyEvent>

typedef struct{
    char const *pix;
    qreal initX,initY;//开始位置
    qreal destX,destY;//结束位置
}sss;

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    m_startGame=false;

    initControl();//初始化控件
    this->setWindowTitle("飞翔的小鸟");
    initBackgroundMusic();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::initControl()
{
    loadStyleSheet("GameWindow");//加载样式

    const QRectF gameRect=rect();//当前的矩形
    m_scene=new GameScene(this,gameRect);//初始化游戏场景
    //初始化游戏视图(将游戏场景添加到视图)
    QGraphicsView* view =new QGraphicsView(m_scene,this);
    view->setScene(m_scene);//设置游戏场景
    //将视图去掉边框,设为透明
    view->setStyleSheet("border:none;background:transparent;");//视图无边框,透明的设置
    //设置缓存为背景模式,    背景没有发生变化不进行更新,可以提升效率
    view->setCacheMode(QGraphicsView::CacheBackground);

    startWelcome();

}

void GameWindow::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/BirdGame/Resources/qss/"+sheetName+".css");
    if(file.open(QFile::ReadOnly))
    {
        QString strStyleSheet=this->styleSheet();//获取当前的样式
        strStyleSheet += file.readAll();
        this->setStyleSheet(strStyleSheet);//设置样式
        file.close();
    }
}

void GameWindow::startWelcome()
{
    //道路
    RoadItem* roadItem = new RoadItem(m_scene);

    //管道
    PipeItem* pipeItem = new PipeItem(m_scene);

    //鸟儿
    m_birdItem=new BirdItem(m_scene);

    //游戏状态检测
    m_checkGameStartusTimer=new QTimer(this);
    connect(m_checkGameStartusTimer,SIGNAL(timeout()),this,SLOT(onCheckGameStartus()));//定时检测游戏状态

    //欢迎字 "飞吧,像飞一样自由,无法挽留..."
    const int nLetters = 15 ;
    //为让字一个个跳出来的动画
    sss letterData[nLetters]={
        {"飞",-1000,-1000,250,100}, //第一行
        {"吧",-800,-1000,300,100},
        {",",-600,-1000,350,100},

        {"像",-400,-1000,150,160},//第二行
        {"风",1000,2000,200,160},
        {"一",800,2000,250,160},
        {"样",600,2000,300,160},
        {"自",400,2000,350,160},
        {"由",200,2000,400,160},
        {",",0,2000,150,450},

        {"无",0,2000,175,220},//第三行
        {"法",0,2000,225,220},
        {"挽",0,2000,275,220},
        {"留",0,2000,325,220},
        {"...",0,2000,375,220}
    };

    //连续动画组
    QSequentialAnimationGroup* letterGroupMovie=new QSequentialAnimationGroup(this);

    //并行动画组
    m_lettersGroupFading = new QParallelAnimationGroup(this);

    for(int i=0;i<nLetters;i++)
    {
        //文本图形项
        //设置字体
        //字体,字体大小,字重600,字的颜色
        QString htmlText=QString("<span style=\"font-family:'Berlin Sans FB';font-size:38px;font-weigth:600;color:#194819;\">%1</span>").arg(letterData[i].pix);
        QGraphicsTextItem *letter = new QGraphicsTextItem();

        letter->setHtml(htmlText);
        letter->setPos(letterData[i].initX,letterData[i].initY);//设置位置
        //属性动画
        QPropertyAnimation *moveAnimation=new QPropertyAnimation(letter,"pos",letterGroupMovie);
        moveAnimation->setEndValue(QPointF(letterData[i].destX,letterData[i].destY));//设置结束值
        moveAnimation->setDuration(200);//动画时长
        moveAnimation->setEasingCurve(QEasingCurve::OutElastic);//动画曲线效果
        letterGroupMovie->addPause(50);//暂停

        //渐渐消失属性动画
        QPropertyAnimation* fadeAnimation = new QPropertyAnimation(letter,"opacity",m_lettersGroupFading);
        fadeAnimation->setDuration(600);//消失动画的时长
        fadeAnimation->setEndValue(0);
        fadeAnimation->setEasingCurve(QEasingCurve::OutQuad);

        m_scene->addItem(letter);//往游戏场景中添加字符图形项
    }
    //启动字符动画
    letterGroupMovie->start(QAbstractAnimation::DeleteWhenStopped);//动画停止后删除

    //[开始]按钮图形项
    QPixmap pix=QPixmap(":/BirdGame/Resources/image/startButton.png");
    ButtonItem* btnItem=new ButtonItem(pix,m_scene);
    btnItem->setPos(QPoint(245,340));

    //[开始]按钮按下,按钮渐渐消失动画
    QPropertyAnimation* fadeAnimation1=new QPropertyAnimation(btnItem,"opacity",m_lettersGroupFading);
    fadeAnimation1->setDuration(600);//动画时长
    fadeAnimation1->setEndValue(0);//结束值,透明度,opacity为0就全透明,1为完全不透明
    fadeAnimation1->setEasingCurve(QEasingCurve::OutInQuint);//设置曲线

    //[开始]按钮被点击,游戏开始
    connect(btnItem,SIGNAL(clicked()),this,SLOT(onStartBtnClicked()));
    connect(fadeAnimation1,&QPropertyAnimation::finished,this,[this](){
        m_startGame=true;//游戏开始
        m_checkGameStartusTimer->start(50);//启动
        m_birdItem->flyLandfallAnmation();//鸟儿往下掉

        //游戏开玩的音效
        m_welcomePlayer->stop();//停止播放器
        m_welcomePlayerList->clear();//清空播放列表
        m_welcomePlayerList->addMedia(QUrl("qrc:/BirdGame/Resources/sound/background.mp3"));
        m_welcomePlayer->setVolume(100);
        m_welcomePlayer->play();
    });

}

void GameWindow::GameOver()
{
    //'墙都不扶,就扶你!'
    const int nLetters = 9 ;
    //为让字一个个跳出来的动画
    sss letterData[nLetters]={
        {"墙",-1000,-1000,200,160}, //第一行
        {"都",-800,-1000,250,160},
        {"不",-600,-1000,300,160},
        {"扶",-400,-1000,350,160},
        {",",1000,2000,400,160},

        {"就",800,2000,220,220},
        {"扶",600,2000,270,220},
        {"你",400,2000,320,220},
        {"!",200,2000,370,220},
    };

    //连续动画组
    QSequentialAnimationGroup* letterGroupMovie=new QSequentialAnimationGroup(this);

    for(int i=0;i<nLetters;i++)
    {
        //文本图形项
        QGraphicsTextItem *letter = new QGraphicsTextItem();

        //设置字体
        //字体,字体大小,字重600,字的颜色
        QString htmlText=QString("<span style=\"font-family:'Berlin Sans FB';font-size:38px;\
                                    font-weigth:600;color:#194819;\">%1</span>").arg(letterData[i].pix);

        letter->setHtml(htmlText);
        letter->setPos(letterData[i].initX,letterData[i].initY);//设置位置
        //属性动画
        QPropertyAnimation *moveAnimation=new QPropertyAnimation(letter,"pos",letterGroupMovie);
        moveAnimation->setEndValue(QPointF(letterData[i].destX,letterData[i].destY));//设置结束值
        moveAnimation->setDuration(200);//动画时长
        moveAnimation->setEasingCurve(QEasingCurve::OutElastic);//动画曲线效果
        //letterGroupMovie->addPause(50);//暂停

//        //渐渐消失属性动画
//        QPropertyAnimation* fadeAnimation = new QPropertyAnimation(letter,"opacity",m_lettersGroupFading);
//        fadeAnimation->setDuration(600);//消失动画的时长
//        fadeAnimation->setEndValue(0);
//        fadeAnimation->setEasingCurve(QEasingCurve::OutQuad);

        m_scene->addItem(letter);//往游戏场景中添加字符图形项
    }
    //启动字符动画 //停止,资源自动回收
    letterGroupMovie->start(QAbstractAnimation::DeleteWhenStopped);//动画停止后删除
    //将小鸟图形项移除
    m_scene->removeItem(m_birdItem);
    //游戏结束的音效
    m_welcomePlayer->stop();//停止播放器
    m_welcomePlayerList->clear();//清空播放列表
    m_welcomePlayer->setMedia(QUrl("qrc:/BirdGame/Resources/sound/gameover.wav"));
    m_welcomePlayer->setVolume(100);
    m_welcomePlayer->play();
}

void GameWindow::initBackgroundMusic()
{
    m_welcomePlayer=new QMediaPlayer(this);//播放器

//    //播放一次
//    m_welcomePlayer->setMedia(QUrl("qrc:/BirdGame/Resources/sound/freelikewind.mp3"));//设置媒体
//    m_welcomePlayer->setVolume(100);//设置音量
//    m_welcomePlayer->play();//播放

    //播放多次
    m_welcomePlayerList = new QMediaPlaylist(this);
    m_welcomePlayerList->addMedia(QUrl("qrc:/BirdGame/Resources/sound/freelikewind.mp3"));//添加媒体
    //...添加其它的播放音乐...
    //m_welcomePlayerList->addMedia(QUrl("qrc:/BirdGame/Resources/sound/welcome.mp3"));
    //循环播放当前列表曲目
    m_welcomePlayerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    m_welcomePlayer->setPlaylist(m_welcomePlayerList);//播放器 设置 播放列表
    m_welcomePlayer->play();//播放
}

void GameWindow::paintEvent(QPaintEvent *event)
{
    //风格选择
    QStyleOption opt;
    opt.init(this);//初始化
    QPainter p(this);//画
    //保留原风格
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}//这里去掉也没事

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(m_startGame) m_birdItem->keyPressEvent(event);
}

void GameWindow::onStartBtnClicked()
{
    //启动消失动画,结束后删除动画
    m_lettersGroupFading->start(QAbstractAnimation::DeleteWhenStopped);
}

void GameWindow::onCheckGameStartus()
{
    if(m_birdItem->checkIsCollided())//鸟儿与其它场景发生碰撞
    {
        GameOver();
    }
}

