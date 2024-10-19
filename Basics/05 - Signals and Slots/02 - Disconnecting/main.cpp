/*
	This code is a Qt-based C++ console application that simulates a radio system
	with multiple stations. The Radio class listens to signals emitted by Station objects,
	which represent different radio channels. The program interacts with the user through 
	standard input to control the radio (turn it on, off, test it, or quit).
*/

#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	// Creates an instance of the Radio class.
    Radio boombox;
	// Array of 3 pointers to Station objects
    Station* channels[3];
	
	// whether the radio is currently on or off
    bool bOn = false;
    //create some stations : Three stations are created dynamically with different frequencies and names.
    channels[0] = new Station(&boombox,94,"Rock and Roll");
    channels[1] = new Station(&boombox,87,"Hip Hop");
    channels[2] = new Station(&boombox,104,"News");

	// connect(Source, Signal , destination,  Slot) 
	// Connects Signals and Slots:
	// Here, it's trying to connect a signal from the boombox object to a slot in the QCoreApplication 
	// class (which manages the application).
	// &Radio::quit: This indicates the quit signal from the Radio class. It should be emitted when you want to close the application.
	// &QCoreApplication::quit: This is the function that actually quits the application.
	// Qt::QueuedConnection: This specifies how the connection should be made, which can be important for thread safety.
	// &a: Refers to the QCoreApplication object created at the start of the program.(destinattion)
	// Here, it means that the slot will be called in the event loop when the event is processed.
    boombox.connect(&boombox,&Radio::quit,&a, &QCoreApplication::quit,Qt::QueuedConnection); //flaw
	
	// QObject::connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);




    do
    {
		// preprocessing input 
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtin(stdin);   // reading cin 
        QString line = qtin.readLine().trimmed().toUpper();

        if((line == "ON") && (bOn==false)) //if(line == "ON")
        {
            qInfo() << "Turning the radio on";
            for(int i = 0; i< 3; i++)
            {
                Station* channel = channels[i];
				// Connect stations to the radio
                boombox.connect(channel,&Station::send,&boombox, &Radio::listen);
            }
            qInfo() << "Radio is on";
            bOn = true;
        }

        if(line == "OFF")
        {
            qInfo() << "Turning the radio off";
            for(int i = 0; i< 3; i++)
            {
                Station* channel = channels[i];
				
				// disconnect
                boombox.disconnect(channel,&Station::send,&boombox, &Radio::listen);
            }
            qInfo() << "Radio is off";
            bOn = false;
        }

        if(line == "TEST")
        {
            qInfo() << "Testing";
            for(int i = 0; i< 3; i++)
            {
                Station* channel = channels[i];
                channel->broadcast("Broadcasting live!");
            }
            qInfo() << "Test complete";
        }

        if(line == "QUIT")
        {
            qInfo() << "Quitting";
            emit boombox.quit();
            break;
        }


    } while(true);


    return a.exec();
}
