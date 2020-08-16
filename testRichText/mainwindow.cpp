#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame> //文本框架
#include <QFileDialog> //文件对话框
#include <QImageReader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //文本框架
    while(1){
        while(1){//将隐藏的文本根框架设置一个红色的文本框架框
            //文本文档类
            QTextDocument *document = ui->textEdit->document();//获取文档对象

            //文本框架类
            QTextFrame *rootFrame = document->rootFrame();//获取根框架

            //文本框架格式
            QTextFrameFormat format;
            //设置边界画
            format.setBorderBrush(Qt::red);//边框颜色(红)
            //设置边界
            format.setBorder(3);//设置边框宽度(像素)
            //设置框架格式
            rootFrame->setFrameFormat(format);
            break;
        }

        while(1){//文本框架设置框架风格
            //设置文本边框风格
            QTextFrameFormat frameFormat;
            //设置背景
            frameFormat.setBackground(Qt::lightGray);//设置背景色(亮灰)
            //设置边缘
            frameFormat.setMargin(10);//设置边距 //此框架与根框架的距离
            //设置填料
            frameFormat.setPadding(5);//设置填衬 //文字与边框的距离
            frameFormat.setBorder(2);//设置边框宽度
            //设置边界风格
            frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);//设置边框风格 //虚线风格

            //文本光标
            QTextCursor cursor = ui->textEdit->textCursor();//获取光标信息
            cursor.insertFrame(frameFormat);//插入边框
            break;
        }
        break;
    }

    //文本框架,文本块遍历操作
    while(1){
        while(1){//文本框架操作
            QAction *action_textFrame = new QAction("框架",this);
            connect(action_textFrame,&QAction::triggered,this,&MainWindow::showTextFrame);

            ui->mainToolBar->addAction(action_textFrame);//工具栏添加动作
            break;
        }

        while(1){//文本块操作
            QAction *action_textBlock = new QAction("文本块",this);
            connect(action_textBlock,&QAction::triggered,this,&MainWindow::showTextBlock);
            ui->mainToolBar->addAction(action_textBlock);
            break;
        }
        break;
    }

    //设置字体
    while(1){
        QAction *action_textFont = new QAction("字体",this);
        action_textFont->setCheckable(true);//功能是否可用
        connect(action_textFont,&QAction::triggered,this,&MainWindow::setTextFont);
        ui->mainToolBar->addAction(action_textFont);
        break;
    }

    //表格,列表,图片
    while(1){
        QAction *action_textTable=new QAction("表格",this);
        QAction *action_textList=new QAction("列表",this);
        QAction *action_textImage=new QAction("图片",this);

        connect(action_textTable,&QAction::triggered,this,&MainWindow::insertTable);
        connect(action_textList,&QAction::triggered,this,&MainWindow::insertList);
        connect(action_textImage,&QAction::triggered,this,&MainWindow::insertImage);

        ui->mainToolBar->addAction(action_textTable);
        ui->mainToolBar->addAction(action_textList);
        ui->mainToolBar->addAction(action_textImage);

        break;
    }

    //语法高亮
    while(1){
        m_sLighter = new MySyntaxHighlighter(ui->textEdit->document());






        break;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()//遍历文本框架
{
    //文本文档
    QTextDocument *document = ui->textEdit->document();//获取当前文档对象

    QTextFrame *frame= document->rootFrame();//获取根框架

    QTextFrame::iterator it;//迭代器
    for(it=frame->begin();it != frame->end();it++){
        QTextFrame *childFrame = it.currentFrame();//获取当前框架指针
        QTextBlock childBlock=it.currentBlock();//获取当前的文本块
        if(childFrame)//如果有框架
            qDebug()<<"frame\n";
        else if(childBlock.isValid())//如果有文本块
            qDebug()<<"block:"<<childBlock.text()<<endl;

    }

}

void MainWindow::showTextBlock()//遍历文本块
{
    QTextDocument *document=ui->textEdit->document();//获取当前文本对象
    QTextBlock block = document->firstBlock();//得到第一个文本块

    //文本块个数blockCount()
    for(int i =0;i<document->blockCount();i++){
        qDebug().noquote()<<QString("文本块%1,文本块首行行号为:%2,长度:%3,内容:%4")
        .arg(i).arg(block.firstLineNumber()).arg(block.length()).arg(block.text());

        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked)//设置字体
{
    if(!checked)return;
    
    QTextCursor cursor=ui->textEdit->textCursor();//获取光标
    QTextBlockFormat blockFormat;//文本块格式
    blockFormat.setAlignment(Qt::AlignCenter);//居中对齐
    cursor.insertBlock(blockFormat);
    QTextCharFormat charFormat;//字符格式
    charFormat.setBackground(Qt::lightGray);//设置背景色 亮灰色
    charFormat.setForeground(Qt::blue);//设置前景色(字颜色)
    charFormat.setFont(QFont(("宋体"),QFont::Bold,true));//设置字体(宋体,加粗)
    charFormat.setFontUnderline(true);//设置下划线
    cursor.setCharFormat(charFormat);//设置字符格式
    cursor.insertText("哈哈哈哈哈");//插入文本
}

void MainWindow::insertTable()//插入表格
{
    QTextCursor cursor=ui->textEdit->textCursor();//获取光标
    QTextTableFormat format;//文本表格格式
    format.setCellSpacing(2);//设置细胞行距 //设置边白 //表格外变白
    format.setCellPadding(10);//设置细胞填衬 //表格内边白
    cursor.insertTable(3,3,format);//插入表格(行,列,格式);
}

void MainWindow::insertList()//插入列表
{
    QTextListFormat format;//文本列表格式
    format.setStyle(QTextListFormat::ListDecimal);//设置风格(数字编号)
    ui->textEdit->textCursor().insertList(format);//界面->文本编辑器->文本光标所在.插入列表
}

void MainWindow::insertImage()//插入图片
{
    //弹出文件对话框,用户选择图片后,接收路径
    QString filePath=QFileDialog::getOpenFileName(this,"选择图片","."
       ,"JPEG(*.jpg *.jpeg);; GIF(*.gif);; PNG(*.png)");

    QUrl url(QString("file://%1").arg(filePath));//资源定位器
    QImage image = QImageReader(filePath).read();//Q图片=图片阅读器(文件路径).阅读

    QTextDocument *document=ui->textEdit->document();//获取文档对象

    //文档添加资源(添加的种类,资源定位器,变体(图片));
    document->addResource(QTextDocument::ImageResource,url,QVariant(image));

    QTextCursor cursor=ui->textEdit->textCursor();//获取光标

    QTextImageFormat imgFormat;//文本图片格式
    //设置格式
    imgFormat.setWidth(image.width());//宽
    imgFormat.setHeight(image.height());//高
    imgFormat.setName(url.toString());//路径

    cursor.insertImage(imgFormat);

}
