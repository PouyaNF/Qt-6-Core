#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>

class Radio : public QObject
{
    Q_OBJECT
public:
    explicit Radio(QObject *parent = nullptr);
	
// No actual code is written in the signal; it's just a declaration. 
signals:
    void quit();  // A signal is a notification emitted by an object when a particular event occurs to notify other objects

public slots:
    void listen(int channel,QString name, QString message);

};

#endif // RADIO_H
