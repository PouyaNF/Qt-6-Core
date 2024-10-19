/*
    
    Static scope in classes
 
    We want all classes to use the same variable

*/


#include <QCoreApplication>
#include <QDebug>
#include "animal.h"

// we have to initialise static var first 
int Animal::count = 0;
QString Animal::name = "";

void test()
{
    Animal cat;
    Animal dog;
    Animal fish;
    qInfo() << dog.count; // 3 

    cat.name = "Gamer";
    dog.name = "MuddPie";  // name = "Gamer" would be replace here since name is static 

    qInfo() << "Cat:" << cat.name;  // "MuddPie" 

    //Deconstruction here!
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();
    qInfo() << Animal::count;   // 0 

    return a.exec();
}
