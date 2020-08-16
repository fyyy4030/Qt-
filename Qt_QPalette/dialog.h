#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>//框架
#include <QLabel>//标签
#include <QComboBox>//组合框
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void createCtrlFrame();
    void fillColorList(QComboBox * comboBox);//给组合框添加颜色列表

    void createContentFrame();

public slots:
    void ShowWindow(int index);
    void ShowWindowText(int index);
    void ShowButton(int index);
    void ShowButtonText(int index);
    void ShowBase(int index);

private:
    QFrame *m_ctrFrame;
    QLabel *m_windowLabel;
    QComboBox *m_windowComboBox;
    QLabel *m_windowTextLabel;
    QComboBox *m_windowTextComboBox;
    QLabel *m_buttonLabel;
    QComboBox *m_buttonCombox;
    QLabel *m_buttonTextLabel;
    QComboBox *m_buttonTextComboBox;
    QLabel *m_baseLabel;
    QComboBox *m_baseComboBox;
    QFrame *m_contentFrame;
    QLabel *m_label1;
    QLabel *m_label2;
    QComboBox *m_combobox1;
    QLineEdit *m_lineEdit;
    QTextEdit *m_textEdit;
    QPushButton *m_okBtn;
    QPushButton *m_cancelBtn;
};
#endif // DIALOG_H
