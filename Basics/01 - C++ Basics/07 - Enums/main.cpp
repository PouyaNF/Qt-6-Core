/*
    
    Enums

    Need to represent a set of data

*/


#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    enum Color {red = 100,green = 55,blue = 256};

    Color mycolor = Color::red;

    qInfo() << "Color" << mycolor; // 100

    return a.exec();
}
