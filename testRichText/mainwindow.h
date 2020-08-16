#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mysyntaxhighlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //遍历文档框架
    void showTextFrame();
    //遍历文本块
    void showTextBlock();
    //设置字体
    void setTextFont(bool checked);

    //表格,列表,图片
    void insertTable();//插入表格
    void insertList();//插入列表
    void insertImage();//插入图片
private:
    Ui::MainWindow *ui;
    MySyntaxHighlighter *m_sLighter;//语法高亮类
};

#endif // MAINWINDOW_H
