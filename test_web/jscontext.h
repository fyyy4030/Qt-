#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QObject>
#include <QWebEnginePage>

//与js通信 //Q_PROPERTY(QString msgRHtmlTmpl MEMBER m_msgRHtmlTmpl NOTIFY signalMsgHtml)
//msgRHtmlTmpl和msgRHtmlTmpl连接,当一方修改就发送signalMsgHtml信号
class JsContext : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString msgRHtmlTmpl MEMBER m_msgRHtmlTmpl NOTIFY signalMsgHtml)
public:
    explicit JsContext(QObject *parent = nullptr);

signals:
    void recvdMsg(const QString& msg);
    void signalMsgHtml(const QString& html);
public:
    // 向页面发送消息
    void sendMsg(QWebEnginePage* page, const QString& msg);

    void sedhtml(QWebEnginePage* page, const QString& msg);

public slots:
    // 接收到页面发送来的消息 //onMsg这个方法是提供给js直接调用的方法，按照Qt官方的说明，这个方法必须被声明为一个slot
    void onMsg(const QString& msg);

private:
    void initm_msgRHtmlTmpl();

private:
    QString m_msgRHtmlTmpl;


};

#endif // JSCONTEXT_H
