/*
	QByteArray:
	QByteArray is a Qt class that represents an array of bytes. 
	It is used to handle binary data and strings in a flexible and efficient way. 
	It can store and manipulate both raw binary data and text data (encoded as ASCII, UTF-8, etc.). 
	QByteArray provides many useful functions for operations such as appending, removing, searching, 
	and modifying byte sequences, as well as for converting data between different formats (like hex and base64).

	QByteArrayView:
	is a class in Qt that provides a non-owning, read-only view of a byte array, similar to how std::string_view works
	for strings in C++. It is useful when you need to work with a subset of a QByteArray or other raw byte data without
	copying it. This helps improve performance and memory efficiency, as it avoids unnecessary allocations and duplications.

	QByteArrayView can be used with various sources, like QByteArray, std::string_view, or raw pointers, 
	making it a flexible option for handling byte data in Qt applications. It’s particularly helpful when 
	you want to pass around byte data to functions without modifying the original array.
	
 */

#include <QCoreApplication>
#include <QByteArray>
#include <QByteArrayView>

void display(QByteArrayView &view)
{
    qInfo() << view;
	// This prints the size of the byte array view (i.e., the number of bytes it contains).
    qInfo() << "Size" << view.size();
	// it interprets the byte sequence as a C-string (const char*) and prints the characters starting from that memory location until a null terminator (\0) is encountered.
    qInfo() << "Data" << view.constData();
	// This creates a slice of the QByteArrayView starting at index 3 and spanning 6 bytes, then prints it.
    qInfo() << "Slice" << view.sliced(3,6);
	// This checks if the QByteArrayView contains the substring "ello" and prints true or false
    qInfo() << "Contains" << view.contains("ello");
	// This prints the byte value at index 1 of the QByteArrayView. If the index is out of range, it throws an exception.
    qInfo() << "At" << view.at(1);
	// This accesses and prints the byte at index 0 using the [] operator. Note that this does not perform range checking
    qInfo() << "Index" << view[0];
	// This searches for the byte 'e' within the QByteArrayView and prints its index. If the byte is not found, it returns -1.
    qInfo() << "Indexof" << view.indexOf('e');

	// This loop iterates over each byte in the QByteArrayView and prints its value.
    for(auto c : view)
    {
        qInfo() << c;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray bytes("Hello world how are you?");
    QByteArrayView view(bytes);

    display(view);

    return a.exec();
}
