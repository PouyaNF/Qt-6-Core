/*

  What
  Filling a container

  Why
  We want to populate a container

  How
  qFill is deprecated
  use a QList or STD fill

 */

#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 1 << 2 << 3 << 4; // This appends the integers 1, 2, 3, and 4 to the list using Qt's operator <<

   // qFill() = do not use

    list.fill(9); // This replaces all elements in the list with the value 9
    qInfo() << list; // [9, 9, 9, 9]

    list.resize(12); // Resizes the list to hold 12 elements. The first four elements remain unchanged (as 9), and the newly added elements will be initialized to 0.
    std::fill(list.begin(),list.end(),-1); // This uses the std::fill algorithm from the C++ standard library to set all the elements in the list to -1
    qInfo() << list; // [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

    return a.exec();
}
