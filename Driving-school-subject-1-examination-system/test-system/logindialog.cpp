#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox> //信息框
#include <QFile>  //文件流
#include <QTextStream> //转换格式

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);//让背景图片能设置填充 true填充 false不填充
    this->resize(ui->label->width(),ui->label->height());//窗体宽高(宽,高);
    setFixedSize(width(),height());//设置窗体固定大小 //自身的宽和高
    setWindowTitle("驾校科目一考试系统");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);//普通对话框 | 取消？
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_landingpushButton_clicked(){//点击信号
    /*正则验证邮箱地址 用户名@域名
    //元字符解释:^表示规则字符串的开始 $表示规则字符串的结束
    //+表示匹配次数>=1次 *表示匹配任意次数(可为0次)
    //{n,m} 表示匹配次数至少n次,至多m次
    // \是转义字符
    */
    QRegExp rx("^[A-Za-z0-9]+([_\.][A-Za-z0-9]+)*@([A-Za-z0-9\-]+\.)+[A-Za-z]{2,6}$");
    //text()返回控件文件
    bool ret=rx.exactMatch(ui->accountlineEdit->text());//对文本精确匹配
    if(!ret){//匹配不成功
        QMessageBox::information(this,"提示","非邮箱地址,请您重新输入!");//信息提示框
        ui->accountlineEdit->clear();//清理输入框
        ui->passwordlineEdit->clear();
        ui->accountlineEdit->setFocus();//聚焦于此控件
    }else{//邮箱格式正确
        QString filename;//当前想要读取的文件路径 //账号密码数据文件
        QString strname;//用户输入的账号
        QString strpass;//用户输入的密码
        QString strline;//每行读取的一行数据
        QStringList strList;//字符串链表 //保存分割读取的一行数据

        filename="account.txt";//如果文件在debug文件夹就不需要../
        strname=ui->accountlineEdit->text();
        strpass=ui->passwordlineEdit->text();

        //读取文件
        QFile file(filename);//文件路径初始化
        QTextStream stream(&file);//读写文件
        if(file.open(QIODevice::ReadOnly |QIODevice::Text)){//只读|纯文本
            while(!stream.atEnd()){//检测到文件结束
                strline=stream.readLine();//读一行
                strList = strline.split(",");//读取的数据有,号就分割 //根据自定义文本设置是账号,密码
                if(strname == strList.at(0)){//账号匹配成功
                    if(strpass == strList.at(1)){//密码匹配成功
                        QMessageBox::information(this,"提示","欢迎进入科目一考试系统!");
                        file.close();
                        done(Accepted);//接受/同意 //同意.exec()运行
                        return;
                    }else{
                        QMessageBox::information(this,"提示","您输入的密码有误请重新输入!");
                        ui->passwordlineEdit->clear();
                        ui->passwordlineEdit->setFocus();
                        file.close();//关闭文本
                        return;
                    }
                }
            }
            QMessageBox::information(this,"提示","您输入的账号和密码有误,请重新输入!");
            ui->accountlineEdit->clear();//清理输入框
            ui->passwordlineEdit->clear();
            ui->accountlineEdit->setFocus();//聚焦于此控件
            file.close();//关闭文本
            return;
        }else{
            QMessageBox::information(this,"提示","读取账号数据文件失败!");
            return;
        }

    }
}

void LoginDialog::on_pushButton_2_clicked()
{//点击取消按钮后
    done(Rejected);//拒绝
}
