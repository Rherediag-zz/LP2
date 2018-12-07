#include "agenda.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Agenda w;
    w.show();

    return a.exec();
}
