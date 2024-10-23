/*

  What
  QLoggingCategory

  Why
  Make Logging categories easier

  How
  QLoggingCategory
  
  The code defines a custom logging category (logtest) and controls its behavior by disabling debug messages. 
  It logs different types of messages (debug, info, warning, and critical) to demonstrate how messages are
  filtered based on the category settings. This is useful for organizing and filtering logs in larger 
  applications.

 */

#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	// Creates a logging category named "testing" and stores it in the variable logtest.
    QLoggingCategory logtest("testing");
	// Disables debug messages for the "testing" category. This means any debug messages tagged with this category will not be logged
    logtest.setEnabled(QtMsgType::QtDebugMsg,false);

	// These lines print whether various types of messages (Debug, Info, Warning, and Critical) are enabled for the "testing" category.
    qDebug() << "Debug = " << logtest.isDebugEnabled();
    qInfo() << "Info = " << logtest.isInfoEnabled();
    qWarning() << "Warning = " << logtest.isWarningEnabled();
    qCritical() << "Critical = " << logtest.isCriticalEnabled();

	// These lines log messages using the "testing" category
    qDebug(logtest) << "This is a debug"; // Attempts to log a debug message. Since debug messages are disabled, this will not appear.
    qInfo(logtest) << "This is a info"; //  Logs an info message, which will appear because info messages are enabled by default.
    qWarning(logtest) << "This is a warning";
    qCritical(logtest) << "This is a critical";

    return a.exec();
}
