#include <QDebug>
#include <QLinkedListIterator> //java风格链表迭代器

void QList_QLinkedList(){//链表容器
    while(0){//QList
        while(0){//正常展示
            QList<int> list;//链表
            list<< 1 << 2;//连续添加元素
            list<< 3;//尾部添加元素
            list.append(4);//尾部添加元素
            list.prepend(0);//头部添加元素
            list.insert(1,55);//指定位置插入元素
            qDebug()<<list;

            //查找元素
            qDebug()<<"第三个元素:"<<list.at(2);
            qDebug()<<"第四个元素:"<<list[3];
            qDebug()<<"list中有9:"<<list.contains(9);

            qDebug()<<"list的大小:"<<list.size();

            //修改元素
            list.replace(2,66);
            list[0]=100;
            qDebug()<<"修改第三个元素和第一个元素后:"<<list;

            //删除元素
            list.removeFirst();//删除第一个元素
            qDebug()<<"删除第一个元素后:"<<list;
            list.removeLast();//删除最后一个元素
            qDebug()<<"删除最后一个元素后:"<<list;
            list.removeAt(2);//删除指定位置元素
            qDebug()<<"删除第三个元素后:"<<list;
            list.removeOne(55);//删除指定元素
            qDebug()<<"删除55后:"<<list;
            list.clear();//清空链表
            qDebug()<<"清空链表后:"<<list;
            break;
        }

        while(0){//java风格迭代器
            QList<int> m;

            QMutableListIterator<int> it_m(m);//读写迭代器
            for(int i=0;i<12;i++) it_m.insert(i);//初始化链表

            while(0){//读写迭代器
                qDebug()<<"初始化后数据反遍历:";
                //迭代器指向链表最后一个元素,前面还有元素么
                for(it_m.toBack();it_m.hasPrevious();)
                    qDebug()<<it_m.previous();

                qDebug()<<"初始化后数据正遍历:";
                //迭代器指向链表第一个元素之前,后面还有元素么
                for(it_m.toFront();it_m.hasNext();)
                    qDebug()<<it_m.next();

                for(it_m.toFront();it_m.hasNext();){
                    int n=it_m.next();
                    if(n ==0){
                        it_m.remove();//删除
                    }

                    if(n ==11){
                        it_m.setValue(12);//修改
                    }
                }

                qDebug()<<"修改数据后正遍历:";
                //迭代器指向链表第一个元素之前,后面还有元素么
                for(it_m.toFront();it_m.hasNext();)
                    qDebug()<<it_m.next();
                break;
            }

            while(1){
                QListIterator<int> it_d(m);//只读迭代器
                qDebug()<<"只读迭代器正遍历:";
                for(it_d.toFront();it_d.hasNext();){//正遍历
                    qDebug()<<it_d.next();
                }
                qDebug()<<"只读迭代器反遍历:";
                for(it_d.toBack();it_d.hasPrevious();){//反遍历
                    qDebug()<<it_d.previous();
                }

                break;}

            break;
        }

        while(0){//STL风格迭代器
            QList<int> ss;
            ss<<11 <<22 <<33 <<44 <<55;

            //读写迭代器
            QList<int>::iterator it_ss;
            it_ss = ss.begin();
            for(;it_ss != ss.end();++it_ss){
                *it_ss=*it_ss *10;
                qDebug()<<*it_ss;
            }

            //只读迭代器
            QList<int>::const_iterator it_s;
            it_s =ss.constBegin();
            qDebug()<<"STL只读正遍历:";
            for(;it_s != ss.constEnd();++it_s){
                qDebug()<<*it_s;
            }
            break;
        }
        break;
    }

    while(1){// QLinkedList 无法[],.at()方法 大量数据插入就能体现出优势了
        QLinkedList<QString> week;
        for(int i =1 ;i < 8;i++){
            week << QString("%1%2").arg("星期").arg(i);
        }

        //java风格只读迭代器
        QLinkedListIterator<QString> it_week(week);
        for(it_week.toFront();it_week.hasNext();){
            qDebug()<<it_week.next();
        }

        //java风格读写迭代器
        QMutableLinkedListIterator<QString> d_week(week);
        for(d_week.toFront();d_week.hasNext();){
            QString n = d_week.next();
            if(n=="星期3"){//修改
                d_week.setValue("星期三");
            }

            if(n=="星期5"){//删除
                d_week.remove();
            }
        }

        qDebug()<<"修改数据后:";
        for(d_week.toFront();d_week.hasNext();){
            qDebug()<<d_week.next();
        }

        for(d_week.toFront();d_week.hasNext();){
            QString n = d_week.next();
            if(n=="星期4"){
                d_week.insert("星期五");
            }
        }

        qDebug()<<"添加星期五后:";
        for(d_week.toFront();d_week.hasNext();){
            qDebug()<<d_week.next();
        }

        break;
    }
}

