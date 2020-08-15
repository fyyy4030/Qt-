#include <QTreeView> //树视图
#include <QStandardItemModel> //标准项目模型
#include <QDebug>

void MVC_Standard_Tree_ItemModel(){//mvc 标准树项目模型
    QStandardItemModel *model=new QStandardItemModel;//标准项模型

    while(1){//模型显示示例
    //获取标准项模型的根项,根项是不可见的
    QStandardItem *parentItem = model->invisibleRootItem();//获取隐藏的(无形的)根项
    //---------------------------------------------------------------------------
    //创建标准项
    QStandardItem *item0=new QStandardItem;
    item0->setText(QString("A"));//设置文本

    //设置图标
    QPixmap pixmap0(50,50);//象图(宽,高)
    pixmap0.fill(Qt::red);//填充(红)
    item0->setIcon(QPixmap(pixmap0));//设置图标

    item0->setToolTip("A项");//设置提示 //停留一会显示

    parentItem->appendRow(item0);//附加行 //注释掉会有异常
    parentItem = item0;//将item0子项作为父项
    //--------------------------------------------创建item0的子项
    //创建标准项
    QStandardItem *item1=new QStandardItem;
    item1->setText(QString("B"));//设置文本

    //设置图标
    QPixmap pixmap1(50,50);//象图(宽,高)
    pixmap1.fill(Qt::green);//填充()
    item1->setIcon(QPixmap(pixmap1));//设置图标

    item1->setToolTip("B项");//设置提示 //停留一会显示

    parentItem->appendRow(item1);//附加行

    //--------------------------------------------创建item0的子项
    //创建标准项
    QStandardItem *item2=new QStandardItem;

    //设置图标
    QPixmap pixmap2(50,50);//象图(宽,高)
    pixmap2.fill(Qt::blue);//填充()

    //设置数据
    item2->setData("C",Qt::EditRole);//编辑的角色
    item2->setData("indexC",Qt::ToolTipRole);//工具提示的角色
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);//图标的角色

    parentItem->appendRow(item2);//附加行

    //在树视图中显示数据
    QTreeView *view=new QTreeView;
    view->setModel(model);//设置模型
    view->show();

    break;
    }

    while(1){//模型索引
        //模型索引 = 索引(行,列,父项)
        QModelIndex indexA = model->index(0,0,QModelIndex());

        qDebug()<<"indexA row(行) coutn(数):"
               <<model->rowCount(indexA);

        QModelIndex indexB = model->index(0,0,indexA);

        qDebug() << "indexB text:"
        << model->data(indexB,Qt::EditRole).toString();

        qDebug() << "indexB toolTip:"
        << model->data(indexB,Qt::ToolTipRole).toString();
        break;
    }
}
