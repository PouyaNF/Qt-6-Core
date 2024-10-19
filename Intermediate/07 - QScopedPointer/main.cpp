/*

  QScopedPointer
  
  QScopedPointer in Qt is a smart pointer that provides automatic memory management 
  by ensuring that the object it points to is deleted when the QScopedPointer goes 
  out of scope. This helps prevent memory leaks in cases where manual memory management 
  might lead to issues, such as forgetting to delete an object.
  
  Ownership: Owns a single object.
  Lifetime Management: Automatically deletes the managed object when it goes out of scope.
  Use Case: Best for managing resources with a limited lifetime, such as within a function or block.

*/

#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void test()
{
    QScopedPointer<Test> sp(new Test());
    sp->setObjectName("My Test");

    qInfo() << "Scoped Pointer" << &sp;
    qInfo() << "Pointer Data" << sp.data();
    qInfo() << sp->objectName();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();

    return a.exec();
}
