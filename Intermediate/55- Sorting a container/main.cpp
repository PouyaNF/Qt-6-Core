/*
  What
  Sorting a container

  Why
  We want things in order

  How
  qSort is deprecated
  use std sort

 */

#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QRandomGenerator>

void randoms(QList<int> *list, int max)
{
    list->reserve(max); // This pre-allocates space for max elements in the QList to optimize performance. By reserving memory in advance, the list won't need to repeatedly resize as elements are appended.
    for(int i = 0; i < max; i++)
    {
        int value = QRandomGenerator::global()->bounded(1000); // QRandomGenerator::global() method returns a globally available random number generator
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    randoms(&list,10);

    qInfo() << "Unsorted:" << list;

    //qSort - do not use

	// This uses the C++ standard library function std::sort() to sort the list in ascending order.
    std::sort(list.begin(),list.end());
    qInfo() << "Sorted:" << list;

	// This reverses the order of the elements in the list. 
    std::reverse(list.begin(),list.end());
    qInfo() << "Reversed:" << list;




    return a.exec();
}
