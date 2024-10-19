/*
    Arrays : std::array
    Multiple values inside one variable

    Pros - easy
    Cons - No range checking
	
	1. C-style Array: int ages[4] = {23,7,34,1000};
	A C-style array is a low-level array that has been part of C and C++ from the start.
	Here's how it works:
	Fixed Size: The size is fixed at compile time (here, 4 elements).
	You cannot resize or dynamically manage the array size once it is declared.

	Direct Memory Access: The array is essentially a block of contiguous memory. 
	Each element is placed right next to the other in memory, and the array name (ages) is a pointer 
	to the first element. This allows direct access to elements by using indices, e.g., ages[0], ages[1], etc.

	Limited Functionality:
	You can't easily get the number of elements in the array. For example, calling sizeof(ages) will return
	the total size in bytes, but not the number of elements unless you manually calculate it (e.g., sizeof(ages) / sizeof(int)).
	You have no built-in bounds checking. 
	Accessing an element outside the bounds of the array (ages[5] in this case) will lead to undefined behavior, potentially causing bugs or crashes.
	It doesn't come with utility functions or features that help with common array operations (like size, copying, or sorting).
	Memory Handling: C-style arrays don't manage their memory or provide mechanisms for dealing with common array operations. You have to manage everything manually.
	
	
*/

#include <QCoreApplication>
#include <QDebug>

#include <array>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // C-style array
    int ages[4] = {23,7,34,1000};
    ages[2] = 99;
    qInfo() << ages[0];
    qInfo() << ages[1];
    qInfo() << ages[2];
    qInfo() << ages[3];
    qInfo() << ages;

	// C++ Standard Template Library (STL) std::array 
    array<int,5> cars;
    cars[0] = 5;
    cars[1] = 67;
    cars[2] = 99;
    cars[3] = 238;
    cars[4] = 56;
    qInfo() << cars[0];
    qInfo() << cars[1];
    qInfo() << cars[2];
    qInfo() << cars[3];
    qInfo() << cars[4];
    //qInfo() << cars;

    qInfo() << "Size:" << cars.size();
    qInfo() << "SizeOf:" << sizeof (cars);
    qInfo() << "Last:" << cars[cars.size() -1];

    return a.exec();
}
