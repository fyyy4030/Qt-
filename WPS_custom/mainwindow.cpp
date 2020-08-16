#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "childwindow.h"
#include <QMdiSubWindow>
#include <QFileDialog> //文档
#include <QColorDialog> //颜色

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();

}

void MainWindow::initMainWindow()
{
    //初始化字号列表项
    QFontDatabase fontdb;
    foreach (int fonsize,fontdb.standardSizes()) {//.standardSizes()返回的是标准字号
        ui->comboBox_2->addItem(QString::number(fonsize));//将下拉框列表初始化
    }

    //获取当前应用程序的字号
    QFont defont;//当前应用默认的字体
    QString sfontsize;//当前字体的大小
    int defontsize;//当前应用默认字体的字号
    int defontindex;//当前字号在(comboBox_2字号)组合框中的索引号

    defont=QApplication::font();//获取到当前应用字体信息
    defontsize=defont.pointSize();//获取字体的字号(大小)
    sfontsize=QString::number(defontsize);//获取到字符串类型的字号
    defontindex=ui->comboBox_2->findText(sfontsize);//传值和下拉框的文本匹配,返回下拉框的索引位置

    ui->comboBox_2->setCurrentIndex(defontindex);//将索引号设为选中(默认)

    //设置多文档区域滚动条
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);//设置滚动条ScrollBarAsNeeded隐藏
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);//设置垂直

    //更新菜单部件是否可用
    refreshMenus();//刷新菜单项
    //多文档区域发射信号,有活动子窗口发射的信号,响应对象,响应的槽方法
    connect(ui->mdiArea,&QMdiArea::subWindowActivated,this,&MainWindow::refreshMenus);

    //更新窗口菜单
    //窗体菜单部件,发射马上要将菜单显示,响应的窗口,响应的槽方法
    addSubWindowListMenu();
    connect(ui->menu_W,&QMenu::aboutToShow,this,&MainWindow::addSubWindowListMenu);

    //将ui->窗体 部件的下拉项操作子窗口光标移动:
    m_WndMapper = new QSignalMapper(this);//信号映射器
    connect(m_WndMapper,SIGNAL(mapped(QWidget*)),this,SLOT(setActiveSubWindow(QWidget*)));

    //对于段落对齐要让它们拥有互斥性,一次只能选择一种使用,将它们添加到同一分组即可
    //功能组
    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ui->action_L);//增加功能(左对齐)
    alignGroup->addAction(ui->action_C_3);//居中
    alignGroup->addAction(ui->action_R_2);//右对齐
    alignGroup->addAction(ui->action_J);//两端对齐

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::docNew()
{
    childWindow *childwnd=new childWindow;
    ui->mdiArea->addSubWindow(childwnd);//在此窗口中添加子窗口部件

    //子窗口,复制信号是否能用,(剪切动作[剪切部件])响应的槽对象,响应的槽方法
    //connect(childwnd,SIGNAL(copyAvailable(bool)),ui->action_T,SLOT(setEnabled(bool)));

    //子窗口,复制信号是否能用,(界面的复制部件)响应的槽对象,响应的槽方法
    //connect(childwnd,SIGNAL(copyAvailable(bool)),ui->action_C,SLOT(setEnabled(bool)));

    childwnd->newDoc();//新建文档
    childwnd->show();//显示文档ui

    //文档建立,那么文字倾斜,加粗,字体,大小等应能用  实现:
    formatEnabled();



}

void MainWindow::docOpen()
{
    //获取文件名
    QString docName = QFileDialog::getOpenFileName(this,
                                                   "打开文档",//标题
                                                   "",//默认打开文档
                                                   "文本文件(*.txt);;"  //过滤条件
                                                   "(*.HTML *.HTM);;"
                                                   "所有文件(*.*)");

    //判断是否已打开文件
    if(!docName.isEmpty()){//文档不为空
        QMdiSubWindow *existWnd = findChildWnd(docName);//文档有无已经打开
        if(existWnd){//文档已打开 //接收到了子窗口对象
            ui->mdiArea->setActiveSubWindow(existWnd);//将接收子窗口为活动的
            return;
        }

        //如果不存在
        childWindow *childWnd=new childWindow;//新建子窗口
        ui->mdiArea->addSubWindow(childWnd);//将新建子窗口添加至多文档区域
        //更新剪切和复制部件为可用
        connect(childWnd,SIGNAL(copyAvailable(bool)),ui->action_T,SLOT(setEnabled(bool)));
        connect(childWnd,SIGNAL(copyAvailable(bool)),ui->action_C,SLOT(setEnabled(bool)));

        if(childWnd->loadDoc(docName)){//加载文档成功
            statusBar()->showMessage("文档已打开",3000);//设置状态栏
            childWnd->show();//显示子窗口
            formatEnabled();//刷新菜单项
        }else{//文档加载失败
            childWnd->close();//将其关闭
        }
    }
}

