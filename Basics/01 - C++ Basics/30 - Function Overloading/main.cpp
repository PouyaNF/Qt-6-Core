/*
    Function Overloading

    We want the same name but different params

*/


#include <QCoreApplication>
#include <QDebug>

void test()
{
    qInfo() << "This is a test";
}

// QString is a class designed to handle and manipulate Unicode strings. 
void test(QString name)
{
    qInfo() << "Name:" << name;
}

void test(int age)
{
    qInfo() << "Age:" << age;
}

void test(bool isActive)
{
    qInfo() << "Testing for active";
    if(isActive)
    {
        qInfo() << "Yes it is active";
    }
    else
    {
        qInfo() << "No this is not active";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test(QString("Bryan Cairns"));


    test(false);
    test(42);

    test();
    test(true);

    return a.exec();
}
