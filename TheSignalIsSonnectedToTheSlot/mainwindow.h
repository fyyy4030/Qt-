#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals://信号,信的返回值都是void
    void Comeon(QString& str);//信号不能也无需实现 //可以多信号连接一个槽

private slots://槽
    void on_zhbtn_clicked();

    void on_szbtn_clicked();

    void on_gzbtn_clicked();//on_对象名_信号名 //自动连接的

    void ComenGuys(QString& str);//这个槽方法响应的是Comeon这个信号 //槽和信号响应的类型必须是一样的

    void ComenGuy();//参数列表不一致会导致连接失败,参数列表可以比信号参数列表少但不可以多

    void ComenG();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
