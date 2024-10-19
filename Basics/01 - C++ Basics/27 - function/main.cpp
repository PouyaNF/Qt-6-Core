/*
    Intro to functions

*/

#include <QCoreApplication>
#include <QDebug>

void test()
{
    qInfo() << "Hello from test";
}


void test2()
{
    qInfo() << "Hello from test2";
    test();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //test();
    test2();   // "Hello from test2"   "Hello from test"

    return a.exec();
}



