#include "logindialog.h"
#include <thetestwindow.h>

#include <QApplication>


int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0)){//进行版本比较
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        //文档中有解释,主要将像素同步
    }
    /*QT预览界面和运行界面不一致:
1.pyqt5
if __name__=="__main__":
    #增加下面的一个代码
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QApplication(sys.argv)
    d=D()
    d.show()
    sys.exit(app.exec())

2.QT c++
int main(int argc, char *argv[])
{
    #增加下面的一个代码
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
!!!注意:如果没有设计模式的窗体,就会无法生成.exe文件,从而造成"发生未经处理的win32"
*/

    QApplication a(argc, argv);//应用程序对象

    LoginDialog w;//登陆窗口对象
    //w.show();//可视化功能
    int res=w.exec();
    if(res==QDialog::Accepted){
        TheTestWindow *E;
        E=new TheTestWindow;

        //return a.exec();
    }else{
        return 0;
    }

    //    TheTestWindow E;
    //    E.show();
    return a.exec();//使当前应用程序消息循环
    //和用户交互使用 //返回此函数
    /* .exec():
如果这个对话框是程序模式，用户不能在同一个应用程序里访问其它窗口，除非
我们把这个对话框关闭;
如果这个对话框是窗口模式，只要这个对话框是处于打开状态的，它就不能和父
窗口进行通信;
注意：避免使用此功能；而是使用open()。与exec（）不同，open（）是异步的，
并且不会旋转其他事件循环。这样可以防止发生一系列危险的错误
（例如，在通过exec（）打开对话框时删除对话框的父级）。
当使用开放式（），您可以连接到完成的（）信号QDialog的时候被关闭对话框通知
*/
}
