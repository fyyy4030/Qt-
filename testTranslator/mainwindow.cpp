#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTranslator> //翻译
#include <QApplication>

//1) tr()函数获取需要翻译的文本
//2) lupdate.exe(Qt提供的工具)编译生成xxx.ts文件
//3) linguist.exe进行翻译
//4) lrelease.exe生成xxx.qm文件
//5) 使用

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_languageBox=new QComboBox;
    m_languageBox->addItem("Chinese","zh");
    m_languageBox->addItem("English","en");
    m_languageBox->addItem("Latin","la");
    m_languageBox->addItem("French","fr");

    connect(m_languageBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changLanguage(int)));

    //tr函数获取需要翻译的文本
    m_nameLabel=new QLabel(tr("德玛西亚"));
    m_signLabel=new QLabel(tr("草丛伦:塔在人在,人在塔不在"));

    setWindowTitle(tr("英雄联盟"));
    resize(400,100);

    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->addWidget(m_languageBox);
    layout->addWidget(m_nameLabel);
    layout->addWidget(m_signLabel);
    //setLayout(layout);
}

MainWindow::~MainWindow()
{
}

void MainWindow::changLanguage(int index)
{
    //为保证只有一个语言
    static QTranslator* translaator;
    if(translaator){
        qApp->removeTranslator(translaator);
        delete translaator;
        translaator=nullptr;
    }

    translaator=new QTranslator;

    QString languagCode=m_languageBox->itemData(index).toString();//zh
    QString qmFile="lang_"+ languagCode;

    //加载
    if(translaator->load(qmFile)){
        qApp->installTranslator(translaator);//安装注册器
    }

    //翻译文本
    m_nameLabel->setText(tr("TXT_NAME_WORD","Demacia"));//(要翻译的ID,找不到就用这个)
    m_signLabel->setText(tr("TXT_SIGN_WORD","Grass Lun: tower in person in, person in the tower not in"));
    setWindowTitle(tr("TXT_TITLE_WORD","League of Legends"));
}

