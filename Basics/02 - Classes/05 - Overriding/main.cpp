/*
   
    Overriding
    Why
    We want to change a base classes behavior
*/

#include <QCoreApplication>
#include <QDebug>
#include "lion.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Lion leo;
    leo.speak();

    return a.exec();
}
