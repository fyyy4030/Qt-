#include "mythread.h"
#include <QDebug>
#include <QMutex> //互斥锁

//多线程并发执行的时候，共享数据的准确性是不确定的
//解决方法：给共享数据加一把锁。

int gPies=0;
QMutex mutex;//互斥锁

MyThread::MyThread(QObject* parent)
{
    m_isStopped=false;
}

void MyThread::stop()
{
    m_isStopped=true;
}

void MyThread::run()
{
    m_isStopped=false;
    int i = 0;
    while(!m_isStopped && i++ < 200000){
        //操作共享数据时,在之前加锁
        mutex.lock();
        qDebug()<<QString("天上掉下%1个馅饼呢.").arg(++gPies);
        //操作完共享数据后,在之后释放
        mutex.unlock();
    }
}
