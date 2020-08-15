#include <QAbstractItemModel> //抽象模型
#include <QAbstractItemView> //抽象视图
#include <QItemSelectionModel> //项目选择模型
#include <QDirModel> //目录模型
#include <QTreeView> //树形视图
#include <QListView> //列表视图
#include <QTableView> //表格视图
#include <QSplitter> //窗口分割

//mvc编程 树,列表,表格等视图示例
void MVC_Tree_List_Table_View_Test(){
    while(1){

        //        static QDirModel model;//目录模型
        //        static QTreeView tree;//树视图
        //        static QListView list;//列表视图
        //        static QTableView table;//表格视图

        //部件要想显示出来,需作为静态或者动态形式,变量形式会限制在作用域而无法显示
        QDirModel *model = new QDirModel;//目录模型
        QTreeView *tree = new QTreeView;//树视图
        QListView *list = new QListView;//列表视图
        QTableView *table = new QTableView;//表格视图


        //视图设置模型
        tree->setModel(model);
        list->setModel(model);
        table->setModel(model);

        //设置视图对象的选择方式为多选
        tree->setSelectionMode(QAbstractItemView::MultiSelection);//多选
        list->setSelectionMode(tree->selectionMode());//同上
        table->setSelectionMode(QAbstractItemView::MultiSelection);

        //树视图双击信号发射后,列表and表格视图同时刷新内容
        QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),list,SLOT(setRootIndex(QModelIndex)));
        QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),table,SLOT(setRootIndex(QModelIndex)));

        //窗口分割
        QSplitter *splitter=new QSplitter;

        //添加部件
        splitter->addWidget(tree);
        splitter->addWidget(list);
        splitter->addWidget(table);

        splitter->setWindowTitle(QString("模型/视图"));
        splitter->show();
        break;
    }
}
