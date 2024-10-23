/*

  What
  File compression

  Why
  Why not!

  How
  Lots of custom code
  make file
  compress file
  decompress file
  NOT COMPATIBLE !!!!

 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QTextStream>

bool makeFile(QString path)
{
	// Creates a QFile object to work with the specified file path.
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QByteArray data;
        for(int i = 0; i < 1000; i++)
        {
            data.append(QString::number(i).toUtf8() + "\r\n");
        }

        file.write(data);
        file.close();

        return true;
    }

    return false;
}

QByteArray getHeader() {
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile); // Creates a QFile object for the new (compressed) file.
    QByteArray header = getHeader(); // Calls getHeader() to retrieve the header for the compressed file.

    if(!ofile.open(QIODevice::ReadOnly)) return false; // Attempts to open the original file in read-only mode. If it fails, return false.
    if(!nfile.open(QIODevice::WriteOnly)) return  false; // Attempts to open the new file in write-only mode. If it fails, return false.
    int size = 1024; // Defines the size of the buffer for reading data from the original file.

    while (!ofile.atEnd()) // Loops until the end of the original file is reached.
    {
        QByteArray buffer = ofile.read(size); // Reads size bytes from the original file into buffer
        QByteArray compressed = qCompress(buffer,9);  // Compresses the read buffer data using qCompress with a compression level of 9 (maximum compression).
        nfile.write(header);
        nfile.write(compressed);
    }

    ofile.close();
    nfile.close();

    qInfo() << "Finished compressing";

    return true;
}

bool decompressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile);
    QByteArray header = getHeader();
    int size = 1024;

    if(!ofile.open(QIODevice::ReadOnly)) return false;
    if(!nfile.open(QIODevice::WriteOnly)) return false;


    //Make sure WE created this file!!!
    QByteArray buffer = ofile.peek(size); //  Peeks at the first size bytes of the original file without moving the read pointer.
    if(!buffer.startsWith(header))
    {
        qCritical() << "We did not create this file!";
        ofile.close();
        nfile.close();
        return false;
    }


    //Find the header positions
    ofile.seek(header.length());  // Moves the read pointer past the header in the original file.

    while (!ofile.atEnd())
    {
        buffer = ofile.peek(size); // Peeks at the next size bytes.
        qint64 index = buffer.indexOf(header);  // Searches for the header within the buffer.
        qDebug() << "Head found at:" << index;  // Outputs the index of the header (or -1 if not found).

        if(index > -1)
        {
            //We found a header
            qint64 maxbytes = index;  // Sets the maximum bytes to read up to the header's position.
            qInfo() << "Reading:" << maxbytes; // Outputs the number of bytes being read.
            buffer = ofile.read(maxbytes);  // Reads the bytes up to the header into buffer.
            ofile.read(header.length());  // Reads past the header.
        }
        else
        {
            //Do not have a header!
            qInfo() << "Read all no header";
            buffer = ofile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        nfile.write(decompressed);
        nfile.flush();
    }

    ofile.close();
    nfile.close();

    return true;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = "orginal.txt";
    QString compressedFile = "compressed.txt";
    QString decompressedFile = "decompressed.txt";

    if(makeFile(originalFile)) {
        qInfo() << "Original created";

        if(compressFile(originalFile, compressedFile)) {
            qInfo() << "File compressed";
            if(decompressFile(compressedFile,decompressedFile)) {
                qInfo() << "File decompressed!";
            } else {
                qInfo() << "Could not decompress file!";
            }
        } else {
            qInfo() << "File not compressed";
        }
    }

    return a.exec();
}
