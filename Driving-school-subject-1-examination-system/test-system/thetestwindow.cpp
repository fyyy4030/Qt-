#include "thetestwindow.h"
#include <QFile> //文件流
#include <QTextStream>  //字符串 //转换格式
#include <QMessageBox> //信息框
#include <QApplication> //此应用全局变量的
#include <QPushButton> //按钮
#include <QButtonGroup> //按钮分组
#include <QObject> //信号与槽

//自适应的文本

TheTestWindow::TheTestWindow(QWidget *parent):QDialog(parent)
{
    //设置字体
    QFont font;
    font.setPointSize(12);
    setFont(font);

    //设置窗体背景颜色
    setPalette(QPalette(QColor(209,215,255)));

    setWindowTitle("考试以用时: 0分0秒");//设置窗口标题
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);//普通对话框 | 取消？
    this->resize(500,600);//设置窗体大小
    initTimer();
    initLayout();
    if(!initTextEdit()){
        QMessageBox::information(this,"提示","初始化题库数据文件失败!");
        //发送信号(间隔秒,当前应用程序全局变量,退出槽函数)
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }

    initButtons();
    show();//显示出来
}

void TheTestWindow::initTimer()
{
    m_timeGo=0;
    m_timer=new QTimer(this);
    m_timer->setInterval(1000);//1秒刷新一次
    m_timer->start();//计时器的启动与操作

    //将信号与槽联系起来(信号的对象,定时器发送信号,当前窗口响应,响应的槽方法)
    connect(m_timer,SIGNAL(timeout()),this,SLOT(freshTime()));
}

void TheTestWindow::initLayout()
{
    m_layout=new QGridLayout(this);

    m_layout->setSpacing(10);//调用布局管理器 //设置控件间的间距
    m_layout->setMargin(10);//设置窗体与控件的间隙
}

bool TheTestWindow::initTextEdit()
{
    QString strLin;//保存文件中读取到的一行数据
    QStringList strList;//保存读取到的答案
    QString filename("exam.txt");//文件路径
    QFile file(filename);//操作文件
    QTextStream stream(&file);//文本文件流
    stream.setCodec("UTF-8");//指定编码

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){//只读|纯文本
        m_textEdit=new QTextEdit(this);
        m_textEdit->setReadOnly(true);//设置只读 //下标无法定位也无法编辑文本

        QString strText;//用于保存显示到文本编辑器的数据
        int nLines=0;//第几行 //行号
        while(!stream.atEnd()){

            if(nLines==0)//过滤首行
            {
                stream.readLine();
                nLines++;
                continue;
            }

            if((nLines >= 6 && nLines <= (6*9) && (nLines % 6) ==0)
                    ||nLines ==(6*9+4) )//选择题范围,判断题范围 //过滤答案行
            {
                strLin = stream.readLine();//将答案行保存
                strList = strLin.split(" ");//将 答案 ACB 分别存储
                m_answerList.append(strList.at(1));//提取答案 //AB
                strText += "\n";
                nLines++;
                continue;
            }

            strText += stream.readLine();//读取一行,累加到strText
            strText += "\n";
            nLines++;//行号++
        }
        m_textEdit->setText(strText);//显示
        //布局管理文本编辑器(文本编辑器对象,行(开始),列(开始),行宽,列宽);//行宽:占据多少行
        m_layout->addWidget(m_textEdit,0,0,1,10);//行(开始):布局管理的第几行
        //布局管理器的行宽设置一次后,不用设置多次
        file.close();
        return true;
    }else{
        return false;
    }
}

