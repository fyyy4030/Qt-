#include <QApplication> //应用程序
#include <QWidget>
#include <QDebug>

int main(int argc,char *argv[]){
    QApplication app(argc,argv);
    QWidget widgets;
    widgets.setWindowTitle("widget窗体");//设置标题
    // widgets.setWindowState(Qt::WindowMaximized);//最大化

    //widgets.resize(QSize(1000,400));//设置窗体大小,宽,高
    widgets.resize(400,1000);

    //widgets.move(QPoint(0,0));//移动窗体,x坐标,y坐标
    widgets.move(50,60);

    qDebug()<<"widgets.x坐标" <<widgets.x() //获取x坐标
           <<"widgets.y坐标" <<widgets.y() //获取y坐标
          <<"\n宽:" <<widgets.width() //获取宽
         <<"高:"<<widgets.height() //获取高
        <<"当前部件的几何信息:"<<widgets.geometry();//获取当前部件的几何信息
    widgets.show();

    QWidget widgets1(0,Qt::FramelessWindowHint | Qt::Dialog);//无边框|对话框
    widgets1.setWindowTitle("widget无边框窗体");//设置标题
    widgets1.show();

    return app.exec();
}
