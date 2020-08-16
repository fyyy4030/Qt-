#include "dialog.h"
#include <QFileDialog> //文件对话框
#include <QColorDialog>//颜色对话框
#include <QFontDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("标准对话框示例:");
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    m_fileBtn = new QPushButton("文件标准对话框:");
    m_fileEdit =new QLineEdit;

    m_colorBtn =new QPushButton("颜色标准对话框:");
    m_colorFrame=new QFrame;
    m_colorFrame->setFrameStyle(QFrame::Box);//设置边框风格
    m_colorFrame->setAutoFillBackground(true);//是否填充背景属性

    m_fontBtn=new QPushButton("字体标准对话框:");
    m_fontEdit=new QLineEdit("喂,你还好么.");

    m_inputBtn=new QPushButton("标准输入对话框");

    m_messageBtn=new QPushButton("标准消息对话框");

    m_mainLayout=new QGridLayout(this);
    m_mainLayout->addWidget(m_fileBtn,0,0);
    m_mainLayout->addWidget(m_fileEdit,0,1);

    m_mainLayout->addWidget(m_colorBtn,1,0);
    m_mainLayout->addWidget(m_colorFrame,1,1);

    m_mainLayout->addWidget(m_fontBtn,2,0);
    m_mainLayout->addWidget(m_fontEdit,2,1);

    m_mainLayout->addWidget(m_inputBtn,3,0,1,2);//放到第3行,第0列,占1行,占2列
    m_mainLayout->addWidget(m_messageBtn,4,0,1,2);

    connect(m_fileBtn,&QPushButton::clicked,this,&Dialog::ShowFileDialog);//信号与槽连接
    connect(m_colorBtn,&QPushButton::clicked,this,&Dialog::ShowColorDialog);
    connect(m_fontBtn,&QPushButton::clicked,this,&Dialog::ShowFontDialog);
    connect(m_inputBtn,&QPushButton::clicked,this,&Dialog::ShowInputDialog);
    connect(m_messageBtn,&QPushButton::clicked,this,&Dialog::ShowMessageBoxDialog);
}

Dialog::~Dialog()
{

}

void Dialog::ShowFileDialog()
{
    //打开文件对话框并获取用户选择的文件
    //窗体,标题,目录(.是当前),过滤(条件;;条件;;n...),默认(可选)
    QString spath = QFileDialog::getOpenFileName(this,"标准文件对话框",".",
    "C++ files(*.cpp);;C files(*.c);;Header files(*.h)");

    m_fileEdit->setText(spath);//将文件路径显示到行编辑器
}

void Dialog::ShowColorDialog()
{
    //获取用户所选颜色 (填上即变默认)
    QColor color=QColorDialog::getColor(Qt::yellow);
    if(color.isValid()){//是否合法
        m_colorFrame->setPalette(QPalette(color));//设置调色板
    }
}

void Dialog::ShowFontDialog()
{
    //获取用户所选字体
    bool ok;//是否成功获取到用户所选字体
    QFont font = QFontDialog::getFont(&ok);//用户所选字体
    if(ok){
        m_fontEdit->setFont(font);//设置字体
    }
}

void Dialog::ShowInputDialog()
{
    m_inputDialog=new InputDialog(this);
    m_inputDialog->show();
}

void Dialog::ShowMessageBoxDialog()
{
    m_messageBox=new MessageBox(this);
    m_messageBox->show();
}
