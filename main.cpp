#include "pacswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PacsWindow w;
    w.show();
    return a.exec();
}
