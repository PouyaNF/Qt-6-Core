/*
    What
    QObject parent child relationships

   In Qt, when a parent object is destroyed, all its child objects are automatically destroyed.
   Therefore, setting up this parent-child relationship helps manage memory efficiently, preventing
   memory leaks.
   
   This code shows how Qt manages memory automatically using parent-child relationships. 
   When an object is deleted, its children are also deleted. 
   This is particularly useful in GUI or application-level programming, where many objects need 
   to be created dynamically but managed efficiently.
   By setting up these relationships, the developer doesn’t need to manually manage the deletion
   of child objects, avoiding memory leaks and making code simpler.

*/


#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "animal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	//Creates a new instance of the Test class and sets a (the QCoreApplication object) as its parent.
	// By setting a as the parent, the parent object (of type Test) will be automatically destroyed when a is destroyed.
    Test *parent = new Test(&a); 
	
	// Creates a new Animal object and sets parent as its parent.
	//This makes the Animal object (parent->dog) a child of the parent object.
    parent->dog = new Animal(parent);
	
	//explicitly deletes the parent object. When this happens, because of the parent-child relationship,
	//the dog object (an instance of Animal) is also destroyed automatically.
	// in this specific code, if the parent object is set as a child of the QCoreApplication
	//instance (a), then deleting parent explicitly may not be strictly necessary because QCoreApplication 
	// will automatically delete all its children when the application exits.
    delete parent; //Deleting

    return a.exec();
    //a decontructed!
}