void MainWindow::docSave()
{
    //活动的子窗口 && 保存文档成功
    if(activateChildWindow() && activateChildWindow()->SaveDocument()){
        statusBar()->showMessage("保存成功",3000);//标题提示
    }
}

void MainWindow::docSaceAS()
{
    //活动的子窗口 && 另存为文档保存成功
    if(activateChildWindow() && activateChildWindow()->SaveAS()){
        statusBar()->showMessage("保存成功",3000);//标题提示
    }
}

void MainWindow::docUndo()
{
    if(activateChildWindow()){//活动的子窗口
        activateChildWindow()->undo();//调用撤销功能
    }
}

void MainWindow::docRedo()
{
    if(activateChildWindow()){//活动的子窗口
        activateChildWindow()->redo();//调用不撤销功能
    }
}

void MainWindow::docCut()
{
    if(activateChildWindow()){//活动的子窗口
        activateChildWindow()->cut();//调用剪切功能
    }
}

void MainWindow::docCopy()
{
    if(activateChildWindow()){//活动的子窗口
        activateChildWindow()->copy();//调用复制功能
    }
}

void MainWindow::docPaste()
{
    if(activateChildWindow()){//活动的子窗口
        activateChildWindow()->paste();//调用粘贴功能
    }
}

void MainWindow::textBold()
{
    QTextCharFormat fmt;

    //设置是否加粗字体格式(是否选中ui->加粗部件 ? 是就加粗 : 不是就正常)
    fmt.setFontWeight(ui->action_B->isChecked() ? QFont::Bold : QFont::Normal);

    //是活动的子窗口就传入设置好的格式,将选中文本操作
    if(activateChildWindow())
        activateChildWindow()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;

    //设置是否倾斜字体格式(是否选中ui->倾斜部件)
    fmt.setFontItalic(ui->action_I->isChecked());

    if(activateChildWindow())
        activateChildWindow()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;

    //设置字体格式(是否选中ui->下划线部件)
    fmt.setFontUnderline(ui->action_U_2->isChecked());

    if(activateChildWindow())
        activateChildWindow()->setFormatOnSelectedWord(fmt);
}

