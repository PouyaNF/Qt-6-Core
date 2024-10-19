#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class Source : public QObject
{
    Q_OBJECT
public:
    explicit Source(QObject *parent = nullptr);
	
	// this method, emit mySignal
    void test();

signals:
	// no need to implement a signal 
    void mySignal(QString message); // we dont have to pass pointer in this case (QString  is not a QObject) 
};

#endif // SOURCE_H
