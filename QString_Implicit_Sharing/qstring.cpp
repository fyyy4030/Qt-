#include <QDebug>
#include <QDateTime>

void QString_conversion(){//QString的转换

    //        QString s="Hello";//数据块引用计数为1
    //        QString s1=s;//数据块引用计数为2
    //        QString s2=s1;//数据块引用计数为3

    //        s2="hi";//hello数据块引用计数为2
    //        //hi数据块引用计数为1

    //QString常用转换
    //const char*初始化
    QString str="杨幂";
    qDebug()<<str;

    //QChar数组初始化
    QChar hi[5]={'H','e','l','l','o'};
    QString strhi(hi,5);
    qDebug()<<strhi
           << "\n"<<sizeof(QChar)<<sizeof(char);

    //QString转int,double等
    QString strage("18");
    QString strpi("3.14");
    float pi=strpi.toFloat();
    int age=strage.toInt();
    double dpi=strpi.toFloat();
    qDebug()<<"age ="<<age
           <<"\npi ="<<pi
          <<"\ndpi ="<<dpi;

    //int等数据转QString
    int aaa = 1548;
    float faa = 41.54f;
    double ddd =6.666f;
    QString stra,strf,strw;
    stra=stra.number(aaa);
    strf=strf.number(faa);
    strw=strw.setNum(ddd);
    qDebug()<<stra<<"\n"<<strf<<"\n"<<strw;

    //QString 转(QByteArray)字节类,const char*
    QString strchar="zhou";
    QByteArray chararr = strchar.toUtf8();//指定编码
    const char* ch =chararr.data();
    qDebug()<<ch;

    //QString 转QDateTime(时间)
    QString t="2010-10-10 10:00:00";
    QDateTime stime= QDateTime::fromString(t,"yyyy-MM-dd hh:mm:ss");//日期格式

    qDebug()<<stime;

    //QDateTime转QString
    QDateTime dtime= QDateTime::currentDateTime();//当前时间
    QString tostr= dtime.toString("yyyy-MM-dd hh:mm:ss.zzz ddd");//不填格式也可以

    qDebug()<<tostr;

}

void QString_Splicing_formatting(){//QString的拼接与格式化

    //QString 拼接
    QString sss="我的女神";
    sss=sss+" 杨幂";
    sss += " 我爱你! ";
    sss.append("我要努力,现场看你(false)!");

    qDebug()<<sss;

    //QString 格式化
    QString ss0,ss1;
    ss0.sprintf("%s%d%s","史前",400,"万年");
    ss1.sprintf("%s%d%s%.1f%s","史前",400,"万年前有",0.5,"个人");
    qDebug()<<ss0<<"\n"<<ss1<<endl;

    QString r0,r1;
    r0 = QString("%1%2%3").arg("史前").arg(400).arg("万年");//进行自动匹配

    qDebug()<<r0<<endl;

}

void QString_Index_insert_replace_deleteSpaces(){//QString的索引,插入,替换,删除空格
    //QString 索引.at()
    QString sat="efsd";//索引从0开始
    QChar cat=sat.at(2);

    //qDebug()<<sat.at(2);
    qDebug()<<cat;

    //QString insert()指定位置插入字符
    QString c0="鱼的记忆只有秒钟";
    QString c1="七";
    c0.insert(6,c1.toUtf8());

    qDebug()<<c0;

    //QString prepend()在字符串起始位置插入字符
    qDebug()<<c0.prepend("热带");

    //QString replace()替换字符
    qDebug()<<c0.replace(8,3,"三个月");//替换开始的位置,被替换的长度,替换成

    //QString trimmed()去除字符串两端空格
    c0 ="    "+c0+"     ";
    qDebug()<<c0<<endl<<c0.trimmed();

    //QString simplified() 去除两端空格,中间空格以一个空格替代
    c1="   sfsdf   sf ss  ffg.   ";

    qDebug()<<c1.simplified();
}

void QString_Query_split_intercept(){//QString的查询,分割,截取,NULL字符串与空字符串
    //QString startsWith(开头),endsWith(结尾),contains(判断字符串里面有没这个目标)查询字符
    QString stm="汤姆和猫是好朋友.";
    QString etm="Tom and Cat are good friends.";

    qDebug()<<stm.startsWith("汤姆");//查询是否开头 是:true
    qDebug()<<etm.startsWith("tom",Qt::CaseSensitive);//区分大小写
    qDebug()<<etm.startsWith("Tom",Qt::CaseSensitive);
    qDebug()<<etm.endsWith("Friends.",Qt::CaseInsensitive);//不区分大小写
    qDebug()<<etm.contains("good");//判断字符串里面有没这个字符
    qDebug()<<etm.contains("Good",Qt::CaseSensitive);
    qDebug()<<QString::compare("Tom","tom",Qt::CaseSensitive);//0表示相等

    //QString split()分割字符串
    QString qspl="1954/5/4";
    QStringList qspls=qspl.split("/");
    qDebug()<<"1954/5/4分割后:";

    foreach(QString ss,qspls)
        qDebug()<<ss;

    //QString mid()截取子字符串
    QString smid="画画时间花花空间";
    qDebug()<<smid.mid(2,3);//开始位置,截取长度 //时间花

    //NULL字符串与空字符串;isEmpty()有无字符
    qDebug()<<QString().isNull()<<endl<<QString().isEmpty();//默认(const char*)0
    qDebug()<<QString("").isNull()<<endl<<QString("").isEmpty();
    const char* ccc='\0';
    qDebug()<<QString(ccc).isNull();
    qDebug()<<QString(ccc).isEmpty();

}

void QString_vessel(){//QStringList容器,字符串链表类
    QStringList zhou;
    //添加元素 //追加元素 //尾插法
    zhou<<"星期一"<<"星期二"<<"星期三";
    zhou<<"星期四";
    zhou.append("星期五");

    zhou.insert(0,"星期六");//insert() 指定位置插入元素

    qDebug()<<zhou;

//    //for遍历链表
//    for(int i=0;i<zhou.size();i++){
//        qDebug()<<zhou.at(i);
//    }

//    //foreach遍历
//    foreach (QString s, zhou) {
//        qDebug()<<s;
//    }

//    //STL风格迭代器遍历
//    QStringList::iterator it=zhou.begin();
//    for(;it != zhou.end();it++){
//        qDebug()<<*it;
//    }

//    //Java风格迭代器遍历
//    QListIterator<QString> itj(zhou);//字符串类型迭代器
//    while(itj.hasNext()){//判断是否有元素
//        qDebug()<<itj.next();
//    }

//    //判断此链表中是否包含某个元素 //cantains() 包含
//    zhou.contains("星期八")? qDebug()<<"链表中有星期八:" :qDebug()<<"链表中没有星期八:";

    //删除头元素
    zhou.removeFirst();
    qDebug()<<zhou;

    //删除尾元素
    zhou.removeLast();
    qDebug()<<zhou;

    //删除某个元素
    zhou.removeOne("星期二");
    qDebug()<<zhou;

    //删除指定位置的元素
    zhou.removeAt(1);
    qDebug()<<zhou;

    zhou.clear();//清空
    qDebug()<<zhou;

}
