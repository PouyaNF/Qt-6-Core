/*
    
    QObject
    Its the base class for (almost) everything
*/


#include <QCoreApplication>
#include "test.h"

void lifecycle()
{
    Test t;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    lifecycle();

    return a.exec();
}
