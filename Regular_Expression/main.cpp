#include <QCoreApplication>
#include <QDebug>
#include <QRegularExpression>

//正则表达式
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    while(1){//正则表达式
        while(0){//QRegExp
            QRegExp reg("ab");
            qDebug()<<"匹配字符本身:"<<reg.exactMatch("abc") //精准匹配()
                   <<reg.exactMatch("ab");

            // \d匹配任意一个数字  *任意多个  \D匹配一个非数字 {}自定义匹配个数
            QRegExp reg1("(\\d*\\D{2})");//()集合
            qDebug()<<"\n匹配数字:"<<reg1.exactMatch("185cm")
                   <<reg1.exactMatch("152m")
                  <<reg1.exactMatch("72in");

            //通配符
            QRegExp reg2("*.txt");//匹配任何txt文件
            reg2.setPatternSyntax(QRegExp::Wildcard);//设置匹配语法(支持通配符)
            qDebug()<<"通配符匹配:"<<reg2.exactMatch("lanFgsdn.txt")
                   <<reg.exactMatch("sfsdf.txt.bak");

            //匹配单词边界
            QRegExp reg3;
            reg3.setPattern("\\b(Hello|hello)\\b");//匹配模式((字符串的集合)) \b:匹配的位置
            qDebug()<<"\n匹配多个单词:"<<reg3.indexIn("helloEveryone!") //-1 失败
                   <<reg3.indexIn("Hmm hello everyone!") //4 匹配到当前位置
                  <<reg3.indexIn("Hi girls! Hello boys!");//匹配到哪个单词不知道,往下

            //捕获匹配的文本
            //由 "(?:" 开始 , ")" 结束 ,非捕获()语法
            QRegExp regHeight("(\\d+)(?:\\s*)(cm|inch)");
            int res = regHeight.indexIn("姚明 226 cm");//位置
            if(res > -1){
                qDebug()<<"文本捕获:\ncap(0):"<<regHeight.cap(0) //完整捕获
                       <<"\ncap(1):"<<regHeight.cap(1) //捕获的第一个单词
                      <<"\ncap(2):"<<regHeight.cap(2);//捕获的第二个单词
            }

            //断言 ?! 不紧跟才匹配 , ?= 紧跟才匹配
            QRegExp reg4;
            reg4.setPattern("面(?!包)");//你的 面 后面不能是 包
            QString s="面没了,吃面包也好吃,吃面食物也可以.";
            qDebug()<<"替换前:"<<s<<endl;
            s.replace(reg4,"意大利");//替换指定的正则表达式
            qDebug()<<"替换后:"<<s<<endl;//符合正则表达式的面替换成了意大利
            break;
        }

        while(1){//QRegularExpression
            //QT5引用了新的类 正则表达式类
            QRegularExpression regExp("hello");
            qDebug()<<"QRegularExpression 匹配字符:"<<regExp.match("hello world!");

            regExp.setPattern("[A-Z]{3,8}");//设置匹配模式
            //regExp.setPatternOptions(QRegularExpression::CaseInsensitiveOption);//设置模式选项 //大小写不敏感

            qDebug()<<"大小写不敏感匹配:"<<regExp.match("helloo")<<endl;

            //捕获 //^开始 $结束
            QRegularExpression regExp1("^(\\d\\d)/(\\d\\d)/(\\d\\d\\d\\d)$");

            QRegularExpressionMatch math0=regExp1.match("01/10/1949");//匹配类
            if(math0.hasMatch()){
                QString s = math0.captured(0); //完整匹配   //日 月 年
                QString s1 = math0.captured(1);//第一个单词 //日
                QString s2 = math0.captured(2);//第二个单词 //月
                QString s3 = math0.captured(3);//第三个单词 //年

                qDebug()<<"捕获文本:\n"<<"完整匹配:"<<s
                       <<"\n 日:"<<s1<<" 月"<<s2<<" 年"<<s3<<endl;
            }

            //部分匹配
            QString sPattern;
            sPattern="^(Jan|Fad|Mar|Apr|May) \\d\\d \\d\\d\\d\\d$";//月 日 年
            QRegularExpression regExp2(sPattern);

            QString ss("Apr 01");//要匹配的
            QRegularExpressionMatch math2;
            math2 = regExp2.match(ss,0 // ,偏移
            ,QRegularExpression::PartialPreferCompleteMatch //部分匹配
                                  );

            bool b=math2.hasMatch();//完整匹配
            bool c=math2.hasPartialMatch();//部分匹配的结果
            qDebug()<<b<<c;

            break;
        }
        break;
    }

    return a.exec();
}
