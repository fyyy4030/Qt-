#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MouseEvent; }
QT_END_NAMESPACE

//鼠标事件
class MouseEvent : public QMainWindow
{
    Q_OBJECT

public:
    MouseEvent(QWidget *parent = nullptr);
    ~MouseEvent();

protected:
    void mousePressEvent(QMouseEvent *event);//按下
    void mouseMoveEvent(QMouseEvent *event);//移动
    void mouseReleaseEvent(QMouseEvent *event);//释放

private:
    Ui::MouseEvent *ui;

    QLabel *m_statusLabel;
    QLabel *m_posLabel;
};
#endif // MOUSEEVENT_H
