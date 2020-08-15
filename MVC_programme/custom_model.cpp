#include "custom_model.h"

custom_model::custom_model(QObject* parent):QAbstractTableModel(parent)
{
    //军队类型
    armyMap[1] = QString("空军");
    armyMap[2] = QString("海军");
    armyMap[3] = QString("陆军");
    armyMap[4] = QString("海军陆战队");

    //武器类型
    weaponMap[1]=QString("轰炸机");
    weaponMap[2]=QString("战斗机");
    weaponMap[3]=QString("航空母舰");
    weaponMap[4]=QString("驱逐舰");
    weaponMap[5]=QString("直升机");
    weaponMap[6]=QString("坦克");
    weaponMap[7]=QString("两栖攻击舰");
    weaponMap[8]=QString("两栖战车");

    populateModel();//表格数据的初识化
}

int custom_model::rowCount(const QModelIndex &parent)const
{
    return army.size();
}

int custom_model::columnCount(const QModelIndex &parent)const
{
    return 3;
}

//多样的  数据(模型索引 &指数,int 角色)
QVariant custom_model::data(const QModelIndex &index, int role) const //返回指定索引的数据,将数值映射成文字
{
    if(!index.isValid())return QVariant();//空(无效) 返回默认构造

    //角色 == 显示的角色
    if(role == Qt::DisplayRole){
        //判断列
        switch(index.column()){
        case 0://返回军队信息
            return armyMap[army[index.row()]];//军队图[军队[索引.行]]
            break;
        case 1:
            return weaponMap[weaponType[index.row()]];//武器图[武器类型[]]
            break;
        case 2:
            return weapon[index.row()];//武器[]
            break;
        default://其它情况
            return QVariant();
        }
    }

    return QVariant();//其它角色
}

//多样的,不同的  数据头数据(部分(行or列),方向,角色)
QVariant custom_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    //角色 == 显示的角色 && 方向 == 水平的
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
        return header[section];//数据头[列]

    //返回默认的 数据头数据
    return QAbstractTableModel::headerData(section,orientation,role);
}

void custom_model::populateModel()//表格数据的初识化
{
    header <<QString("军种") <<QString("种类")<<QString("武器");//表头
    army << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1 ;//军种
    weaponType << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2 ;//武器类型 //种类
    weapon<<QString("B-2")<<QString("尼尔兹极")<<QString("阿帕奇")<<QString("黄蜂级")
         <<QString("比例伯克级")<<QString("AAAV")<<QString("M1A1")<<QString("F-22");//武器
}
