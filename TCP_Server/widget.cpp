#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_tcpServer=new QTcpServer(this);

    //监听来自客服端的请求
    if(!m_tcpServer->listen(QHostAddress::Any,8888))//ip,端口
    {//失败
        qDebug()<<m_tcpServer->errorString();
        m_tcpServer->close();
    }

    //新的连接
    connect(m_tcpServer,&QTcpServer::newConnection,this,&Widget::onNewConnect);
    connect(m_tcpServer,&QTcpServer::newConnection,this,&Widget::onSendMessage);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnect(){
    //当前连接来的客户端
    m_tcpSocket=m_tcpServer->nextPendingConnection();
    //断开连接
    connect(m_tcpSocket,&QTcpSocket::disconnected,m_tcpSocket,&QTcpSocket::deleteLater);
    //Socket有数据时
    connect(m_tcpSocket,&QTcpSocket::readyRead,this,&Widget::onReadMessage);
}

void Widget::onSendMessage(){
    QString str="你好,客户端!";
    m_tcpSocket->write(str.toUtf8());
    ui->label->setText("发送数据成功!");
}

void Widget::onReadMessage()
{
    //读取全部数据
    QByteArray bt = m_tcpSocket->readAll();
    ui->readLabel->setText(bt);
}

