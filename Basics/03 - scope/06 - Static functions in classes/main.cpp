/*
    
    Static functions in classes

    In C++, a static function within a class is a member function that belongs to the class
	itself rather than to any particular object of the class.
	This means it can be called without creating an instance of the class.
	A static function can only access other static members (both variables and
	functions) of the class, as it does not operate on any specific object's data.
	Static functions are useful when a function's logic is tied to the class itself, 
	not to any instance, such as utility functions, counters, or managing shared resources.
	They are commonly used when we need functionality that doesn't depend on object state but 
	still logically belongs to the class.

*/


#include <QCoreApplication>
#include <QDebug>
#include "test.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    Test t;
//    t.doStuff();
//    t.doOtherStuff();    // it works 

    Test::doOtherStuff();   // it works  also without having instance of the class since the function is static 

    return a.exec();
}
