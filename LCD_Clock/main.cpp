#include "clock.h"
#include <QApplication>
#include "digital_clock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Digital_Clock w;
    w.show();

    return a.exec();
}
