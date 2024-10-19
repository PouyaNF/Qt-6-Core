/*
	The difference between passing objects by copy (test) and by pointer (testPtr).
	
	Proper memory management when using heap allocation (getObject and delete p).

*/

//QCoreApplication is the base class for non-GUI applications. 
//It manages application control flow and settings.
#include <QCoreApplication>
#include <QDebug>


// a copy of the object is made when this function is called.
// Copying QObject objects is not recommended in Qt, and it might produce unexpected behavior.
// Q_FUNC_INFO is a predefined macro that outputs the function signature for debugging.
void test(QObject object) //Copy
{
    qInfo() << &object << Q_FUNC_INFO;
}


// It does not create a copy 
void testPtr(QObject *object) //Pointer
{
    qInfo() << object << Q_FUNC_INFO;
}

//QObject getObject()
//{
//    QObject o;
//    return o; //return a copy
//}

QObject* getObject()
{
    QObject *o = new QObject(); //Warning, creating in the heap
    return o;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	// The object now resides on the heap.
    QObject* p = getObject();
	
    testPtr(p);

    delete p;

    return a.exec();
}