void MainWindow::textFamily(const QString &fmly)
{
    QTextCharFormat fmt;//文本字符格式
    fmt.setFontFamily(fmly);//设置字体格式
    if(activateChildWindow()){
        //活动的子窗口->设置格式在选择单词(格式)
        activateChildWindow()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textSize(const QString &ps)
{
    //double
    qreal pointSize = ps.toFloat();

    if(pointSize > 0){
        QTextCharFormat fmt;
        //设置字体表明大小(大小值)
        fmt.setFontPointSize(pointSize);
        if(activateChildWindow()){
            activateChildWindow()->setFormatOnSelectedWord(fmt);
        }
    }
}

void MainWindow::textColor()
{
    if(activateChildWindow()){
        //活动子窗口
        //颜色对话框::获取颜色(当前窗口颜色,当前窗口)
        QColor color = QColorDialog::getColor(activateChildWindow()->textColor(),this);
        if(!color.isValid()) return;//颜色不合法
        QTextCharFormat fmt;//文本字符格式
        fmt.setForeground(color);//设置前景颜色
        activateChildWindow()->setFormatOnSelectedWord(fmt);//设置格式在选择单词

        //将当前ui->颜色部件 进行修改,使用当前所选颜色填充
        QPixmap pix(16,16);//绘制一个,16.16的图
        pix.fill(color);//填充
        ui->action_C_2->setIcon(pix);//设置图标
    }
}

void MainWindow::paraStyle(int nStyle)
{
    if(activateChildWindow())//活动的子窗口
        activateChildWindow()->setParaSyle(nStyle);
}

void MainWindow::docPrint()
{
    //打印机(像素::采用打印机的像素)
    QPrinter pter(QPrinter::HighResolution);

    //打印的对话框显示出来
    QPrintDialog *ddlg = new QPrintDialog(&pter,this);
    if(activateChildWindow())
        //接收用户的设置(打印对话框选择)
        ddlg->setOption(QAbstractPrintDialog::PrintSelection,true);//保留用户的设置
    ddlg->setWindowTitle("打印预览");

    childWindow *childwnd = activateChildWindow();
    //如果用户选择打印
    if(ddlg->exec() == QDialog::Accepted)
        childwnd->print(&pter);//就打印

    delete ddlg;//打印对话框删除
}

void MainWindow::docPrintPreview()
{
    //打印机
    QPrinter prter;
    QPrintPreviewDialog preview(&prter,this);//打印预览对话框
    //打印预览对话框发送请求,绘画请求,this,打印预览
    connect(&preview,SIGNAL(paintRequested(QPrinter*)),this,SLOT(printPreview(QPrinter*)));
}


void MainWindow::formatEnabled()
{
    //设置部件是否可用
    ui->action_B->setEnabled(true);//加粗部件可用
    ui->action_I->setEnabled(true);//倾斜
    ui->action_U_2->setEnabled(true);//下划线
    ui->action_L->setEnabled(true);//左对齐
    ui->action_R_2->setEnabled(true);//右对齐
    ui->action_C_3->setEnabled(true);//居中
    ui->action_J->setEnabled(true);//两端对齐
    ui->action_C_2->setEnabled(true);//颜色
}

childWindow *MainWindow::activateChildWindow()
{
    //返回多文档编辑器的子窗口
    QMdiSubWindow* actWnd = ui->mdiArea->activeSubWindow();
    if(actWnd)//对象类型转换<需转成的类型>(先转换成部件类)
        return qobject_cast<childWindow*>(actWnd->widget());
    else //没有活动的子窗口就返回0
        return 0;
}

QMdiSubWindow *MainWindow::findChildWnd(const QString &docName)
{
    //if(!docName) return -1;//传值不对
    QString strfile = QFileInfo(docName).canonicalFilePath();//文件路径

    //遍历所有子窗口
    foreach (QMdiSubWindow* subWnd, ui->mdiArea->subWindowList()) {
        childWindow* childWnd=qobject_cast<childWindow*>(subWnd->widget());//类型转换
        if(childWnd->m_CurDocpath == strfile) return subWnd;//文档已经打开 返回子窗口对象
    }
    return 0;//没有打开
}

void MainWindow::refreshMenus()
{
    bool hasChild=false;
    hasChild = (activateChildWindow() != 0);

    //部件是否可用
    ui->save_file->setEnabled(hasChild);//保存
    ui->action_A->setEnabled(hasChild);//另存为
    ui->action_P->setEnabled(hasChild);//打印
    ui->action_3->setEnabled(hasChild);//打印预览
    ui->action_P_2->setEnabled(hasChild);//粘贴
    ui->action_O->setEnabled(hasChild);//关闭
    ui->action_A_2->setEnabled(hasChild);//关闭所有
    ui->action_T_2->setEnabled(hasChild);//平铺
    ui->action_C_4->setEnabled(hasChild);//层叠
    ui->action_X->setEnabled(hasChild);//下一个RR
    ui->action_U->setEnabled(hasChild);//撤销
    ui->action_R->setEnabled(hasChild);//重做

    //判断用户有无选中文本,有就对文本操作的部件设为可用
    //有子窗口 && 返回光标信息:是否有选中内容
    bool hasSelect = (activateChildWindow() !=0 && activateChildWindow()->textCursor().hasSelection());

    ui->action_T->setEnabled(hasSelect);//剪切
    ui->action_C->setEnabled(hasSelect);//复制
    ui->action_B->setEnabled(hasSelect);//加粗
    ui->action_I->setEnabled(hasSelect);//倾斜
    ui->action_U_2->setEnabled(hasSelect);//下划线
    ui->action_L->setEnabled(hasSelect);//左对齐
    ui->action_C_3->setEnabled(hasSelect);//居中
    ui->action_R_2->setEnabled(hasSelect);//右对齐
    ui->action_J->setEnabled(hasSelect);//两端对齐
    ui->action_C_2->setEnabled(hasSelect);//颜色
}

void MainWindow::addSubWindowListMenu()//窗体菜单的菜单更新
{
    while(1){//修复每点击一次就执行菜单更新,导致信息不断重叠
        ui->menu_W->clear();//清空
        //重新添加部件
        ui->menu_W->addAction(ui->action_O);//关闭
        ui->menu_W->addAction(ui->action_A_2);//关闭所有
        ui->menu_W->addSeparator();//分割线
        ui->menu_W->addAction(ui->action_T_2);//平铺
        ui->menu_W->addAction(ui->action_C_4);//层叠
        ui->menu_W->addSeparator();
        ui->menu_W->addAction(ui->action_X);//下一个
        ui->menu_W->addAction(ui->action_V);//前一个
        break;
    }

    //获取多文档区域中的所有窗口
    QList<QMdiSubWindow*> wnds=ui->mdiArea->subWindowList();

    if(!wnds.isEmpty()) ui->menu_W->addSeparator();//有子窗口就窗口菜单加个分割线

    //将子窗口逐个提取,往窗体菜单中添加,选中给勾勾
    for(int i=0;i<wnds.size();i++){
        childWindow* childWnd = qobject_cast<childWindow*>(wnds.at(i)->widget());
        QString menuitem_text;//获取窗口名
        menuitem_text = QString("%1 %2").arg(i+1).arg(childWnd->getCurDocName());

        QAction *menuitem_act=ui->menu_W->addAction(menuitem_text);//往窗体菜单中添加 活动条(菜单选项)
        menuitem_act->setCheckable(true);//设置是否可勾勾
        menuitem_act->setChecked(childWnd == activateChildWindow());//是否选中

        //窗体下拉选项的子窗口条目,被点击发射激活信号,信号映射器接收,槽函数实现发射mapped(mapped(QWidget*))信号
        connect(menuitem_act,SIGNAL(triggered(bool)),m_WndMapper,SLOT(map()));

        //设置信号发送者所带的参数 //子窗口条目,子窗口 //任意参数都能进,自行指定
        m_WndMapper->setMapping(menuitem_act,wnds.at(i));
    }
    formatEnabled();
}

void MainWindow::on_new_file_triggered()//触发的,启动的 //当点击新建部件就会触发此槽方法
{
    docNew();
}

void MainWindow::on_action_O_triggered()//关闭当前活动的子窗口
{
    ui->mdiArea->closeActiveSubWindow();//将活动的子窗口关闭
}

void MainWindow::on_action_A_2_triggered()
{
    ui->mdiArea->closeAllSubWindows();//将所有的子窗口关闭
}

void MainWindow::on_action_T_2_triggered()
{
    ui->mdiArea->tileSubWindows();//平铺
}

void MainWindow::on_action_C_4_triggered()
{
    ui->mdiArea->cascadeSubWindows();//层叠
}

void MainWindow::on_action_X_triggered()
{
    ui->mdiArea->activateNextSubWindow();//下一个
}

void MainWindow::on_action_V_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();//前一个
}

void MainWindow::setActiveSubWindow(QWidget *wnd)//设置活动的子窗口
{
    //将部件类指针转换成子窗口类型,并设置为活动的子窗口
    if(wnd) ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(wnd));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();//将所有的子窗口关闭
    if(ui->mdiArea->currentSubWindow())//如果是子窗口的事件
        event->ignore(); //忽略此事件
    else
        event->accept(); //接收此事件
}

