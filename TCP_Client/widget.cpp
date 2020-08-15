#include "widget.h"
#include "ui_widget.h"

#define TCPPORT "8888" //端口号

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tcpSocket=new QTcpSocket(this);

    //Socket有数据来了的处理
    connect(m_tcpSocket,&QTcpSocket::readyRead,this,&Widget::onReadMessage);
    //有错误
    //connect(m_tcpSocket,&QAbstractSocket::SocketError,this,&Widget::onDisplayError);
    connect(m_tcpSocket,SIGNAL(SocketError(QAbstractSocket::SocketError)),this,SLOT(onDisplayError(QAbstractSocket::SocketError)));

    ui->hostLine->setText("127.0.0.1");
    ui->portLine->setText(TCPPORT);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadMessage(){
    QByteArray bt;
    bt.resize(m_tcpSocket->bytesAvailable());//重置大小

    m_tcpSocket->read(bt.data(),bt.size());

    ui->messageLabel->setText(bt);
}

void Widget::onDisplayError(QAbstractSocket::SocketError e)
{
    qDebug()<<QString::fromLocal8Bit("SocketError:")<<e<<"\n"<<m_tcpSocket->errorString();
}


void Widget::on_connectBtn_clicked()
{
    //中止
    m_tcpSocket->abort();
    //连接主机(ip,端口)
    m_tcpSocket->connectToHost(ui->hostLine->text(),ui->portLine->text().toUInt());
}

void Widget::on_sendBtn_clicked()
{
    m_tcpSocket->write(ui->sendLine->text().toUtf8());
    m_tcpSocket->flush();//清空缓冲区
}
