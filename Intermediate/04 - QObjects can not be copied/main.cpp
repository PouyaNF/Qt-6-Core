/*
    QObjects can not be copied

    Why
    The memory address is the objects identity
	
	In general, copying a QObject can lead to problems because QObject instances are non-copyable,
	as indicated by its private copy constructor and assignment operator.
	

*/

#include <QCoreApplication>

void testPointer(QObject *obj)
{
    qInfo() << obj;  // it prints the memory address of the object
}

void testAddress(QObject &obj)
{
    qInfo() << &obj; // It logs the memory address of the object passed in by reference
}

// Even though Qt’s QObject typically disallows copying due to QObject's non-copyable nature,
// this function would still compile, but it will likely cause runtime errors or result in
// undefined behavior, depending on the object type.
void testCopy(QObject obj)
{
    qInfo() << &obj;   
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("Bryan");

    testPointer(&person);
    testAddress(person);
    testCopy(person); //Deleted copy constructor

    return a.exec();
}
