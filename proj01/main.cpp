#include "mywidget.h"
//#include <QPushButton>
#include <QApplication>

int main(int argc, char *argv[])//argc
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}
