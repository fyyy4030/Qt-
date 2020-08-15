#include <QApplication>
#include <QTableView> //表格视图
#include "custom_model.h" //自定义模型(表格)
#include "read_only_model.h" //只读模型(列表)
#include <QListView> //列表视图

void MVC_Tree_List_Table_View_Test();//mvc编程 树,列表,表格等视图示例

void MVC_Standard_Tree_ItemModel();//mvc 标准树项目模型

void MVC_custom_model_main();//mvc 自定义模型 主入口

void MVC_read_only_model_main();//mvc 只读模型 主入口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MVC_Tree_List_Table_View_Test();

    MVC_Standard_Tree_ItemModel();

    //MVC_custom_model_main();

    //MVC_read_only_model_main();

    return a.exec();
}

void MVC_custom_model_main(){//mvc 自定义模型 主入口
    custom_model *model=new custom_model;
    QTableView *view = new QTableView;
    view->setModel(model);//设置模型
    view->setWindowTitle(QString("表格视图"));//设置窗口标题
    view->resize(600,400);//设置大小
    view->show();
}

void MVC_read_only_model_main(){//mvc 只读模型 主入口
    QStringList list;
    list<<"太阳"<<"地球"<<"月亮"<<"木星";

    read_only_model *model=new read_only_model(list);//创建模型

    model->insertRows(3,2);//插入 (开始位置,插入数量)
    model->removeRows(0,1);//删除 (开始位置,删除数量)

    QListView *listview=new QListView;//列表视图
    listview->setModel(model);//视图设置模型
    listview->show();

    QTableView *tableview=new QTableView;//表格视图
    tableview->setModel(model);//视图设置模型
    tableview->show();




}
