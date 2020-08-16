#include "jscontext.h"
#include <QJsonObject>
#include <QJsonDocument>

JsContext::JsContext(QObject *parent) : QObject(parent)
{

initm_msgRHtmlTmpl();

}

//Qt的web浏览器也就是html的界面向页面发送消息
void JsContext::sendMsg(QWebEnginePage* page, const QString& msg)
{
    page->runJavaScript(QString("recvMessage('%1');").arg(msg));

}

//web向Qt发信息
void JsContext::onMsg(const QString &msg)
{
    emit recvdMsg(msg);
}

void JsContext::sedhtml(QWebEnginePage* page, const QString& msg){
    m_msgRHtmlTmpl.replace(QString("{{MSG}}"),msg);

    //int i = m_msgRHtmlTmpl.indexOf(QString::fromLocal8Bit("{{MSG}}"));
    //m_msgRHtmlTmpl=m_msgRHtmlTmpl.replace(i,7,msg);

    //QJsonObject msgObj;//用于发送信息的
    //msgObj.insert("MSG",msg);//key,值 //体现在html中的大写MSG中插入
    //msgObj.insert("MSG",msg);
    //QString ss=QJsonDocument(msgObj).toJson(QJsonDocument::Compact);


    page->runJavaScript(QString("appendHtml('%1');").arg(m_msgRHtmlTmpl));
    initm_msgRHtmlTmpl();//成功了归位,以待下回使用,不然数据还是那个
}

void JsContext::initm_msgRHtmlTmpl(){
    //m_msgRHtmlTmpl.clear();
    //设置头像成功!!!
    m_msgRHtmlTmpl = "<div class=\"msg-wrap right\">\
            <img class=\"header\" src=\"./D.jpg\"\ ondragstart=\"return false;\" \
onselectstart=\"return false;\">\
            <div class=\"msg\">{{MSG}}<span class=\"trigon\"></span></div>\
    </div>";
}
