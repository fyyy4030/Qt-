#ifndef PROPERTY_H
#define PROPERTY_H

#include <QObject>

class Property : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mask READ mask WRITE setMask NOTIFY maskChanged) //动态属性所需,前面的类型是可改的
public:
    explicit Property(QObject *parent = nullptr);
    QString mask()const;//读属性,返回值必须和动态属性改的那类型一样 //READ
    void setMask(QString mask);//写,返回值必须空,必须要有单参数类型同上
signals:
    //属性变化会发送信号,所有需加上
    void maskChanged(QString mask);//同写参照
public slots:

private:
    QString m_mask;

};

#endif // PROPERTY_H
