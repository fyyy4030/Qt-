#include "testlayouts.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0)){//进行版本比较
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        //文档中有解释,主要将像素同步
    }

    //如果想要将QT控件随着窗体放大缩小自己变化,还是需要管理布局为栅格布局
    //或者将水平策略和垂直策略改为扩大的&展开的试试
    QApplication a(argc, argv);
    testLayouts w;
    w.show();

    return a.exec();
}
