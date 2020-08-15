#ifndef CUSTOM_MODEL_H
#define CUSTOM_MODEL_H

#include <QAbstractTableModel> //抽象表格模型

//自定义模型 : 抽象表格模型
class custom_model : public QAbstractTableModel
{
    //Q_Object
public:
    custom_model(QObject* parent=0);

    //行计数(父项索引默认传值)
    virtual int rowCount(const QModelIndex &parent=QModelIndex())const;
    virtual int columnCount(const QModelIndex &parent)const;//列数

    //多样的  数据(模型索引 &指数,int 角色)
    QVariant data(const QModelIndex &index, int role)const;//返回指定索引的数据,将数值映射成文字

    //多样的,不同的  数据头数据(部分(行or列),方向,角色)
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QVector<short> army;//军种
    QVector<short> weaponType;//武器类型

    QMap<short,QString> armyMap;//军队映射
    QMap<short,QString> weaponMap;//武器映射

    QStringList weapon;//武器
    QStringList header;//表头

    void populateModel();//表格数据的初识化
};

#endif // CUSTOM_MODEL_H
