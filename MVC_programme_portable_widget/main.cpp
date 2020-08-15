#include <QApplication>
#include <QDebug>
#include <QListWidget> //列表部件
#include <QTreeWidget> //树部件
#include <QTableWidget> //表格部件
#include <QStandardItemModel>//标准项目模型

void QListWidget__();//QListWidget部件
void QTreeWidget__();//QTreeWidget部件
void QTableWidget__();//QTableWidget部件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QListWidget__();//QListWidget部件

    QTreeWidget__();//QTreeWidget部件

    QTableWidget__();//QTableWidget部件

    return a.exec();
}

void QListWidget__(){//QListWidget部件
    QListWidget *listwidget=new QListWidget;
    //添加项目
    new QListWidgetItem("天涯",listwidget);

    QListWidgetItem *listwidgetitem=new QListWidgetItem;
    listwidgetitem->setText("海角");

    //设置图标
    QPixmap pixmap(50,50);
    pixmap.fill(Qt::blue);
    listwidgetitem->setIcon(QIcon(pixmap));
    listwidgetitem->setToolTip("大海的角落");//工具小建议

    listwidget->insertItem(1,listwidgetitem);//插入项目(位置,项目)
    //设置排序
    listwidget->sortItems(Qt::DescendingOrder);//降序排列

    listwidget->show();
}

void QTreeWidget__(){//QTreeWidget部件
   // QStandardItemModel *model=new QStandardItemModel;//标准项模型
    //获取标准项模型的根项,根项是不可见的
    //QStandardItem *parentItem = model->invisibleRootItem();//获取隐藏的(无形的)根项

    QTreeWidget *treewidget=new QTreeWidget;//树

    //设置列数
    treewidget->setColumnCount(2);

    //treewidget->setColumnWidth(0,200);//设置列宽

    //设置表头
    QStringList headers;//表头
    headers<<"星星名字"<<"星星数量";
    treewidget->setHeaderLabels(headers);

    //添加项目
    QTreeWidgetItem *item1=new QTreeWidgetItem(treewidget);
    item1->setText(0,"小星星");

    QTreeWidgetItem *item11=new QTreeWidgetItem(item1);
    //item11->setSizeHint(0,QSize(1000,1000));
    item11->setText(0,"小星星的小星星");
    item11->setToolTip(0,"小星星的小星星");
    item11->setText(1,"第二颗小星星");


    //QWidget * s2=static_cast<QWidget*>(item1);
    //parentItem = s2;

    treewidget->setColumnWidth(0,300);//设置列宽


    //添加项目指定它的前一个项目item1
    QTreeWidgetItem *item2=new QTreeWidgetItem(treewidget,item1);
    item2->setText(0,"大猩猩");
    //QStandardItem * s1=static_cast<QStandardItem*>(item2);
    //parentItem = s1;

    //返回树视图头项目指针
   // treewidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //treewidget->setColumnWidth(1,2000);//设置列宽

    treewidget->show();
}

void QTableWidget__(){
    //表格部件
    QTableWidget *tablewidget=new QTableWidget(3,2);
    //表格部件项目
    QTableWidgetItem *tablewidgetitem=new QTableWidgetItem("tom");
    tablewidget->setItem(1,1,tablewidgetitem);//表格部件设置项目

    //创建表格项目并做为表头
    QTableWidgetItem *headerV =new QTableWidgetItem("cat");

    //表格部件.设置垂直的表头项目(行(位置),表格项目)
    tablewidget->setVerticalHeaderItem(0,headerV);

    //表格项目
    QTableWidgetItem *headerH =new QTableWidgetItem("what?");

    //表格部件.设置水平的表头项目(行(位置),表格项目)
    tablewidget->setHorizontalHeaderItem(0,headerH);

    tablewidget->show();
}
