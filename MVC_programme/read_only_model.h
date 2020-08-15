#ifndef READ_ONLY_MODEL_H
#define READ_ONLY_MODEL_H

#include <QAbstractListModel> //抽象列表模型

/* 对于类函数自己没有使用,却运行的问题(注:修改界面内容引发另一处界面修改):
  比如bool setData(...);此函数.Qt的 .exec()函数不断刷新应用,
从而数据不断刷新(常量类-全局类-动态类-静态类的视图/模型解析),致使setData()运行.
*/
/*关于常量类-全局类-动态类-静态类的视图/模型解析
 * Qt中常量类在main函数是能完整运行,但加了作用域后就bug了,那是.exec()函数不断刷新应用,
 * 常量类析构了,然后程序无法进行了.这种情况,采用全局类和静态类和动态类完美解决.
*/

//只读模型
class read_only_model : public QAbstractListModel
{
    Q_OBJECT
public:
    read_only_model(const QStringList &strings,QObject *parent=0);

    //模型行数(父模型索引(默认索引值))
    int rowCount(const QModelIndex &parent=QModelIndex()) const;

    //多样的  数据(模型索引 &指数,int 角色)
    QVariant data(const QModelIndex &index, int role) const;//指定模型索引数据

    //多样的,不同的  数据头数据(部分(行or列),方向,角色 = 显示的角色) //表头内容(数或表格)
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

    //项目标记(属性)  标记(模型索引 &指数)
    Qt::ItemFlags flags(const QModelIndex &index) const;

    //编辑数据(模型索引 &指数,多样的 值,角色 = 编辑角色)
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

    //插入行(插入的位置,插入的行,父项的模型索引) //模型索引读需添加默认值
    bool insertRows(int position, int rows,const QModelIndex &parent=QModelIndex());

    //删除行
    bool removeRows(int position,int rows,const QModelIndex &parent=QModelIndex());

private:
    QStringList m_stringList;

};

#endif // READ_ONLY_MODEL_H
