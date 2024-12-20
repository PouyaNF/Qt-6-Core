/*
    Functions can return values
    
    Return a value
    Return a pointer

	A pointer in C++ is a variable that holds the memory address of another variable.
	A reference is an alias for an already existing variable.

	A reference is initialized to a variable, it cannot be changed to refer to another variable.
	Hence, a reference is similar to a const pointer.

*/

#include <QCoreApplication>
#include <QDebug>

QObject get_object(QString name)
{
    QObject o;
    o.setObjectName(name);
    return o; //Error - Make a copy of that object : In Qt, QObject (and classes derived from it) are non-copyable, meaning they can't be copied directly.   
}

QObject& get_ref(QString name)
{
    QObject o; // local variable On the stack, and will be deleted 
    o.setObjectName(name);
    return o; // Will be deleted : returning a reference leads to undefined behavior
}

QObject* get_ptr(QString name)
{
    QObject *o = new QObject(); //On the heap, we will manage this!
    o->setObjectName(name);
    return o; //Will NOT be deleted
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject o1 = get_object("ByVal");
    QObject o2 = get_ref("ByRef");
    QObject *o3 = get_ptr("ByPtr");
    qInfo() << o3;

    delete o3; //delete that off the heap


    return a.exec();
}
