#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

class Animal : public QObject // QObject: base class in Qt that provides core functionality 
{
    Q_OBJECT  // micro that enables the class to use Qt's meta-object features like signals, slots, and properties.

public:
    // The QObject *parent part allows you to specify a parent for your Animal object if you want.
    // The nullptr part means that, by default, if you don’t give the object a parent, it will have 
    // no parent, and you'll need  to delete it yourself when you're done with it.
    explicit Animal(QObject *parent = nullptr); 
    void speak(QString message);


// Signals are special messages that an object can send when something happens, like a button being clicked 
//or a task being completed.
signals:

};

#endif // ANIMAL_H
