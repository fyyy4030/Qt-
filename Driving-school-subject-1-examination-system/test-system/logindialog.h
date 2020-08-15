#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE

namespace Ui {
//F2进入深层文件 //F1帮助
class LoginDialog;//ui_LoginDialog子类,用于描述登陆窗口界面信息
}

QT_END_NAMESPACE

class LoginDialog : public QDialog {
    /*Q_OBJECT当前的类支持信号与槽的机制
     //必须继承QOBJECT的类才有用
     //信号与槽是用于不同类之间的通信
     //比如是A与B窗口和控件*/
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots://私有的槽方法
    //槽方法 //自定义的QT也自动连接,格式需: //on_控件对象name_信号name
    void on_landingpushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::LoginDialog *ui;
};
#endif // LOGINDIALOG_H
