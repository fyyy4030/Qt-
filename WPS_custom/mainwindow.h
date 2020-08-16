#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "childWindow.h"
#include <QCloseEvent>
#include <QSignalMapper>
#include <QMdiSubWindow>
#include <QtPrintSupport/QPrinter> //打印机
#include <QtPrintSupport/QPrintDialog> //打印对话框
#include <QtPrintSupport/QPrintPreviewDialog> //打印预览对话框

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initMainWindow();//初始化字号列表项
    ~MainWindow();
    void docNew();//新建文档
    void docOpen();//打开文档
    void docSave();//保存文档
    void docSaceAS();//另存为

    void docUndo();//撤销
    void docRedo();//不撤销
    void docCut();//剪切
    void docCopy();//复制
    void docPaste();//粘贴

    void textBold();//加粗
    void textItalic();//倾斜
    void textUnderline();//下划线

    void textFamily(const QString &fmly);//文本字体(字体)
    void textSize(const QString &ps);//字体大小

    void textColor();//文本颜色

    void paraStyle(int nStyle);//风格

    void docPrint();//文档打印
    void docPrintPreview();//打印预览
private slots:
    void on_new_file_triggered();//新建文档的槽方法
    void refreshMenus();//刷新菜单
    void addSubWindowListMenu();//窗体菜单的菜单更新

    void on_action_O_triggered();

    void on_action_A_2_triggered();

    void on_action_T_2_triggered();

    void on_action_C_4_triggered();

    void on_action_X_triggered();

    void on_action_V_triggered();

    void setActiveSubWindow(QWidget* wnd);

    void on_open_file_triggered();

    void on_save_file_triggered();

    void on_action_A_triggered();

    void on_action_U_triggered();

    void on_action_R_triggered();

    void on_action_T_triggered();

    void on_action_C_triggered();

    void on_action_P_2_triggered();

    void on_action_B_triggered();

    void on_action_I_triggered();

    void on_action_U_2_triggered();

    void on_fontComboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_action_L_triggered();

    void on_action_R_2_triggered();

    void on_action_C_3_triggered();

    void on_action_J_triggered();

    void on_action_C_2_triggered();

    void on_comboBox_activated(int index);

    void on_action_P_triggered();

    void printPreview(QPrinter* printer);//打印预览
    void on_action_3_triggered();

protected:
    void closeEvent(QCloseEvent *event);//重写关闭所有子窗口事件

private:
    void formatEnabled();//功能启动
    childWindow* activateChildWindow();//活动的子窗口
    QMdiSubWindow* findChildWnd(const QString& docName);//查找子窗口中文档是否已打开
private:
    Ui::MainWindow *ui;

    //当想要对一样的信号执行不一样的操作时,可使用信号映射器
    QSignalMapper* m_WndMapper;//信号映射器
};

#endif // MAINWINDOW_H
