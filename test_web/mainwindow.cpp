#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedLayout>
#include <QStatusBar>
#include <QSlider>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "7777");//改成在页面上点击右键并选择"Inspect"，即可呼出调试界面。
    m_webView = new QWebEngineView(this);
    QStackedLayout* layout = new QStackedLayout(ui->frame);
    ui->frame->setLayout(layout);
    layout->addWidget(m_webView);

    connect(ui->btnGo, &QPushButton::clicked,[this]() {
        QString url = ui->addressEdit->text();//http://
        if (!url.isEmpty())
        {
            m_webView->load(url);//加载静态或者动态网页均可
        }
    });

    connect(ui->btnRefresh, &QPushButton::clicked,[this]() {
        m_webView->reload();//重新加载网页
    });

    //实现Inspector调试界面,按下F12弹出简化页面上点击右键并选择"Inspect"，即可呼出调试界面
    //在主窗口初始化时修改一下QWebEngineViewContextMenu设置。
    //因为QWebEngineView继承了QWidget，所以可以使用与处理QWidget类似的方式定制ContextMenu：
    m_webView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_inspector = NULL;
    connect(m_webView, &QWidget::customContextMenuRequested,[this]() {
        QMenu* menu = new QMenu(this);
        QAction* action = menu->addAction("Inspect");
        connect(action, &QAction::triggered,[&](){
            if(m_inspector == NULL)
            {
                m_inspector = new Dialog(this);
            }
            else
            {
                m_inspector->show();
            }
        });
        menu->exec(QCursor::pos());
    });

    //与js交互
    //创建QWebChannel对象;
    //向QWebChannel对象注册Qt对象。 例子里的Qt对象就是上面实现的JsContext对象。
    //注意：这里注册时所用的名字“context”，就是js获取qt对象时所使用的索引名。
    //将设置好的QWebChannel对象设置为当前页面的通道。即调用QWebEnginePage的setWebChannel方法。
    //注意：如果没有正确注册webchannel，在js调用qt对象时会出现qt对象为undefined的情况。
    m_jsContext = new JsContext(this);
    m_webChannel = new QWebChannel(this);
    m_webChannel->registerObject("abcdefg", m_jsContext);
    m_webView->page()->setWebChannel(m_webChannel);
//测试的html:  file:///D:/C++_source_code_Qt_VS/IT_QT/QT_C++_SourceCode/test_web/test.html
    connect(m_jsContext, &JsContext::recvdMsg, this, [this](const QString& msg) {
        QMessageBox::information(this,QString::fromLocal8Bit("recvdMsg"),QString::fromLocal8Bit("Received message:") + msg.toUtf8());
    });

    connect(ui->btnSend, &QPushButton::clicked, this, [this]() {
        QString msg = ui->msgEdit->text();
        if (!msg.isEmpty())
        {
            m_jsContext->sendMsg(m_webView->page(), msg);
        }
    });

    connect(ui->add,&QPushButton::clicked, this,[this](){

        if (!ui->msgEdit->text().isEmpty())
        {
            m_jsContext->sedhtml(m_webView->page(), ui->msgEdit->text());
        }
        ui->msgEdit->clear();
    });

}

MainWindow::~MainWindow()
{
    delete m_webView;
    delete ui;
}

void MainWindow::onAdd(){

}

