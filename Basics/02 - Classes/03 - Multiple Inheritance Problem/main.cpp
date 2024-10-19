/*
    
    Class inheritance
    We want to inherit aspects of a class

*/


#include <QCoreApplication>
#include "feline.h"
#include "canine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Canine dog;   // construct Animal , Mammal and Canine
    Feline cat;   // construct Animal , Mammal and Feline


    return a.exec();
}
