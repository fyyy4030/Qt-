#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> //TCP服务端
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onNewConnect();//客户端新的连接请求处理
    void onSendMessage();//服务端反馈客户端新的连接请求处理
    void onReadMessage();//读取数据
private:
    Ui::Widget *ui;
    QTcpServer* m_tcpServer;
    QTcpSocket* m_tcpSocket;
};
#endif // WIDGET_H
