/*
    QOBJECT Macro:
	The Q_OBJECT macro in Qt enables essential features like the signals and slots mechanism,
	the meta-object system, and automatic memory management. It allows a class to emit signals
	and connect them to slots, supporting event-driven programming. By including this macro in
	a class, the Qt Meta-Object Compiler (moc) generates extra code for runtime type information,
	dynamic property handling, and object introspection. Without Q_OBJECT, a class cannot use 
	Qt’s event-handling system or leverage reflection capabilities, which are crucial for many Qt
	features.
*/

#include <QCoreApplication>
#include "test.h"

void lifecycle()
{
    Test t;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    lifecycle();

    return a.exec();
}
