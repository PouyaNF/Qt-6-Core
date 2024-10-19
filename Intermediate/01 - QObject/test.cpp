#include "test.h"

//  constructor for the Test class
//  this constructor initializes the Test object and its base class (QObject) with the provided parent,
//  ensuring that the Test object becomes a child of the given QObject

Test::Test(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";
}

Test::~Test()
{
    qInfo() << this << "Deconstructed";
}
