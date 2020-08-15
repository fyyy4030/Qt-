#include "eventfilter.h"

EventFilter::EventFilter(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("事件过滤");
    m_label1=new QLabel;
    m_label2=new QLabel;
    m_label3=new QLabel;
    m_stateLabel=new QLabel("鼠标按下的标志");

    m_stateLabel->setAlignment(Qt::AlignHCenter);//设置居中

    m_image1.load("i1.jpg");
    m_image2.load("i2.jpg");
    m_image3.load("i3.jpg");

    //m_image2=m_image2.scaled(m_label2->size());//按大小缩放图片

    //按比例缩放图片
    QMatrix m;
    m.scale(0.5,0.5);
    m_image2=m_image2.transformed(m);

    m_label1->setPixmap(QPixmap::fromImage(m_image1));
    m_label2->setPixmap(QPixmap::fromImage(m_image2));
    m_label3->setPixmap(QPixmap::fromImage(m_image3));

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(m_label1);
    layout->addWidget(m_label2);
    layout->addWidget(m_label3);

    QVBoxLayout *mainlayout=new QVBoxLayout(this);
    mainlayout->addLayout(layout);
    mainlayout->addWidget(m_stateLabel);
    resize(500,700);

    //给图片标签安装事件过滤,指定整个窗体为监视事件的对象
    m_label1->installEventFilter(this);
    m_label2->installEventFilter(this);
    m_label3->installEventFilter(this);
}

EventFilter::~EventFilter()
{
}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    QMatrix matrix;
    QMatrix m;
    m.scale(0.3,0.3);
    QImage tmpImg;

    //放大图片
    matrix.scale(2.0,2.0);//比例
    if(watched == m_label1){
        //鼠标按下事件处理 //判断事件类型是否为鼠标按下事件
        if(event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent=(QMouseEvent*)event;//将事件转鼠标事件
            if(mouseEvent->buttons() & Qt::LeftButton)
                m_stateLabel->setText("左键按下图片1");
            if(mouseEvent->buttons() & Qt::MidButton)
                m_stateLabel->setText("中键按下图片1");
            if(mouseEvent->buttons() & Qt::RightButton)
                m_stateLabel->setText("右键按下图片1");

            tmpImg=m_image1.transformed(matrix);//转换
            m_label1->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type() == QEvent::MouseButtonRelease){ //鼠标释放
            m_stateLabel->setText("鼠标释放图片1");
            m_label1->setPixmap(QPixmap::fromImage(m_image1));
        }
    }else if(watched == m_label2){
        if(event->type() == QEvent::MouseButtonPress){//鼠标按下
            QMouseEvent *mouseEvent=(QMouseEvent*)event;
            if(mouseEvent->buttons() & Qt::LeftButton)
                m_stateLabel->setText("左键按下图片2");
            if(mouseEvent->buttons() & Qt::MidButton)
                m_stateLabel->setText("中键按下图片2");
            if(mouseEvent->buttons() & Qt::RightButton)
                m_stateLabel->setText("右键按下图片2");

            tmpImg=m_image2.transformed(m);//转换
            m_label2->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type() == QEvent::MouseButtonRelease){ //鼠标释放
            m_stateLabel->setText("鼠标释放图片2");
            m_label2->setPixmap(QPixmap::fromImage(m_image2));
        }
    }else if(watched == m_label3){
        if(event->type() == QEvent::MouseButtonPress){//鼠标按下
            QMouseEvent *mouseEvent=(QMouseEvent*)event;
            if(mouseEvent->buttons() & Qt::LeftButton)
                m_stateLabel->setText("左键按下图片3");
            if(mouseEvent->buttons() & Qt::MidButton)
                m_stateLabel->setText("中键按下图片3");
            if(mouseEvent->buttons() & Qt::RightButton)
                m_stateLabel->setText("右键按下图片3");

            tmpImg=m_image3.transformed(matrix);//转换
            m_label3->setPixmap(QPixmap::fromImage(tmpImg));
        }
        if(event->type() == QEvent::MouseButtonRelease){ //鼠标释放
            m_stateLabel->setText("鼠标释放图片3");
            m_label3->setPixmap(QPixmap::fromImage(m_image3));
        }
    }

    //事件交给上层对话框处理
    return QDialog::eventFilter(watched,event);
}

