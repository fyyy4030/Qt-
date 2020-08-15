#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_sender  = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked(){
    //发送数据是QByteArray
    QByteArray dataGram = ui->lineEdit->text().toUtf8();
    //写数据包·数据,数据大小,地址,端口号
    m_sender->writeDatagram(dataGram.data(),dataGram.size(),
                              QHostAddress::Broadcast,6666);

    //循环广播
    //for(quint16 port= 6666; port < 6666 +200; port++){
      //   m_sender->writeDatagram(dataGram.data(),dataGram.size(),
    //                            QHostAddress::Broadcast,port);
    //}
}
