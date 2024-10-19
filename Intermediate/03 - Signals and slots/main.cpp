/*
    
    Signals and slots

	a mechanism for communication between objects, where a signal is emitted when a 
	particular event occurs, and slots are functions that respond to these signals. 
	They allow for decoupled event handling, meaning the sender and receiver do not 
	need to know about each other. This system simplifies event-driven programming, 
	enabling flexible and reusable code.
	
	the sender and receiver don’t need to know about each other because they are connected 
	dynamically at runtime via the QObject::connect() method. The connection is established 
	using function signatures (signal and slot names), not direct references between objects. 

*/

#include <QCoreApplication>
#include "test.h"

void notifications()
{
    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    //You have to connect the two objects
    //Dont make multiple connections to the same signal and slot unless you want multiple calls
    //Notice the icons
    //Can have a connection type
    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::AutoConnection);

    mom.testing();
    //child.wake("NOW");
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    notifications();

    return a.exec();
}