void TheTestWindow::initButtons()
{
    QStringList strList={"A","B","C","D"};
    for(int i=0;i<10;i++)
    {
        //标题标签
        m_titleLabels[i]=new QLabel(this);
        m_titleLabels[i]->setText("第"+QString::number(i+1)+"题");
        m_layout->addWidget(m_titleLabels[i],1,i);

        //按钮及判断题布局

        //判断题
        if(i==9)
        {
            m_radioA=new QRadioButton(this);//判断题A按钮
            m_radioA->setText("正确");
            m_radioB=new QRadioButton(this);//判断题B按钮
            m_radioB->setText("错误");
            m_layout->addWidget(m_radioA,2,9);
            m_layout->addWidget(m_radioB,3,9);
            m_btnGroup[8]=new QButtonGroup(this);//作为当前窗口的副窗口
            m_btnGroup[8]->addButton(m_radioA);//按钮分组添加按钮
            m_btnGroup[8]->addButton(m_radioB);
            break;
        }

        if(i<8)m_btnGroup[i]=new QButtonGroup(this);

        //选择题
        for(int j=0;j<4;j++)
        {
            //多选题
            if(i==8)
            {
                m_checkBtns[j]=new QCheckBox(this);
                m_checkBtns[j]->setText(strList.at(j));
                m_layout->addWidget(m_checkBtns[j],2+j,8);
            }
            else
            {
                //单选题
                m_radioBtns[4*i+j]=new QRadioButton(this);
                m_radioBtns[4*i+j]->setText(strList.at(j));
                m_layout->addWidget(m_radioBtns[4*i+j],2+j,i);
                m_btnGroup[i]->addButton(m_radioBtns[4*i+j]);
            }

        }
    }

    //提交按钮
    QPushButton *submitBtn=new QPushButton(this);
    submitBtn->setText("提交");
    submitBtn->setFixedSize(100,35);//设置此按钮大小

    //将信号与槽联系起来(信号的对象,点击了就发送信号,当前窗口响应,响应的槽方法)
    connect(submitBtn,SIGNAL(clicked(bool)),this,SLOT(getScore()));
    m_layout->addWidget(submitBtn,5,9,6,1);
}

bool TheTestWindow::hasNoSelect()
{
    int radioSelects=0;//单选计数
    for(int i=0;i<8;i++){
        if(m_btnGroup[i]->checkedButton())
            radioSelects++;//单选按钮被选上
    }
    if(radioSelects != 8)return true;

    int checkSelects=0;//多选计数
    for(int i=0;i<4;i++){
        if(m_checkBtns[i]->isChecked())
            checkSelects++;//多选按钮被选上
    }
    if(checkSelects<=1)return true;

    if(!m_radioA->isChecked() && !m_radioB->isChecked())return true;

        return false;
}

void TheTestWindow::freshTime()
{
    //刷新考试用时
    m_timeGo++;
    QString min = QString::number(m_timeGo / 60);//讲int结果转string //分
    QString sec = QString::number(m_timeGo % 60);//秒
    setWindowTitle("考试以用时: "+min+"分"+sec+"秒");//设置窗口标题
}

void TheTestWindow::getScore()
{
    if(hasNoSelect()){//未完成考试
        QMessageBox::information(this,"提示","您有未完成的题目,请完成考试","是");//默认按钮"是"
        return;
    }

    int scores=0;//分数
    for(int i=0;i<10;i++){
        if(i<8){//单选
            //提取按钮分组所选中的按钮文本 ==链表中的答案
            if(m_btnGroup[i]->checkedButton()->text()==m_answerList.at(i))
                scores+=10;
        }

        if(i==8){//多选
            QString answer=m_answerList.at(i);
            bool has[4];
            has[0]=answer.contains("A");//字符串里有包含A就返回true
            has[1]=answer.contains("B");
            has[2]=answer.contains("C");
            has[3]=answer.contains("D");

            bool check[4];
            check[0]=m_checkBtns[0]->checkState();//多选按钮有没被选中,被选中返回true
            check[1]=m_checkBtns[1]->checkState();
            check[2]=m_checkBtns[2]->checkState();
            check[3]=m_checkBtns[3]->checkState();
            for(int j=0;j<4;j++){
                if(has[j] != check[j])continue;
            }
            scores+=10;
        }

        if(i==9){//判断题
            if(m_btnGroup[8]->checkedButton()->text()==m_answerList.at(i))
                scores+=10;
        }
    }

    QString str="您的成绩是"+QString::number(scores)+"分 ,是否重新考试?";
    int res = QMessageBox::information(this,"提示",str,QMessageBox::Yes | QMessageBox::No);
    if(res==QMessageBox::Yes)
        return;//返回重考
    else
        close();//关闭窗口部件
}
