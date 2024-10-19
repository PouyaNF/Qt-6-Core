#include "monster.h"

// muliple inheriance - QObject is an ambiguous base of Monster
Monster::Monster(QObject *parent) : QObject(parent), Feline(parent), Canine(parent)
{

}
