#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

//消息框
class MessageBox : public QDialog
{
    Q_OBJECT
public:
    MessageBox(QWidget* parent);

private slots:
    void ShowIssueDialog();
    void ShowMessageDialog();
    void ShowNoticeDialog();
    void ShowErrorDialog();
    void ShowQtDialog();
    void ShowCustomDialog();
    void ShowAboutDialog();

private:
    QLabel*  m_hintLabel;//提示

    QPushButton* m_issueBtn;//问题
    QPushButton* m_messageBtn;//信息
    QPushButton* m_noticeBtn;//警告
    QPushButton* m_errorBtn;//错误
    QPushButton* m_QtBtn;//Qt的
    QPushButton* m_aboutBtn;//关于

    QLabel*  m_customLabel;//自定义标签
    QPushButton* m_customBtn;//自定义消息框显示

    QGridLayout* m_mainLayout;//布局管理器
};

#endif // MESSAGEBOX_H
