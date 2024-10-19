/*
    
    Connecting:
	
	In Qt, signals and slots are a key part of its event-driven architecture,
	facilitating communication between objects.

	Signals: These are emitted by objects when a particular event occurs.
	For example, a button might emit a signal when it's clicked. 
	However, signals don't know who is listening for the event; they simply announce
	that something has happened.

	Slots: These are functions designed to respond to signals. 
	When a signal is emitted, Qt checks if any slots are connected to that signal and,
	if so, executes the corresponding slot function.
	
*/

#include <QCoreApplication>
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Source oSource;
    Destination oDestination;

	// Connects the mySignal signal from oSource to the mySlot slot in oDestination. 
	// This means when oSource emits mySignal, oDestination::mySlot will be called.
    QObject::connect(&oSource,&Source::mySignal,&oDestination,&Destination::mySlot);

	//  Triggering Signal Emission
    oSource.test();
	
	// Directly Calling the Slot Method
    oDestination.mySlot("HI!");

    return a.exec();
}
