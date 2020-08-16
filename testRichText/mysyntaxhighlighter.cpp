#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent)
:QSyntaxHighlighter(parent)
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat format;//字符格式
    format.setFontWeight(QFont::Bold);//设置字体权重(加粗)
    format.setBackground(Qt::red);//设置背景色(红)
    format.setForeground(Qt::green);//设置前景色(绿)

    //QString pattern="\\bgood\\b";//匹配的字符 //隔开才显示
    QString pattern="good";//不隔开也显示
    QRegExp expression(pattern);//正则表达式类
    int index = text.indexOf(expression);//返回匹配到的位置()//匹配不成功返回-1
    while(index >= 0){//匹配到了就进行格式设置
        int length = expression.matchedLength();//匹配到的字符长度
        setFormat(index,length,format);//设置格式(开始,长度,设置成啥样);
        index = text.indexOf(expression,index+length);//往下重新匹配
    }
}
