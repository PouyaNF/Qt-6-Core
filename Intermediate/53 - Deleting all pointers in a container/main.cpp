/*

  What
  Deleting all pointers in a container

  Why
  C++ requires us to manage pointers

  How
  qDeleteAll

 */

#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Test*> list;
    for(int i = 0; i < 10; i++)
    {
        Test *t = new Test(); //no parent, no smart pointer
        t->setObjectName(QString::number(i));
        list.append(t);

    }

    qInfo() << list.at(0);

	// Deletes all the objects pointed to by the pointers in the list. 
    qDeleteAll(list); // It prevents memory leaks by releasing the memory allocated with new.
	
    qInfo() << "Count: " << list.count(); //  After qDeleteAll, this count will still be 10 because deleting the objects does not remove them from the list.

   // qInfo() << list.at(0); //Will crash
    qInfo() << "Clearing...";
    list.clear(); // Clears the list. This removes all elements from the list, leaving it empty. 

    qInfo() << "Count: " << list.count(); // should now be 0 since the list was cleared

    return a.exec();
}
