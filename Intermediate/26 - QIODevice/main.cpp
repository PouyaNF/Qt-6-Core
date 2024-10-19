/*

  
  QIODevice

  QIODevice is the abstract base class of all IO devices
  
  Classes like QFile, QBuffer, and QTcpSocket inherit from QIODevice, which means they implement and extend its 
  functionality to handle specific types of data sources. For example, QFile handles file I/O, QBuffer works with
  data stored in memory (like a QByteArray), and QTcpSocket deals with network communication.

  QBuffer: is a class in Qt that provides a way to use a QByteArray as a device for I/O operations, similar to how you would
  use a file or network socket. It allows you to read from and write to a byte array in memory as if it were a file.

  
 */

#include <QCoreApplication>
// provides the base class for all I/O devices.
#include <QIODevice>
// is used for in-memory data handling as if it were a file.
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	// A QBuffer object named buffer is created.
    QBuffer buffer;
	// The buffer is opened in read-write mode using buffer.open(QIODevice::ReadWrite). This prepares the buffer for both reading and writing operations.
	// If the buffer opens successfully, it prints "Device is open" using qInfo().
    if(buffer.open(QIODevice::ReadWrite))
    {
        qInfo() << "Device is open";

        QByteArray data("Hello world");
		
		// A loop runs 5 times, each time writing the contents of data to the buffer, followed by a newline ("\r\n"). 
        for(int i = 0; i < 5; i ++)
        {
            buffer.write(data);
            buffer.write("\r\n");
        }
		
		// What it does: This method forces any buffered data to be written to the underlying device immediately. 
		// In the case of QBuffer, which works directly with memory (a QByteArray), flush() is not strictly necessary 
		// because data is directly written to memory without any intermediate buffering.
        //buffer.flush();
		
		
		// moves the read/write pointer to the beginning of the buffer. To read the data from the beginning, you need to reset the position to 0.
        buffer.seek(0);
		//  reads all the data from the buffer and prints it using qInfo().The output will display "Hello world" repeated 5 times, each on a new line.
        qInfo() << buffer.readAll();
		
        qInfo() << "Closing buffer...";
		// Closing the buffer is a good practice to ensure that all resources are properly released, especially when you're done using it. 
        buffer.close();
    }
    else
    {
        qInfo() << "Could not open the device";
    }

    qInfo() << "Finished";

    return a.exec();
}
