/*
    
    Hello World
    
    Main function
    Includes
    QCoreAppliction and exec
    CMake
    CMake Modules
*/

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Hello World";

    return a.exec();
}
