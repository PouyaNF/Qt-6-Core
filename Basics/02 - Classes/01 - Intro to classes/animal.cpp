#include "animal.h"

// QObject(parent): Passing parent to the QObject constructor tells Qt that the Animal object should have the 
// specified parent. This is important because Qt automatically deletes child objects when the parent is destroyed.

Animal::Animal(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";   // this :  printing the memory address of this current object.
}

void Animal::speak(QString message)
{
    qInfo() << this << message;
}
