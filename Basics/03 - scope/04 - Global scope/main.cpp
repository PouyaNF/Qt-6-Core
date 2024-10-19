/*
    
    Global scope

*/


#include <QCoreApplication>
#include <QDebug>

QString name = "Bryan";

void testing()
{
     qInfo() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    name = "Bob";
    qInfo() << name;  // "Bob"

    bool test = true;
    if(test)
    {
        QString name = "Tammy";
        qInfo() << name;   // "Tammy"
        qInfo() << ::name;   //  :: is scope operator  -  "Bob"
    }

     qInfo() << name;   // "Bob"
     testing();     //   "Bob"

    return a.exec();
}
