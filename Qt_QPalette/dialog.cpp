#include "dialog.h"
#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();

    QHBoxLayout *mainLayout=new QHBoxLayout(this);
    mainLayout->addWidget(m_ctrFrame);
    mainLayout->addWidget(m_contentFrame);

}

Dialog::~Dialog()
{
}

void Dialog::createCtrlFrame()
{
    m_ctrFrame =new QFrame;//边框
    m_ctrFrame->setFrameStyle(QFrame::Sunken | QFrame::Box);//设置下沉风格 | 箱子风格

    m_windowLabel =new QLabel("QPalette::Window:");
    m_windowComboBox = new QComboBox;
    fillColorList(m_windowComboBox);//给组合框添加颜色列表
    //选中组合框其中一个就改变window窗体背景色
    connect(m_windowComboBox,SIGNAL(activated(int)),this,SLOT(ShowWindow(int)));

    m_windowTextLabel =new QLabel("QPalette::WindowText:");
    m_windowTextComboBox =new QComboBox;
    fillColorList(m_windowTextComboBox);
    //选中组合框其中一个就改变window窗体前景色
    connect(m_windowTextComboBox,SIGNAL(activated(int)),this,SLOT(ShowWindowText(int)));

    m_buttonLabel=new QLabel("QPalette:Button:");
    m_buttonCombox = new QComboBox;
    fillColorList(m_buttonCombox);
    connect(m_buttonCombox,SIGNAL(activated(int)),this,SLOT(ShowButton(int)));

    m_buttonTextLabel=new QLabel("QPalette:ButtonTxet:");
    m_buttonTextComboBox =new QComboBox;
    fillColorList(m_buttonTextComboBox);
    connect(m_buttonTextComboBox,SIGNAL(activated(int)),this,SLOT(ShowButtonText(int)));

    m_baseLabel=new QLabel("QPalette:Base:");
    m_baseComboBox=new QComboBox;
    fillColorList(m_baseComboBox);
    connect(m_baseComboBox,SIGNAL(activated(int)),this,SLOT(ShowBase(int)));

    //左控制,右响应改变
    QGridLayout *mainLayout =new QGridLayout(m_ctrFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(m_windowLabel,0,0);
    mainLayout->addWidget(m_windowComboBox,0,1);
    mainLayout->addWidget(m_windowTextLabel,1,0);
    mainLayout->addWidget(m_windowTextComboBox,1,1);
    mainLayout->addWidget(m_buttonLabel,2,0);
    mainLayout->addWidget(m_buttonCombox,2,1);
    mainLayout->addWidget(m_buttonTextLabel,3,0);
    mainLayout->addWidget(m_buttonTextComboBox,3,1);
    mainLayout->addWidget(m_baseLabel,4,0);
    mainLayout->addWidget(m_baseComboBox,4,1);
}

//给组合框添加颜色列表
void Dialog::fillColorList(QComboBox *comboBox)
{
    QStringList colorList = QColor::colorNames();//获取所有颜色
    QString color;
    QPixmap pix(QSize(70,20));
    foreach(color,colorList){
        pix.fill(QColor(color));//填充颜色
        comboBox->addItem(QIcon(pix),NULL);//添加项目
        comboBox->setIconSize(QSize(70,20));//设置图片大小
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);//根据内容进行适应,设置大小
    }
}

void Dialog::createContentFrame()
{
    m_contentFrame=new QFrame;
    m_contentFrame->setAutoFillBackground(true);//自动填充背景

    m_label1=new QLabel("请选择一个值");
    m_label2=new QLabel("请输入字符串");
    m_combobox1=new QComboBox;
    m_lineEdit=new QLineEdit;
    m_textEdit=new QTextEdit;

    m_okBtn=new QPushButton("确认");
    m_cancelBtn=new QPushButton("取消");
    m_okBtn->setAutoFillBackground(true);

    QGridLayout *Toplayout=new QGridLayout;
    Toplayout->addWidget(m_label1,0,0);
    Toplayout->addWidget(m_combobox1,0,1);
    Toplayout->addWidget(m_label2,1,0);
    Toplayout->addWidget(m_lineEdit,1,1);
    Toplayout->addWidget(m_textEdit,2,0,1,2);

    QHBoxLayout *bottomLayout=new QHBoxLayout;
    bottomLayout->addWidget(m_okBtn);
    bottomLayout->addWidget(m_cancelBtn);

    QVBoxLayout *mainLayout=new QVBoxLayout(m_contentFrame);
    mainLayout->addLayout(Toplayout);
    mainLayout->addLayout(bottomLayout);
}

void Dialog::ShowWindow(int index)
{
    QStringList colorList=QColor::colorNames();//获取所有颜色
    QColor color =QColor(colorList[index]);//获取左边框架对应操作组合框选择的颜色
    QPalette p =m_contentFrame->palette();//获取框架的调色板
    p.setColor(QPalette::Window,color);//设置颜色(窗体,)
    m_contentFrame->setPalette(p);//将调色板设置为更新的
    m_contentFrame->update();//更新
}

void Dialog::ShowWindowText(int index)
{
    QStringList colorList=QColor::colorNames();
    QColor color =QColor(colorList[index]);
    QPalette p =m_contentFrame->palette();
    p.setColor(QPalette::WindowText,color);
    m_contentFrame->setPalette(p);
    m_contentFrame->update();
}

void Dialog::ShowButton(int index)
{
    QStringList colorList=QColor::colorNames();
    QColor color =QColor(colorList[index]);
    QPalette p =m_contentFrame->palette();
    p.setColor(QPalette::Button,color);
    m_contentFrame->setPalette(p);
    m_contentFrame->update();
}

void Dialog::ShowButtonText(int index)
{
    QStringList colorList=QColor::colorNames();
    QColor color =QColor(colorList[index]);
    QPalette p =m_contentFrame->palette();
    p.setColor(QPalette::ButtonText,color);
    m_contentFrame->setPalette(p);
    m_contentFrame->update();
}

void Dialog::ShowBase(int index)
{
    QStringList colorList=QColor::colorNames();
    QColor color =QColor(colorList[index]);
    QPalette p =m_contentFrame->palette();
    p.setColor(QPalette::Base,color);
    m_contentFrame->setPalette(p);
    m_contentFrame->update();
}

