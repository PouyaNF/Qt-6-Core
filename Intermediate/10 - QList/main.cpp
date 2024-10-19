/*  
    QList
	
	QList is a dynamic array class in the Qt framework that provides a flexible 
	and type-safe way to store and manipulate collections of objects. 
	It allows for automatic resizing, efficient indexing, and quick access to 
	elements using methods like append(), prepend(), and removeAt(). 
	As a template class, QList can hold any data type, supports copy-on-write 
	semantics for performance, and integrates seamlessly with Qt's meta-object
	system. Its user-friendly interface and dynamic memory management make QList
	a popular choice for developers working on Qt applications.
*/

#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	// QList<int> list;: This declares a QList of integers, named list
    QList<int> list;

    // overloaded << operator to append the integers 1, 2, and 3 to the list.
    list << 1 << 2 << 3;

    for(int i = 0; i < 5; i++)
    {
        list.append(i);
    }

    qInfo() << list;

    qInfo() << "Length" << list.length();
	// This prints the size of the list. In the context of QList, size() and length() return the same value
    qInfo() << "Size" << list.size();
	// This prints the count of elements in the list, which is equivalent to its length or size.
    qInfo() << "Count" << list.count();
	// This prints the number of times the integer 4 appears in the list.
    qInfo() << "Count" << list.count(4);
	//  This replaces the value at index 2 in the list with 99. The new list would be 1, 2, 99, 0, 1, 2, 3, 4.
    list.replace(2,99);
	// The list now contains 1, 2, 99, 0, 1, 2, 3, 4, 3, 3, 3.
    list << 3 << 3 << 3;
	// This removes the first occurrence of the integer 3 from the list.
    list.remove(3);
	// foreach is used to iterate over collections, such as QList, QVector, and other containers. It simplifies the syntax for iterating over elements compared to traditional for-loops
    foreach(int i, list)
    {
        qInfo() << i;
    }
	// This removes all occurrences of the integer 3 from the list.
    list.removeAll(3);
	
    for(int i = 0; i < list.length();i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

	//creates a new QList<int> named slice, which contains a sublist of list starting from index 2 and containing 3 elements.
    QList<int> slice  = list.sliced(2,3);

    qInfo() << "Slice" << slice;
    qInfo() << "List" << list;

	// This checks if the integer 6 is present in the list and prints the result (true or false).
    qInfo() << "Contains" << list.contains(6);
	// This attempts to find the index of the integer 6 in the list and prints the index.
    qInfo() << "Indexof" << list.indexOf(6);
	// This removes all elements from the list, effectively making it empty.
    list.clear();
    qInfo() << "Length" << list.length();
    qInfo() << "Size" << list.size();
    qInfo() << "Count" << list.count();


    return a.exec();
}