void MainWindow::on_open_file_triggered()
{
    docOpen();
}

void MainWindow::on_save_file_triggered()
{
    docSave();
}

void MainWindow::on_action_A_triggered()
{
    docSaceAS();
}

void MainWindow::on_action_U_triggered()
{
    docUndo();
}

void MainWindow::on_action_R_triggered()
{
    docRedo();
}

void MainWindow::on_action_T_triggered()
{
    docCut();
}

void MainWindow::on_action_C_triggered()
{
    docCopy();
}

void MainWindow::on_action_P_2_triggered()
{
    docPaste();
}

void MainWindow::on_action_B_triggered()
{
    textBold();//加粗
}

void MainWindow::on_action_I_triggered()
{
    textItalic();//倾斜
}

void MainWindow::on_action_U_2_triggered()
{
    textUnderline();//下划线
}

void MainWindow::on_fontComboBox_activated(const QString &arg1)
{
    textFamily(arg1);//设置字体
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    textSize(arg1);//设置字体大小
}

void MainWindow::on_action_L_triggered()
{
    if(activateChildWindow())
        activateChildWindow()->setAlignOfDocumentText(1);
}

void MainWindow::on_action_R_2_triggered()
{
    if(activateChildWindow())
        activateChildWindow()->setAlignOfDocumentText(2);
}

void MainWindow::on_action_C_3_triggered()
{
    if(activateChildWindow())
        activateChildWindow()->setAlignOfDocumentText(3);
}

void MainWindow::on_action_J_triggered()
{
    if(activateChildWindow())
        activateChildWindow()->setAlignOfDocumentText(4);
}

void MainWindow::on_action_C_2_triggered()
{
    textColor();
}

void MainWindow::on_comboBox_activated(int index)
{
    paraStyle(index);
}

void MainWindow::on_action_P_triggered()
{
    docPrint();
}

void MainWindow::printPreview(QPrinter *printer)
{
    activateChildWindow()->print(printer);
}

void MainWindow::on_action_3_triggered()
{
    docPrintPreview();
}
