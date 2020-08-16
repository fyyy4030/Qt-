#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QTextEdit> //文本编辑器
#include <QCloseEvent> //关闭系列
#include <QMessageBox>
#include  <QtWidgets>

//子窗口
class childWindow : public QTextEdit
{
    Q_OBJECT
public:
    childWindow();

    QString m_CurDocpath;//当前文档路径
    void newDoc();//新建文档
    QString getCurDocName();//文档路径中提取文档名
    bool loadDoc(const QString& docName);//加载文档
    void setCurDoc(const QString& docName);//修改子窗口标题,标识等
    bool SaveDocument();//判断m_bSaved从而操作以下哪种函数
    bool SaveAS();//另存为
    bool SaveDoc(QString &docName);//保存文档

    void setFormatOnSelectedWord(const QTextCharFormat &fmt);//设置选中格式

    void setAlignOfDocumentText(int aligntype);//设置文本段落

    void setParaSyle(int pStyle);//设置风格
protected:
    void closeEvent(QCloseEvent *event);//关闭事件
private:
    bool promptSave();//是否保存提示框

private slots:
    void docBeModified();//文档修改时,窗口标题栏加'*'

private:
    bool m_bSaved;//文档是否保存;
};

#endif // CHILDWINDOW_H
