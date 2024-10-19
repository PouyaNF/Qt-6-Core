/*
    
    Data types:  We need to tell C++ what type of thing we are working with
    
    https://www.w3schools.com/cpp/cpp_data_types.asp
    https://www.geeksforgeeks.org/c-data-types/


	Problem: assigning a double value (44.90) to an int variable (age). 
	In C++, assigning a floating-point value to an integer variable will truncate (remove) the decimal part,
	leading to age becoming 44 (since 44.90 truncates to 44).
	Explanation: This is not a syntactic error, but it can lead to loss of data or unexpected behavior. 
	It’s generally best to use the correct type for the data you are working with. 

	Problem: You assign a negative value (-1) to an unsigned int variable (cats). Unsigned integers cannot
	represent negative values. When you assign a negative value to an unsigned integer, it will wrap around
	and produce a large positive number due to underflow.
	Explanation: In your case, -1 will be stored as the maximum value representable by unsigned int
	(often 4294967295 for a 32-bit system). This can lead to confusing results and potential bugs. 
	Use int if you need to handle negative numbers.


	
*/

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age = 44;
    double height = 6.02;

    qInfo() << "Age:" << age;
    qInfo() << "Height:" << height;

    age = 44.90;  // Problem here :  
    qInfo() << "Age:" << age;

    signed int dogs = -1;
    qInfo() << "Dogs:" << dogs;
    dogs = 15;
    qInfo() << "Dogs:" << dogs;

    unsigned int cats = -1;  // Problem here
    qInfo() << "Cats:" << cats;
    cats = 15;
    qInfo() << "Cats:" << cats;

    qInfo() << sizeof(dogs);
    qInfo() << sizeof(cats);
    qInfo() << sizeof(height);

    return a.exec();
}
