/*

  What
  Reading large files

  Why
  ReadAll is not a great idea
  Break it into smaller parts

  How
  QFile::readline
  Qfile::read

 */

#include <QCoreApplication>
#include <QFile>

// This function reads the content of the file line by line
void readLines(QFile &file)
{
	// checks if the file is readable.If it isn’t, the function returns immediately without doing anything.
    if(!file.isReadable()) return;
	// This sets the file’s read/write pointer to the beginning (position 0)
    file.seek(0);

    while(!file.atEnd())  // The loop continues until the end of the file is reached.
    {
		// Reads a line from the file using file.readLine()
        qInfo() << file.readLine(); // \n
    }
}

// This function reads the file in chunks of 25 bytes
void readChunks(QFile &file)
{
    if(!file.isReadable()) return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.read(25);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; //create this manually

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) //reads the file can not modify it
    {
        //Read line by line
        readLines(file);


        qInfo() << "-------------------";

        //Read chunks
        readChunks(file);

        file.close();

    }
    else
    {
        qInfo() << file.errorString();
    }


    return a.exec();
}
