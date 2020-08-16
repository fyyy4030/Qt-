#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H
#include <QSyntaxHighlighter> //语法高亮类

//我的语法高亮类
class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    MySyntaxHighlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString& text);//重写实现高亮语法块

};

#endif // MYSYNTAXHIGHLIGHTER_H
