/*
    
    Pointers vs copies
    Pointers are fast, and we get the actual object

*/

#include <QCoreApplication>
#include <QDebug>

void test(QString value) //Stack - COPY - value would be copied 
{
    qInfo() << &value << "Size:" << value.length();
} //Destrory the copied value 

void testPtr(QString *value) //Stack - Pointing
{
    qInfo() << "P" << value << "Size:" << value->length();
    qInfo() << "A" << &value << "Size:" << value->length();
} //Pointer will be Destroried but not the object 

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "Bryan"; //Stack
    qInfo() << &name << "Size:" << name.length();   // 5 

    test(name);
    testPtr(&name);

    return a.exec();
}
