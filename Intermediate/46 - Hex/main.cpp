/*

  What
  Hex

  Why
  Hexadecimal numeral system is a positional numeral system that represents numbers using a radix of 16

  How
  QByteArray again!

 */

#include <QCoreApplication>
#include <QDebug>

QString makeData() {
    QString data;
    for(int i = 0; i < 10; i++) {
        data.append("Hello\r\n");
    }
    return  data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
	// Converts the QString data into a QByteArray using UTF-8 encoding, which represents the string in a binary format.
    QByteArray bytes(data.toUtf8());
	// Converts the binary data from bytes to a hexadecimal representation, where each byte is represented by two hexadecimal digits.
    QByteArray encoded = bytes.toHex();
	// Decodes the hexadecimal data back into the original binary format 
    QByteArray decoded = QByteArray::fromHex(encoded);

    qInfo() << "Encoded:" << encoded;
    qInfo(" --------------------------------------- ");
    qInfo() << "Decoded:" << decoded;

    return a.exec();
}
