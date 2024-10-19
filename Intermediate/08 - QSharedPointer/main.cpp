/*

  QSharedPointer

  QSharedPointer is a smart pointer in Qt that provides automatic memory management 
  with shared ownership. Multiple QSharedPointer instances can point to the same object, 
  and the object is automatically deleted when the last QSharedPointer that owns it goes 
  out of scope or is reset.
  
  QSharedPointer
  Ownership: Allows multiple pointers to share ownership of a single object.
  Reference Counting: Keeps track of how many QSharedPointer instances point to 
  the same object; deletes the object when the count reaches zero.
  Use Case: Useful in scenarios where multiple components need access to the same 
  resource, such as shared data in multi-threaded applications.
  
 QWeakPointer
 Ownership: Does not own the object; provides a weak reference.
 Avoids Dangling Pointers: Can be used with QSharedPointer to prevent dangling pointers,
 as it automatically becomes nullptr if the object is deleted.
 
 Use Case: Ideal for observer patterns or when you need to reference an object without affecting its lifetime.
 QPointer
 Ownership: Also does not own the object; it is specifically designed for QObject types.
 Automatic Nullification: Automatically becomes nullptr when the QObject it points to is deleted.
 Use Case: Useful for tracking QObject instances in a signal/slot mechanism, ensuring safe access to objects that may be deleted.
  
  
*/

#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

QSharedPointer<Test> getObject(QString name)
{
	
	// Creates a QSharedPointer named sp that manages a newly allocated Test object. 
    QSharedPointer<Test> sp(l Test());
	
    sp->setObjectName(name);
    //Do other things here
    return sp;
}

// Since QSharedPointer uses shared ownership, passing it by value means that the reference 
//count for the shared object will increase inside this function.
void doWork(QSharedPointer<Test> sp)
{
    //We are using a copy of the sharedpointer
    qInfo() << "Work" << sp.data();
    qInfo() << "SharedPointer" << &sp;
}

void test()
{
	
    qInfo() << "Getting the object";
	
	// creates a QSharedPointer for a new Test object, assigns it the name "My Object"
    QSharedPointer<Test> ptr = getObject("My Object");
	// the address of the ptr variable
    qInfo() << "SharedPointer" << &ptr;
	// Logs the raw pointer to the Test object managed by ptr
    qInfo() << "Object" << ptr.data();
	//passing ptr by value. Inside doWork(), a copy of ptr is created, increasing the reference count to 2
    doWork(ptr);
    //Reference count is zero
    qInfo() << "Complete";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
