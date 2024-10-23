/*

  What
  UTF8

  Why
  UTF-8 uses one to four bytes to represent each character

  How:
	1 byte (8 bits): for standard ASCII characters (0-127), which includes letters, numbers, and basic punctuation.
	2 bytes (16 bits): for additional characters, such as Latin letters with diacritics and some symbols.
	3 bytes (24 bits): for most common characters, including those from languages like Greek, Cyrillic, and many more.
	4 bytes (32 bits): for rare characters, including many emoji and characters from less common languages.

  The encoding is defined by the Unicode standard, and was originally designed by Ken Thompson and Rob Pike.
  Called "Unicode"
 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

QString makeData()
{
    QString data;
    data.append("Unicode test\r\n");

	//  loop runs 10 times to append random Unicode characters to data
    for(int i = 0; i < 10; i++)
    {
        int number = QRandomGenerator::global()->bounded(1024);
        data.append(QChar(number));
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    qInfo() << data;

    QFile file("data.txt");
	
    if(file.open(QIODevice::WriteOnly)) {

		// Creates a QTextStream object to write to the file.
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf8);
        stream << data;
		// Ensures all data is written to the file before closing it.
        stream.flush();

        file.close();
    }

    qInfo() << "Done";
    qInfo() << "UTF8: " << data;
	
	// Attempts to convert the data to ASCII (Latin-1) format and outputs it. 
	// Characters that are not representable in ASCII will be replaced with a question mark (?).
    qInfo() << "ASCII: " << data.toLatin1();  

    return a.exec();
}
