/*

    Qt provides a more organized way to output messages
	qInfo(), qDebug(), qWarning(), qCritical(), and qFatal(): These functions are used for logging various levels 	of messages:
	qInfo(): Informational messages.
	qDebug(): Debugging messages, usually for development.
	qWarning(): Warning messages that indicate potential issues.
	qCritical(): Critical messages indicating severe errors.
	qFatal(): Logs a fatal error message and then terminates the program with a non-zero exit code.

*/

#include <QCoreApplication>
#include <iostream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age = 0;
    qInfo() << "Enter your age:";
    cin >> age;

    qInfo() << "You are" << age << "years old";

    qInfo() << "Information";
    qDebug() << "Debug";
    qWarning() << "Warning";
    qCritical() << "Critical";
    qFatal("Test Crash !!!!");

    return a.exec();
}
