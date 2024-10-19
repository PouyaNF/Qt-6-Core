/*

  
  Writing files
  Put data into a file

  using QFile:
  QFile is a class in Qt that provides an interface for file handling, allowing you to work with files on the file system easily.
  It inherits from QIODevice
  File Opening Modes: It can open files in various modes like:
	QIODevice::ReadOnly: Open the file for reading only.
	QIODevice::WriteOnly: Open the file for writing only.
	QIODevice::ReadWrite: Open the file for both reading and writing.
	QIODevice::Append: Open the file for writing and append to the end of the file.
	QIODevice::Truncate: If the file exists, it will be cleared when opened.

 */

#include <QCoreApplication>
#include <QFile>
#include <QDateTime>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; // This file will be created or accessed in the current directory of the application.

	// A QFile object named file is created with the specified filename. This object will be used to open, write, and manage the file.
    QFile file(filename);
	
    if(file.open(QIODevice::WriteOnly))
    {
		// gets the current date and time and converts it to a string. 
        QString now = QDateTime::currentDateTime().toString();

        QByteArray data;
		
		// converts the QString to a byte array using toLocal8Bit() and appends it to data.
        data.append(now.toLocal8Bit());
        data.append(" - ");
        data.append("Hello World");

		// The data byte array is written to the file using file.write(data).
        file.write(data);
        file.close();

        qInfo() << "Wrote to the file";
    }
    else
    {
        qInfo() << file.errorString();
    }


    return a.exec();
}
