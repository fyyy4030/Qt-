#include "dialog.h"
#include "ui_dialog.h"
#include <QStackedLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btnClose, &QPushButton::clicked, this, [this](){
           hide();
       });

       m_webView = new QWebEngineView(this);
       QStackedLayout* layout = new QStackedLayout(ui->frame);
       ui->frame->setLayout(layout);
       layout->addWidget(m_webView);
       m_webView->load(QUrl("http://localhost:7777"));
       QDialog::show();
}

Dialog::~Dialog()
{
    delete ui;
}

//这里的关闭按钮实际上只是把界面隐藏起来了，所以重载一下show方法，保证每次打开时调试的页面是最新
void Dialog::show()
{
    m_webView->reload();
    QDialog::show();
}
