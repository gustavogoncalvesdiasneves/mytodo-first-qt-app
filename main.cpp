#include "mytodo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTodo w;
    w.show();
    return a.exec();
}
