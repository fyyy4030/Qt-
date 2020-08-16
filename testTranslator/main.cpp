#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //多语言
//    QTranslator *translator=new QTranslator;
//    translator->load("lang_en.qm");
//    a.installTranslator(translator);

    MainWindow w;
    w.show();
    return a.exec();
}