void QVector_(){//QVector向量容器 //操作基本和上面一样
    QVector<QString> vs;

    //添加元素
    vs<<"杨幂"<<"迪丽热巴"<<"刘涛";
    vs<<"小倩";
    vs.append("杨紫");//尾
    vs.prepend("Angelababy");//头
    vs.insert(2,"刘亦菲");//指定位置添加

    qDebug()<<vs;

    vs.replace(5,"王祖贤");//修改元素
    qDebug()<<vs;

    //删除元素
    vs.remove(0);//将第一个元素删除
    qDebug()<<vs;
    vs.removeAll("杨紫");//将某元素删除
    qDebug()<<vs;

    //查询元素
    qDebug()<<"第四个明星是:"<<vs[3];
    qDebug()<<"是否有杨幂:"<<vs.contains("杨幂");

    //java风格迭代器
    QVectorIterator<QString> it_vs(vs);//只读迭代器
    qDebug()<<"java风格只读迭代器";
    for(it_vs.toFront();it_vs.hasNext();){
        qDebug()<<it_vs.next();
    }

    qDebug()<<"java风格读写迭代器";
    QMutableVectorIterator<QString> dx_vs(vs);//读写迭代器
    for(dx_vs.toFront();dx_vs.hasNext();){
        QString s=dx_vs.next();
        if(!QString::compare(s,"刘亦菲")){
            dx_vs.setValue("柳岩");
        }
    }

    qDebug()<<"数据修改后遍历:";
    for(dx_vs.toFront();dx_vs.hasNext();){
        qDebug()<<dx_vs.next();
    }


}

void QMap_QMultiMap(){//QMap QMultiMap 映射,图容器
    while(0){//QMap
        while(0){//java风格迭代器
            QMap<QString,QString> map;
            //添加元素
            map.insert("杨幂","168");//根据key来排序的
            map.insert("杨紫","165");
            map["迪丽热巴"]="170(成年)";
            map["王祖贤"]="165cm";

            //通过key找value
            qDebug()<<"迪丽热巴:"<<map["迪丽热巴"];
            qDebug()<<"杨紫:"<<map.value("杨紫");

            //通过value找key
            qDebug()<<"165的是谁:"<<map.key("165");//同样value的会提取第一位的

            //java风格迭代器
            qDebug()<<"\njava风格只读迭代器:";
            QMapIterator<QString,QString> d_map(map);//只读迭代器
            for(d_map.toFront();d_map.hasNext();){
                d_map.next();
                qDebug()<<d_map.key()<<":"<<d_map.value();
            }

            qDebug()<<"\njava风格读写迭代器:";
            QMutableMapIterator<QString,QString> it_map(map);
            if(it_map.findNext("165"))      //查找value
                it_map.setValue("165.78");  //修改value

            qDebug()<<"修改数据后遍历:";
            for(it_map.toFront();it_map.hasNext();){
                it_map.next();
                qDebug()<<it_map.key()<<":"<<it_map.value();
            }
            break;
        }

        while(0){//STL风格迭代器
            QMap<QString,QString> map;
            //添加元素
            map.insert("杨幂","168");//根据key来排序的
            map.insert("杨紫","165");
            map["迪丽热巴"]="170(成年)";
            map["王祖贤"]="165cm";

            qDebug()<<"只读迭代器:";
            QMap<QString,QString>::const_iterator d_map=map.constBegin();//只读迭代器
            for(;d_map != map.constEnd();d_map++){
                qDebug()<<d_map.key()<<":"<<d_map.value();
            }

            qDebug()<<"\n读写迭代器:";
            QMap<QString,QString>::iterator it_map;//读写迭代器
            it_map = map.find("杨紫");
            if(it_map != map.end()){//修改数据
                it_map.value()="170";
            }

            qDebug()<<"修改数据后遍历:";
            it_map=map.begin();
            for(;it_map != map.end();it_map++){
                qDebug()<<it_map.key()<<":"<<it_map.value();
            }

            break;
        };
        break;
    }

    while(1){//QMultiMap;一key对应多value;删除
        QMultiMap<QString,QString> map;
        //添加元素
        map.insert("杨幂","168");//根据key来排序的
        map.insert("杨紫","165");
        map.insert("杨紫","180");
        map.insert("迪丽热巴","170(成年)");
        map.insert("王祖贤","155cm");
        map.insert("王祖贤","177cm");

        qDebug()<<map;
        map.remove("王祖贤","155cm");//删除
        qDebug()<<"删除后:"<<map;

        qDebug()<<endl<<map.values("杨紫");//查询key对应的全部value

        //Java风格只读迭代
        QMapIterator<QString,QString> it(map);
        qDebug() << endl << "遍历:";
        for(it.toFront();it.hasNext();){
            qDebug() << it.key()
                     <<":"
                    << it.next().value();

        }


        break;
    }

}

void QHash_(){//QHash 哈希类 容器
    QHash<int,QString> hash;
    //添加元素
    hash.insert(1,"一块钱");
    hash.insert(10,"10块钱");
    hash.insert(20,"20块钱");
    hash[35]="35块钱";
    hash[55]="55块钱";
    hash.insertMulti(55,"五十五");
    //hash[55]="五十五";//会覆盖

    //java风格迭代器
    QHashIterator<int,QString> d_hash(hash);//只读迭代器
    qDebug()<<"只读人民币:";
    for(d_hash.toFront();d_hash.hasNext();){
        qDebug()<<d_hash.key()<<":"<<d_hash.next().value();//无序存储
    }

    QMutableHashIterator<int,QString> it_hash(hash);//读写迭代器

    if(it_hash.findNext("10块钱"))
         it_hash.setValue("10元");//修改

    qDebug()<<"\n修改后遍历:";

    for(it_hash.toFront();it_hash.hasNext();){
        qDebug()<<it_hash.key()<<":"<<it_hash.next().value();
    }

}


