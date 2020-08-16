#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "inputdialog.h"
#include "messagebox.h"

//对话框
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots://槽
    void ShowFileDialog();
    void ShowColorDialog();
    void ShowFontDialog();
    void ShowInputDialog();
    void ShowMessageBoxDialog();
private:
    QPushButton* m_fileBtn;//打开文件对话框的按钮
    QLineEdit* m_fileEdit;//显示所选文件路径 //行编辑器

    QGridLayout* m_mainLayout;//主布局管理器

    QPushButton* m_colorBtn;//打开颜色对话框
    QFrame* m_colorFrame;//用户所选效果

    QPushButton* m_fontBtn;//打开字体对话框
    QLineEdit* m_fontEdit;//显示所选字体效果

    QPushButton* m_inputBtn;//显示输入对话框
    InputDialog* m_inputDialog;//输入对话框

    QPushButton* m_messageBtn;//显示消息对话框
    MessageBox* m_messageBox;//消息框
};

#endif // DIALOG_H
