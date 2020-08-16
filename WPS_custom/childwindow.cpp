#include "childwindow.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocumentWriter> //文档写入
#include <QTextBlockFormat>
#include <QTextListFormat>


childWindow::childWindow()
{
    setAttribute(Qt::WA_DeleteOnClose);//子窗口关闭时销毁该类的实例对象

    m_bSaved=false;
}

void childWindow::newDoc()
{
    static int wndSeqNum = 1;//文档序号
    m_CurDocpath=QString("WPS 文档 %1").arg(wndSeqNum++);//当前文档路径

    //设置窗体标题,文档改动后,名称后面加'*'号标识
    setWindowTitle(m_CurDocpath + "[*]" + " - MyWPS");
    //当前文档,内容发生改变的信号,当前窗体对象,执行的槽函数
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(docBeModified()));

}

QString childWindow::getCurDocName()
{
    return QFileInfo(m_CurDocpath).fileName();//返回的是文件的名称
}

bool childWindow::loadDoc(const QString &docName)
{
    if(docName.isEmpty())return false;//传值为空

    QFile file(docName);
    if(!file.exists())return false;//文件不存在

    if(!file.open(QFile::ReadOnly)) return false;//文件打开不成功

    QByteArray text = file.readAll();//读取文件所有

    if(Qt::mightBeRichText(text))//判断是否是富文本
        setHtml(text);//如果是富文本直接显示
    else
        setPlainText(text);//当纯文本显示

    setCurDoc(docName);

    //当前文档,内容改变信号,this,改变修改状态(true)
    //改变修改状态后,程序继续运行那么就会窗口标题后面加*
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(docBeModified()));
    return true;

}

void childWindow::setCurDoc(const QString &docName)
{
    if(docName.isEmpty())return;//传值为空

    //canonicalFilePath()可以去除'.',".." ,返回标准路径名称
    m_CurDocpath = QFileInfo(docName).canonicalFilePath();

    m_bSaved = true;//文档已被保存过

    document()->setModified(false);//当前文档->修改状态(未改动)
    setWindowModified(false);//窗体的改动标识(不进行显示)
    setWindowTitle(getCurDocName() + "[*]");//设置子窗体标题文本

}

bool childWindow::SaveDocument()
{
    if(m_bSaved) return SaveDoc(m_CurDocpath);//已经保存过了就保存在现有路径
    else return SaveAS();//没有保存过就另存为
}

bool childWindow::SaveAS()
{
    //文件对话框::获取保存文件名字(this,标题,路径,文档格式)
    QString docname = QFileDialog::getSaveFileName(this,"另存为...",m_CurDocpath
                                                   ,"HTML文档 (*.htm *.html);; 所有文件(*.*)");

    if(docname.isEmpty())
        return false;//文档为空
    else
        return SaveDoc(docname);//将文档保存在用户想要保存的地方
}

bool childWindow::SaveDoc(QString &docName)
{
    //判断文档是否""结尾,大小写不敏感
    if(!(docName.endsWith(".htm",Qt::CaseInsensitive) || docName.endsWith(".html",Qt::CaseInsensitive))){
        docName += ".html";//默认保存文档设置成功为.html格式
    }

    QTextDocumentWriter writer(docName);
    bool is = writer.write(this->document());//写(当前文档)
    if(is)
        setCurDoc(docName);//设置子窗体状态
    return is;
}

void childWindow:: setFormatOnSelectedWord(const QTextCharFormat &fmt)
{
    //获取当前文档光标
    QTextCursor tcursor = textCursor();

    //光标是否选中文本; 没选中就进行选中操作(选中范围在光标范围区域内);
    if(!tcursor.hasSelection()) tcursor.select(QTextCursor::WordUnderCursor);

    //已经选中,进行文本合并格式
    tcursor.mergeCharFormat(fmt);
    //将已进行的文本格式合并到当前文本里
    mergeCurrentCharFormat(fmt);
}

void childWindow::setAlignOfDocumentText(int aligntype)
{
    if(aligntype == 1)
        setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);//设置队列(左行 | 绝对的队列)
    else if(aligntype == 2)
        setAlignment(Qt::AlignRight | Qt::AlignAbsolute);//右对齐
    else if(aligntype == 3)
        setAlignment(Qt::AlignHCenter | Qt::AlignAbsolute);//居中对齐
    else if(aligntype == 4)
        setAlignment(Qt::AlignJustify | Qt::AlignAbsolute);//两端对齐
}

void childWindow::setParaSyle(int pStyle)
{
    QTextCursor tcuisor = textCursor();//获取光标信息
    //文本链表格式::样式
    QTextListFormat::Style sname;
    if(pStyle != 0){
        switch(pStyle){
        case 1:
            sname = QTextListFormat::ListDisc;//黑心实心圆
            break;
        case 2:
            sname = QTextListFormat::ListCircle;//空心圆
            break;
        case 3:
            sname=QTextListFormat::ListSquare;//方型
            break;
        case 4:
            sname=QTextListFormat::ListDecimal;//十进制整数
            break;
        case 5:
            sname=QTextListFormat::ListLowerAlpha;//小写字母
            break;
        case 6:
            sname=QTextListFormat::ListUpperAlpha;//大写字母
            break;
        case 7:
            sname=QTextListFormat::ListLowerRoman;//小写罗马字母
            break;
        case 8:
            sname=QTextListFormat::ListUpperRoman;//大写罗马字母
            break;
        default:
            sname = QTextListFormat::ListDisc;//数字前缀
        }//获取到格式符

        //编辑文本块
        tcuisor.beginEditBlock();

        //文本块格式
        QTextBlockFormat tBlockfmt = tcuisor.blockFormat();

        //链表格式
        QTextListFormat tListfmt;
        if(tcuisor.currentList()){//是否有链表
            tListfmt = tcuisor.currentList()->format();//进行链表格式设置
        }else{
            tListfmt.setIndent(tBlockfmt.indent()+1);//设置缩进,此单位是tap的宽度//将留出格式符位置
            tBlockfmt.setIndent(0);//不进行缩进
            tcuisor.setBlockFormat(tBlockfmt);//设置块的格式
        }

        //设置链表格式风格
        tListfmt.setStyle(sname);
        tcuisor.createList(tListfmt);//文本块创建一个链表

        tcuisor.endEditBlock();//编辑结束
    }else{
        QTextBlockFormat tbfmt;
        tbfmt.setObjectIndex(-1);//无效格式
        tcuisor.mergeBlockFormat(tbfmt);
    }
}

void childWindow::closeEvent(QCloseEvent *event)
{
    if(promptSave()){
        event->accept();
    }else{
        event->ignore();
    }
}


bool childWindow:: promptSave()
{
    if(!document()->isModified()) return true;

    //文档修改
    QMessageBox::StandardButton result = QMessageBox::warning(this,"系统提示"
                                                              ,QString("文档%1已修改,是否保存?").arg(getCurDocName())
                                                              ,QMessageBox::Yes |
                                                              QMessageBox::Discard //忽略
                                                              | QMessageBox::No);

    if(result == QMessageBox::Yes)
        return SaveDocument();
    else if(result == QMessageBox::No)
        return false;

    return true;

}
void childWindow::docBeModified()
{
    setWindowModified(document()->isModified());//设置窗体是否被修改(是否被编辑)
}
