#ifndef MYACTION_H
#define MYACTION_H
#include <QWidgetAction> //部件功能
#include <QLineEdit> //行编辑器

//自定义功能 : 部件功能
class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    MyAction(QObject *parent = 0);

protected:
    //重写创建部件
    QWidget* createWidget(QWidget *parent);

signals://信号
    void getText(const QString& string);//接收用户输入的字符串

private slots:
    void sendText();//发送文本

private:
    //行编辑器
    QLineEdit* lineEdit;

};

#endif // MYACTION_H
