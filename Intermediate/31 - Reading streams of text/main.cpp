/*

  Reading streams of text

  Why
  Encoding!

  How
  QTextStream : Facilitates reading and writing text in a convenient manner, handling character encoding seamlessly.

 */

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>  


void write(QFile &file)
{
	// Checks if the file is writable. 
    if(!file.isWritable())
    {
        qInfo() << "Unable to write to file!";
        return;
    }

	// Creates a QTextStream object that operates on the provided file.
    QTextStream stream(&file);
	
	// Sets the encoding for the stream. This line specifies that the stream will use the last encoding that was set (the specific encoding isn’t explicitly set here). 
	// This is useful for ensuring that the text is written in a compatible format.
    stream.setEncoding(QStringConverter::LastEncoding);
	
	// Moves the write pointer to the end of the file. This ensures that new data is appended to the existing content instead of overwriting it
    stream.seek(file.size());
	
    for(int i = 0; i < 5; i++)
    {
        stream << QString::number(i) << "-Item\r\n";
    }
	// Forces the stream to write any buffered data to the file, ensuring that all content is saved.
    stream.flush();
    qInfo() << "File written";

}

void read(QFile &file)
{
    if(!file.isReadable())
    {
        qInfo() << "Unable to read to file!";
        return;
    }

    QTextStream stream(&file);
    stream.seek(0);
	
    while(!stream.atEnd())
    {
        qInfo() << stream.readLine();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString filename = "test.txt";

    QFile file(filename);
    if(file.open(QIODevice::ReadWrite)) //can read and write
    {

        QTextStream stream(&file);
        qInfo() << "Encoding:" << stream.encoding();

        write(file);
        read(file);

        file.close();

    }
    else
    {
        qInfo() << file.errorString();
    }

    return a.exec();
}
