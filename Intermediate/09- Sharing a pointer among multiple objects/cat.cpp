#include "cat.h"

Cat::Cat(QObject *parent, QString name) : QObject(parent)
{
    setObjectName(name);
    qInfo() << "Constructed" << this;
}

Cat::~Cat()
{
    qInfo() << "Deconstructed" << this;
}

void Cat::play(QSharedPointer<Toy> toy)
{
	// performs a swap operation between the current toy object 
	// (m_toy, a member variable of the Cat class) and the new toy 
	// object passed as an argument (toy).
    m_toy.swap(toy);
    qInfo() << this << "Playing with" << m_toy.data();
}
