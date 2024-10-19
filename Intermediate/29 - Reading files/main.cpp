/*

  Reading files

  How to read files

  QFile

 */

#include <QCoreApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString filename = "test.txt";
    QFile file(filename);

    qInfo() << "Exists:" << file.exists();

    if(file.open(QIODevice::ReadOnly))
    {
        //Small files only!!! : it reads the entire file content into memory at once, which can be inefficient for large files.
        qInfo() << file.readAll();

        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    return a.exec();
}
