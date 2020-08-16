#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject* parent=nullptr);

    void stop();//线程停止
protected:
    void run() override;//线程启动,执行入口

private:
    bool m_isStopped;//线程是否终止
};

#endif // MYTHREAD_H
