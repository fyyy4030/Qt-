#ifndef QVARIANT__H
#define QVARIANT__H

#include <QWidget>

/*QVariant QT共用体:
QVariant这个类很神奇，或者说方便。很多时候，需要几种不同的数据类型需要传递，
如果用结构体，又不大方便，容器保存的也只是一种数据类型，而QVariant则可以统统搞定。

帮助文档上说：The QVariant class acts like a union for the most common Qt data types.。

QVariant 这个类型充当着最常见的数据类型的联合。QVariant 可以保存很多Qt的数据类型，
包括QBrush、QColor、QCursor、QDateTime、QFont、QKeySequence、 QPalette、
QPen、QPixmap、QPoint、QRect、QRegion、QSize和QString，并且还有C++基本类型，如 int、float等。

当然，如果支持的类型没有想要的，没关系，QVariant也可以支持自定义的数据类型。
被QVariant存储的数据类型需要有一个默认的构造函数和一个拷贝构造函数。
为了实现这个功能，首先必须使用Q_DECLARE_METATYPE()宏。
通常会将这个宏放在类的声明所在头文件的下面：

Q_DECLARE_METATYPE(MyClass)
*/

namespace Ui {
class QVariant_;
}

class QVariant_ : public QWidget
{
    Q_OBJECT

public:
    explicit QVariant_(QWidget *parent = 0);
    ~QVariant_();

private:
    Ui::QVariant_ *ui;
};

#endif // QVARIANT__H
