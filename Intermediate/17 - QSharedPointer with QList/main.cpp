/*

  QSharedPointer with QList

  Why
  QObjects can not be copied

  Example
  See below

 */

#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

void testListAuto()
{
	
	// Using QSharedPointer ensures that the objects are automatically deleted when no references to them remain.
	// Declares a QList named list that holds QSharedPointer objects pointing to Test instances. 
    QList<QSharedPointer<Test>> list;

    for(int i = 0; i < 5; i++)
    {
		//  the object has no parent, and you are responsible for managing its memory manually.
        QSharedPointer<Test> item(new Test(nullptr, "Item" + QString::number(i)));
        list.append(item);
    }

    foreach(QSharedPointer<Test> test, list)
    {
		// Prints the raw pointer (test.data()) of each Test object to the console. 
        qInfo() << test.data();
    }

	
    qInfo() << "Remove one item";
	// Removes the first item (index 0) from the list. This operation decreases the reference count of the QSharedPointer 
	// managing that item. If no other QSharedPointer references that Test object, it will be automatically deleted.
    list.removeAt(0);
    qInfo() << "Clearing";
	// Clears the entire list, removing all elements. The reference count for each QSharedPointer is reduced,
	// and if the count reaches zero for any of the Test objects, they are automatically deleted
    list.clear();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testListAuto();
    return a.exec();
}
