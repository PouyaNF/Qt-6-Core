/*

  Sharing a pointer among multiple objects
  We want a smart pointer, but we want to share it

 */

#include <QCoreApplication>
#include <QSharedPointer>
#include "cat.h"
#include "toy.h"
#include <vector>

void test()
{
    int max = 5;
    QSharedPointer<Toy> toy(new Toy());  
    std::vector<QSharedPointer<Cat>> cats(max);  

    for(int i = 0; i < max; i++)
    {
		// The .reset() method is used to assign a new object to a QSharedPointer.
		// releases any existing object managed by the pointer (if there is one) and takes ownership of the newly created Cat object.
        cats[i].reset(new Cat());
        cats[i]->play(toy);
    }

    qInfo() << "All cats are done!";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
