#include "messagebox.h"
#include <QMessageBox>

MessageBox::MessageBox(QWidget* parent):QDialog(parent)
{
    setWindowTitle("标准信息对话框集合:");
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    m_hintLabel=new QLabel("请选择一种消息框");//提示

    m_issueBtn=new QPushButton("问题消息框");//问题
    m_messageBtn=new QPushButton("信息消息框");//信息
    m_noticeBtn=new QPushButton("警告消息框");//警告
    m_errorBtn=new QPushButton("错误消息框");//错误
    m_QtBtn=new QPushButton("关于QT消息框");//Qt的
    m_aboutBtn=new QPushButton("关于消息框");//关于

    m_customLabel=new QLabel;
    m_customBtn=new QPushButton("自定义消息框");//自定义
    m_customLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);//设置边框风格(面版 | 下沉)

    m_mainLayout=new QGridLayout(this);//布局管理器
    m_mainLayout->addWidget(m_hintLabel,0,0,1,2);
    m_mainLayout->addWidget(m_issueBtn,1,0);
    m_mainLayout->addWidget(m_messageBtn,1,1);
    m_mainLayout->addWidget(m_noticeBtn,2,0);
    m_mainLayout->addWidget(m_errorBtn,2,1);
    m_mainLayout->addWidget(m_QtBtn,3,0);
    m_mainLayout->addWidget(m_aboutBtn,3,1);
    m_mainLayout->addWidget(m_customBtn,4,0);
    m_mainLayout->addWidget(m_customLabel,4,1);

    connect(m_issueBtn,&QPushButton::clicked,this,&MessageBox::ShowIssueDialog);

    connect(m_messageBtn,&QPushButton::clicked,this,&MessageBox::ShowMessageDialog);

    connect(m_noticeBtn,&QPushButton::clicked,this,&MessageBox::ShowNoticeDialog);

    connect(m_errorBtn,&QPushButton::clicked,this,&MessageBox::ShowErrorDialog);

    connect(m_QtBtn,&QPushButton::clicked,this,&MessageBox::ShowQtDialog);

    connect(m_aboutBtn,&QPushButton::clicked,this,&MessageBox::ShowAboutDialog);

    connect(m_customBtn,&QPushButton::clicked,this,&MessageBox::ShowCustomDialog);
}

void MessageBox::ShowIssueDialog()
{
    m_hintLabel->setText("问题消息框");
    int res = QMessageBox::question(this,"问题消息框","您已打开消息框,是否关闭?"
     ,QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok);

    switch (res) {
    case QMessageBox::Ok:
        m_hintLabel->setText("问题消息框-确定");
        break;
    case QMessageBox::Cancel:
        m_hintLabel->setText("问题消息框-取消");
        break;

    default:
        m_hintLabel->setText("问题消息框-X");
        break;
    }
}

void MessageBox::ShowMessageDialog()
{
    m_messageBtn->setText("信息消息框");
    QMessageBox::information(this,"信息提示框","这是个信息提示框,我也不知道写啥?");
}

void MessageBox::ShowNoticeDialog()
{
    m_hintLabel->setText("警告消息框");
    int res = QMessageBox::warning(this,"警告消息框","您有未保存的数据,是否保存?(假)"
     ,QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
      ,QMessageBox::Save);

    switch (res) {
    case QMessageBox::Save:
        m_hintLabel->setText("警告消息框-保存");
        break;
    case QMessageBox::Discard:
        m_hintLabel->setText("警告消息框-忽视");
        break;
    case QMessageBox::Cancel:
        m_hintLabel->setText("警告消息框-取消");
        break;

    default:
        m_hintLabel->setText("问题消息框-X");
        break;
    }

}

void MessageBox::ShowErrorDialog()
{
    m_hintLabel->setText("错误消息框");
    QMessageBox::critical(this,"错误消息框","发生重大错误(假)!!!");

}

void MessageBox::ShowQtDialog()
{
    m_hintLabel->setText("关于Qt的消息框");
    QMessageBox::aboutQt(this,"关于Qt...");
}

void MessageBox::ShowCustomDialog()
{
    m_customLabel->setText("自定义消息框");

    //自制消息框
    QMessageBox custom;
    custom.setWindowTitle("自定义消息框");//设置标题
    QPushButton *yes = custom.addButton("好吧",QMessageBox::ActionRole);//添加按钮("标题",动作的角色)
    QPushButton *no = custom.addButton("算了吧",QMessageBox::ActionRole);
    QPushButton *norm = custom.addButton(QMessageBox::Cancel);//标准的取消按钮

    custom.setIconPixmap(QPixmap("DDD.jpg"));//设置图标
    custom.exec();//启动

    if(custom.clickedButton()==yes){
        m_customLabel->setText("点击了好吧");
    }else if(custom.clickedButton()==no){
        m_customLabel->setText("点击了算了吧");
    }else if(custom.clickedButton()==norm){
        m_customLabel->setText("点击了标准的取消按钮");
    }
}

void MessageBox::ShowAboutDialog()
{
    m_hintLabel->setText("关于消息框");
    QMessageBox::about(this,"关于","这是个关于关于的信息.");
}
