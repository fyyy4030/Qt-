#ifndef DIGITAL_CLOCK_H
#define DIGITAL_CLOCK_H

#include <QLCDNumber> //显示编号
#include <QPoint>

//数字的钟表 :
class Digital_Clock : public QLCDNumber
{
    Q_OBJECT
public:
    Digital_Clock(QWidget *parent = 0);

protected:
    //重写事件
    void mousePressEvent(QMouseEvent* event);//鼠标按下事件(鼠标事件)
    void mouseMoveEvent(QMouseEvent* event);//鼠标移动事件

private slots:
    void showTime();//显示时间

private:
    QPoint m_dragPosition;//保存鼠标点相对时钟窗体左上角的偏移值
    bool m_showColon;//钟表显示" : "
};

#endif // DIGITAL_CLOCK_H
