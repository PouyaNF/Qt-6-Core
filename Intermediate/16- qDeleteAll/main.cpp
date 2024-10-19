/*

	This code demonstrates the use of qDeleteAll with QList to manage the memory
	of dynamically allocated Test objects.
	
	qDeleteAll(list) deletes all the objects (pointers) in a container like QList, 
	QVector, or any other Qt container that holds pointers.
	It’s typically used when you have a container holding dynamically allocated objects
	and you want to clean up the memory by deleting each object in the list.


 */

#include <QCoreApplication>
#include <QList>
#include "test.h"


void testListDelete()
{
	
    QList<Test*> list;
    for(int i = 0; i < 5; i++)
    {
		// creates a new instance of the Test class using dynamic memory allocation.
		// nullptr: Passes a null pointer as the first argument, which might be used for parent-child relationships in Qt (indicating that this object has no parent).
        list.append(new Test(nullptr,"Item" + QString::number(i)));
    }

	// Iterates through the list and prints the memory addresses of the Test objects.
    foreach(Test* test, list)
    {
        qInfo() << test;
    }

	// Deletes all Test objects pointed to by the pointers in list, freeing their allocated memory.
    qDeleteAll(list);


    
	
	// qDeleteAll(list) deletes the objects pointed to by the pointers, 
	// but the pointers themselves in the list still exist. 
	// They now point to invalid (deleted) memory, which is why accessing them would lead to undefined behavior.  
	//qInfo() << list.at(0); //Dangling Pointer
	list.clear();

    qInfo() << "Count:" << list.count();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testListDelete();

    return a.exec();
}
