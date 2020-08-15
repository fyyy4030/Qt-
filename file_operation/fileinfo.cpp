#include "fileinfo.h"
#include "ui_fileinfo.h"
#include <QFileDialog>
#include <QDateTime>

FileInfo::FileInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileInfo)
{
    ui->setupUi(this);
}

FileInfo::~FileInfo()
{
    delete ui;
}

void FileInfo::getFileInfo(QString &fileName)
{
    QFileInfo info(fileName);
    qint64 size =info.size();//获取文件的大小
    QDateTime time = info.created();//获取文件创建日期
    QDateTime time1 = info.lastModified();//文件最后一次修改时间
    QDateTime time2 = info.lastRead();//文件最后一次访问

    //文件的属性信息
    bool b = info.isDir();//是不是目录
    bool b1 = info.isFile();//是不是文件
    bool b2 = info.isSymLink();//是不是链接
    bool b3 = info.isHidden();//是不是隐藏
    bool b4 = info.isReadable();//是不是可读
    bool b5 = info.isWritable();//是不是可写
    bool b6 = info.isExecutable();//是不是可执行文件

    ui->filesize->setText(QString::number(size));
    ui->begintime->setText(time.toString());
    ui->amendtime->setText(time1.toString());
    ui->endtime->setText(time2.toString());

    ui->catalog->setChecked(b);//设置是否勾选
    ui->file->setChecked(b1);
    ui->symbol->setChecked(b2);
    ui->hide->setChecked(b3);
    ui->read->setChecked(b4);
    ui->write->setChecked(b5);
    ui->write_2->setChecked(b6);
}

void FileInfo::on_pushButton_clicked()
{
    //QString filename1 = QFileDialog::getOpenFileName(this,"打开文件",".","files(*)");//所有文件都可以打开
    QString filename1 = QFileDialog::getExistingDirectory(this,"选择目录",".");//.是默认当前路径 //选择目录
    ui->filename->setText(filename1);//将文件路径显示出输入框
    getFileInfo(filename1);
}

