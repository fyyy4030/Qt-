#include "read_only_model.h"

read_only_model::read_only_model(const QStringList &strings,QObject *parent)
    :QAbstractListModel(parent),m_stringList(strings)
{

}

int read_only_model::rowCount(const QModelIndex &parent) const //行数
{
    return m_stringList.count();//计数 //返回列表的项数和size()等同
}

QVariant read_only_model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())return QVariant();//无效就返回默认

    if(index.row() == m_stringList.size())return QVariant();//索引的行 == 数据的大小

    //角色==显示||编辑
    if(role == Qt::DisplayRole || role ==Qt::EditRole)return m_stringList.at(index.row());
    else return QVariant();

}

QVariant read_only_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)return QVariant();//不是显示的角色

    if(orientation == Qt::Horizontal)
        //return QString("Column %1").arg(section);//水平表头
        return QString("行星");
    else
        QString("Row %1").arg(section);//垂直的表头
}

Qt::ItemFlags read_only_model::flags(const QModelIndex &index) const
{
    if(!index.isValid())return Qt::ItemIsEnabled;//无效就返回无项目标志
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;//有效:可用 | 可编辑
}

bool read_only_model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role==Qt::EditRole){//索引有效 && 可编辑角色
        //替换(代替,取代)(索引.行,(要替换的值)值.转string) //行所在的位置被value所更改
        m_stringList.replace(index.row(),value.toString());//数据的设置
        emit dataChanged(index,index);//发射信号 数据改变(左上角,右下角模型索引)
        return true;
    }
    return false;
}

 //插入行(插入的位置,插入的行,父项的模型索引) //模型索引读需添加默认值
bool read_only_model::insertRows(int position, int rows, const QModelIndex &parent)
{
    //告知其它组件指定的行开始插入操作
    //头插行(模型索引,插入的位置,位置+几行-1) //开始行插入操作
    beginInsertRows(QModelIndex(),position,position+rows-1);
    //beginInsertRows(parent,position,position+rows-1);//因为父项的模型索引是要修改,所以这不能使用,要想使用就去掉const

    for(int row=0;row<rows;row++)
        m_stringList.insert(position,QString("来自星星的你"));

    //告知其它组件完成操作
    endInsertRows();
    return true;
}

bool read_only_model::removeRows(int position, int rows,const QModelIndex &parent)
{
    //告知其它组件指定的行开始删除操作
    beginRemoveRows(QModelIndex(),position,position+rows-1);

    for(int row=0;row<rows;row++)
        m_stringList.removeAt(position);

    //告知其它组件完成操作
    endRemoveRows();
    return true;
}
