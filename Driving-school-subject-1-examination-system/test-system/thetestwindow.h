#ifndef THETESTWINDOW_H
#define THETESTWINDOW_H
#include <QDialog>  //对话框
#include <QTimer>   //时间
#include <QTextEdit>  //文本编辑器
#include <QLabel>  //标签
#include <QRadioButton>  //单选按钮
#include <QCheckBox>  //多选按钮
#include <QGridLayout> //管理布局  //布局管理器



class TheTestWindow : public QDialog
{
  Q_OBJECT
public:
    TheTestWindow(QWidget* parent=0);//初始化父类,如果没有参数就成为顶级窗口
    void initTimer();//对计时器和考试用时初始化
    void initLayout();//初始化布局管理器
    bool initTextEdit();//初始化文本编辑器
    void initButtons();//初始化按钮及标签
    bool hasNoSelect();//判断题目是否全部完成 //有没选择 //true:未全完成
private:

    QTimer *m_timer;//计时器
    int m_timeGo;//考试以用时

    //控件
    QTextEdit *m_textEdit;//考试题库显示 //文本编辑器
    QLabel *m_titleLabels[10];//题目标签
    QRadioButton *m_radioBtns[32];//单选题按钮
    QCheckBox *m_checkBtns[4];//多选题按钮
    QRadioButton *m_radioA;//判断题A选项
    QRadioButton *m_radioB;//判断题B选项

    QGridLayout *m_layout;//布局管理器

    QStringList m_answerList;//答案的链表
    QButtonGroup *m_btnGroup[9];//按钮分组 //因为9个单选被编译归类为只有一个答案 //多选不影响
private slots://私有的槽方法
    void freshTime();//刷新时间
    void getScore(); //获取考试成绩
};

#endif // THETESTWINDOW_H
