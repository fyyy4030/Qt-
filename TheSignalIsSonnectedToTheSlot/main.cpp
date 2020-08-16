#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0)){//进行版本比较
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        //文档中有解释,主要将像素同步
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
