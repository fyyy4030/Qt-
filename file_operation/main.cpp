//#include <QCoreApplication>//控制台
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QDate>
#include <QDataStream>
#include "fileinfo.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);//控制台

    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0)){//进行版本比较
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        //文档中有解释,主要将像素同步
    }
    QApplication a(argc, argv);//ui

    while(0){//控制台文件操作
        while(0){//只读文件 & 读写文件
            while(0){//读取文件
                QFile file("文件测试.txt");
                if(file.open(QIODevice::ReadOnly)){//只读
                    char buffer[100];

                    //读取文件
                    //返回-1 失败 ,成功返回的是读取的字节数 //读出来的数据存放位置,最多读多少(字节的长度)
                    qint32 n = file.readLine(buffer,sizeof(buffer));
                    if(n != -1){
                        //QString ds = QString::fromLocal8Bit(buffer);//转编码
                        qDebug()<<"长度:"<<n
                               <<" 内容:"<<QString::fromLocal8Bit(buffer)<<endl;
                    }
                    file.close();//关闭文件
                }else{
                    qDebug()<<file.errorString();//失败的原因
                }
                break;
            }

            while(0){//读写文件
                //文件写入
                double dpi=3.1415926;//整数精度默认6位,需调整
                int age = 13;
                QFile dataFile;
                dataFile.setFileName("文件写入测试.txt");
                if(dataFile.open(QFile::WriteOnly | QFile::Truncate)){//文件存在,则会清空并被覆盖
                    QTextStream out(&dataFile);//文件操作流
                    out.setRealNumberPrecision(3);//设置整数精度
                    out.setFieldWidth(10);//设置字段宽度
                    out.setFieldAlignment(QTextStream::AlignRight);//设置对齐方式 //右对齐

                    out<<QString("PI:")
                         //          <<qSetRealNumberPrecision(8) //设置整数精度
                         //         <<qSetFieldWidth(10) //设置字段(位宽)宽度 //对齐
                         //        <<left  //设置左对齐 //F2进入查看居中,右等对齐
                         //        <<dpi

                         //        <<bin << age //bin设置读写的整数为二进制

                         //          <<hex   //hex设置读写的整数为16进制
                         //         <<showbase  //强制显示进制前缀
                         //        <<uppercasebase //显示大写的进制前缀
                         //        <<age

                      <<scientific  //科学记数法
                     <<dpi <<age
                       ;
                    dataFile.close();//关闭文件
                }else{
                    qDebug()<<dataFile.errorString();
                }

                break;
            }
            break;
        }

        while(0){//读写二进制文件
            QFile binFile("操作二进制文件.dat");
            if(binFile.open(QIODevice::WriteOnly | QIODevice::Truncate)){//文件存在,则会清空并被覆盖
                //往文件中写入数据
                QDataStream out(&binFile);
                out<<QString("迪丽热巴")<<QDate::fromString("1999-3-9","yyyy-MM-dd")
                  <<(int)23;
                binFile.close();
            }else{
                qDebug()<<binFile.errorString();
            }

            //读
            binFile.setFileName("操作二进制文件.dat");//拷贝操作
            if(binFile.open(QIODevice::ReadOnly)){
                QDataStream in(&binFile);
                QString name;
                QDate birthday;//生日
                int age;

                in >> name >> birthday >> age;//读取数据要按格式类型,保持一致
                qDebug()<<name<<birthday;

                binFile.close();
            }else{
                qDebug()<<binFile.errorString();
            }

            break;
        }
        break;
    }

    FileInfo f;
    f.show();

    return a.exec();
}
