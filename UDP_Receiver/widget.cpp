#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_receiver = new QUdpSocket(this);
    //绑定·端口号,模式
    m_receiver->bind(6666,QUdpSocket::ShareAddress);
    //有数据过来的处理
    connect(m_receiver,&QUdpSocket::readyRead,this,&Widget::onProcessData);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onProcessData(){
    QString strData;

    //有未处理的数据报就循环
    while(m_receiver->hasPendingDatagrams()){
        //读取数据包
        QByteArray dataGram;
        dataGram.resize(m_receiver->pendingDatagramSize());//数据报大小
        m_receiver->readDatagram(dataGram.data(),dataGram.size());

        //将数据显示到界面
        ui->label_2->setText(dataGram);
    }
}

