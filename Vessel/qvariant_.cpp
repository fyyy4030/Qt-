#include "qvariant_.h"
#include "ui_qvariant_.h"
#include <QDebug>

QVariant_::QVariant_(QWidget *parent) :
    QWidget(parent)
{
   QVariant v(100);
   qDebug()<<v.toInt();

   QVariant vpi(3.1415f);
   qDebug()<<vpi.toFloat();

   QVariant str("hills");
   qDebug()<<str.toString();

   QVariant b(true);
   qDebug()<<b.toBool();

   QColor cc=QColor(Qt::black);//黑色
   QVariant c(cc);
   qDebug()<<c.type();//数据类型
   qDebug()<<c.value<QColor>();

   QVariant vs =str;//转换测试
//   QVariant vs =1000;
   qDebug()<<vs.canConvert(QVariant::Int);//判断有无转换能力,但不一定转换成功,类型转换需匹配才行
   qDebug()<<vs.convert(QVariant::Int);//进行转换
   qDebug()<<vs;
   qDebug()<<vs.toString();//转换数据失败,数据可能会被覆盖
}

QVariant_::~QVariant_()
{

}
