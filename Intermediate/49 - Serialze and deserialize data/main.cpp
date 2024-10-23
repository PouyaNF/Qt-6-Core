/*

  Serialze and deserialize data

  How
  QDataStream and QFile
  
  Serialization is the process of converting an object or data structure into a format that can be easily 
  stored or transmitted, such as a binary format, XML, JSON, or other structured text forms. 
  The serialized data can then be saved to a file, sent over a network, or passed between different 
  systems or applications. When the data is needed again, it can be deserialized (reconstructed) back 
  into its original form.


  

  Serialization in Qt refers to the process of converting an object or data structure into a format that 
  can be easily stored or transmitted and later reconstructed. This is particularly useful for saving 
  application state, transferring data over a network, or persisting data to files.
	
 */

#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

bool saveFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file); // Creates a QDataStream object named out that is associated with the file object. This allows for serialized writing of data to the file
    out.setVersion(QDataStream::Qt_6_0); // Sets the version of the QDataStream to Qt 6.0. This is important for maintaining compatibility when reading the data back.

    QString title = "The answer is 42!";
    qint64 num = 42;

    out  << title; // Serializes the title string and writes it to the file using the QDataStream.
    out << num;   // Serializes the num integer and writes it to the file.

    file.close();

    return true;
}

bool readFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_0)
    {
        qCritical() << "Versions do not match";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;  // Deserializes the title string from the file and stores it in the title variable.
    in >> num;  // Deserializes the num integer from the file and stores it in the num variable.

    qInfo() << title;
    qInfo() << num;

    file.close();

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = "test.txt";

    if(saveFile(file)) {
        qInfo() << "Saved!";
        readFile(file);
    }


    return a.exec();
}
