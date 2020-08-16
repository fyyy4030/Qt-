#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

//输入对话框
class InputDialog : public QDialog
{
    Q_OBJECT
public:
    InputDialog(QWidget* parent=0);

private slots:
    void eidtName();
    void eidtSex();
    void eidtAge();
    void eidtScore();
private:
    QLabel* m_nameTitle;//姓名
    QLabel* m_sexTitle;//性别
    QLabel* m_ageTitle;//年龄
    QLabel* m_scoreTitle;//分数

    QLabel* m_nameLabel;
    QLabel* m_sexLabel;
    QLabel* m_ageLabel;
    QLabel* m_scoreLabel;

    QPushButton* m_nameBtn;
    QPushButton* m_sexBtn;
    QPushButton* m_ageBtn;
    QPushButton* m_scoreBtn;

    QGridLayout* m_mainLayout;//布局管理器

};

#endif // INPUTDIALOG_H
