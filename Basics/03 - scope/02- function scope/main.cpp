/*
    
    Function scope

    Functions have their own scope, but share with their parent scope
    Understanding Lexical scope

*/


#include <QCoreApplication>
#include <QDebug>

void test(int number)
{
    //Scope
    number = 50;
    qInfo() << "2 - Number: " << &number << " = " << number;  // 50
}

int main(int argc, char *argv[])
{
    //Scope
    QCoreApplication a(argc, argv);

    int number = 75;
    qInfo() << "1 - Number: " << &number << " = " << number; // 75
    test(number);

    bool ok = true;
    if(ok)
    {
        //Scope
        int number = 1000; // if we do not use int , we modify number in parent scope, but now we define new number =1000, only for this scope
        qInfo() << "3 - Number: " << &number << " = " << number;
    }

    qInfo() << "4 - Number: " << &number << " = " << number;  // 75

    return a.exec();
}
