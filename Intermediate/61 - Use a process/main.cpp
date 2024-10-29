/*

  What
  Use a process

  Why
  Why reinvent the wheel, there are tons of applications

  How
  QProcess 
  QProcess is a class in the Qt framework that allows you to start external programs (processes) 
  and communicate with them. It provides a convenient interface to run and manage these processes,
  enabling you to interact with them through standard input, output, and error streams. 
  
  This code demonstrates how to use QProcess to run the gzip command, which compresses data passed to it. 
  



 */

#include <QCoreApplication>
#include <QProcess>

bool test()
{

    QProcess gzip;  // Create a QProcess object for running the gzip command
    gzip.start("gzip", QStringList() << "-c"); // The gzip command is started with the -c option, which tells gzip to write output to standard output (stdout) instead of creating a file.

    if(!gzip.waitForStarted(3000)) return false; //Waits up to 3 seconds (3000 milliseconds) for the gzip process to start. If gzip fails to start within this time, the function returns false

    QByteArray data; // 
    for(int i = 0; i < 100; i++)
    {
        QString item = "Item " + QString::number(i);
        data.append(item.toUtf8());
    }

    gzip.write(data); // Sends the data to the standard input (stdin) of the gzip process.
    gzip.closeWriteChannel(); // Closes the write channel of the gzip process, indicating no more data will be written.
    if(!gzip.waitForFinished(3000)) return false; // Waits up to 3 seconds for gzip to finish compressing. If gzip does not finish within this time, the function returns false.

    QByteArray result = gzip.readAll(); //  Reads all available output data from gzip after compression, storing it in result.

    qInfo() << "Before: " << data.size();
    qInfo() << "Result: " << result.size();  // smaller due to gzip compression. 
    qInfo() << "Compressed: " << result; 
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(test()) {
        qInfo() << "Compressed with gzip!";
    } else {
        qInfo() << "Failed to use gzip";
    }

    return a.exec();
}
