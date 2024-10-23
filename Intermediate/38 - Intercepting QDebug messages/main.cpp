/*

  
  Intercepting QDebug messages

  The process for intercepting and logging messages in a Qt application using a message handler. 
  
  intercepting messages like info, debug, warning, and critical messages in real-time allows them to be 
  logged into a file for later analysis, especially when an application crashes. 
  The method involves setting up a custom message handler function using qInstallMessageHandler and writing
  logs to a file using QTextStream to capture details such as message type, date-time, file name, and line
  number. 
  
  
This code sets up a simple Qt application that logs messages to a file and still displays them in the console as usual.
  
 */

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

// This line saves Qt’s default message handler so we can still use it later, even after we create our custom message handler.
const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

// custom message handler.
void lhandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

    QString txt;
	
	// decides how to label each type of message 
    switch (type) {
    case QtInfoMsg:
        txt = QString("Info: %1").arg(msg);
        break;
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtCriticalMsg:
        txt = QString("Critical: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        break;
    }
	// This section opens a file called "log.txt" and adds new messages to it
    QFile file("log.txt");
    if(file.open(QIODevice::Append)) {
        QTextStream ts(&file);
        ts << QDateTime::currentDateTime().toString() << " - " << txt << " file: " << context.file << " line: " << context.line << "\r\n";
        ts.flush();
        file.close();
     }

	// This calls the original Qt message handler so that the message still shows up in the console or wherever it normally would.
	// It ensures that our custom handler doesn’t replace the default behavior but adds to it.
    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInstallMessageHandler(lhandler);

    qInfo() << "This is a info message";
    qDebug() << "This is a debug message";
    qWarning() << "This is a warning message";
    qCritical() << "This is a critical message";
    qFatal("THIS IS SPARTA!!!");

    return a.exec();
}
