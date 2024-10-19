#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

class Animal : public QObject
{
    Q_OBJECT
public:
    explicit Animal(QObject *parent = nullptr);
    ~Animal();

    static QString name; // every instance of the class can access to this var
    static int count;

signals:

};

#endif // ANIMAL_H
