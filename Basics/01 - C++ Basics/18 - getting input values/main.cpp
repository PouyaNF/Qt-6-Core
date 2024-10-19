/*
	Getting input values
*/

#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string name;
    int age;

    cout << "Enter your name:" << endl;
    cin >> name;

    cout << "Enter your age:" << endl;
    cin >> age;

    qInfo() << name.c_str() << "is" << age << "years old";

    return a.exec();
}
