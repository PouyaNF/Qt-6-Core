#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    number = 0;
	
	// 	tells the timer to wait for 1000 milliseconds (or 1 second) between each tick.
    timer.setInterval(1000); 
	
	//  links the timer’s timeout signal to our custom timeout function in
    // the Test class. This means that every second, timeout() will be called automatically.
    // This is the object emitting the signal, which in this case is the timer object of type QTimer.
	// &QTimer::timeout: The signal from QTimer.The timeout signal is emitted every time the timer completes its interval (every second, as set by timer.setInterval(1000);).
	// this: The receiver of the signal, which is the current instance of Test (this refers to the Test object).
	// The slot (function) in the Test class that will execute when the timeout signal is emitted.
    connect(&timer,&QTimer::timeout,this,&Test::timeout);
}



// Every second, timeout() increases number by 1, and the current time is printed to the console.
// After 5 seconds (when number reaches 5), the timer is stopped by timer.stop(); to prevent further calls to timeout().
void Test::timeout()
{
    number++;
    //Qt5
    //qInfo() << QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);
    qInfo() << QTime::currentTime().toString(Qt::DateFormat::TextDate); // Print the current time to the console.
	
    if(number >= 5) 
    {
        timer.stop();  // Stop the timer when 'number' reaches 5.
        qInfo() << "Complete!";
    }
}

void Test::dostuff()
{
    number = 0;
    timer.start();
}
