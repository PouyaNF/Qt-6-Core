/*

  What
  ASCII

  Why
  No encoding

  How
  You already use it
  http://www.asciitable.com/


 
 Character Encoding:
	Character encoding is a system that pairs each character in a set with a specific numerical value.
	This allows computers to represent text as data.
 
 ASCII (American Standard Code for Information Interchange):
	ASCII is a character encoding standard that uses 7 bits to represent 128 characters, including letters, digits, punctuation, and control characters.
	Each character is assigned a numeric code (0-127). For example, the letter 'A' corresponds to 65, and the space character is represented by 32.
	ASCII supports basic English letters and symbols but lacks characters for other languages and some special symbols.
	ASCII is a 7-bit character set containing 128 characters.
	It contains the numbers from 0-9, the upper and lower case English letters from A to Z, and some special characters.
	The character sets used in modern computers, in HTML, and on the Internet, are all based on ASCII.
	
Printable vs. Non-printable Characters: 
	Printable characters are those that can be displayed on the screen (e.g., letters and numbers), while non-printable characters (like carriage return or line feed) do not produce visible output.
	Examples include the carriage return (CR) and line feed (LF), which are used for formatting text.

Hexadecimal and Octal Representation:
	Characters can also be represented in hexadecimal (base 16) and octal (base 8) numeral systems, providing alternative ways to express character codes.

UTF-8 Encoding:
	UTF-8 is a more modern character encoding standard that is backward compatible with ASCII for the first 128 characters (0-127).
	It allows for the representation of a much larger set of characters, including symbols and characters from non-English languages. This makes it essential for global applications.
	when writing data using Qt, it automatically converts ASCII to UTF-8. 

 */


#include <QCoreApplication>
#include <QDebug>
#include <QFile>


QByteArray makedata()
{
    QByteArray data; // This variable will hold the bytes that are created within the function.
    for(int i = 0; i < 10; i++) {
        data.append(72);   // This appends the byte 72 to data, which corresponds to the ASCII character 'H'
        data.append(101);  // This appends the byte 101, corresponding to the ASCII character 'e'.
        data.append(108);  // This appends the byte 108, corresponding to the ASCII character 'l'.
        data.append(108);  
        data.append(111);   // This appends the byte 111, corresponding to the ASCII character 'o'.
        data.append(33);    // This appends the byte 33, which corresponds to the ASCII character '!'
        data.append(13); // \r :  carriage return (\r), which moves the cursor to the beginning of the line without advancing to the next line.
        data.append(10); // \n

        // \r\n
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makedata();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.close();
    }

    qInfo() << "Done";

    return a.exec();
}
