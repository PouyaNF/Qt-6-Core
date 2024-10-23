/*

  What
  Creating message categories

  Why
  We want custom categories with filtering

  How
  QLoggingCategory
  Q_DECLARE_LOGGING_CATEGORY
  Q_LOGGING_CATEGORY
  setFilterRules

 */

#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

//Declares a logging category called network, making it available for use in the application
Q_DECLARE_LOGGING_CATEGORY(network);

// Defines the network category with the identifier "network". This sets up the category to be used in filtering and logging messages
Q_LOGGING_CATEGORY(network,"network");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	// This logs a simple informational message ("test") to the default logging output without using any specific category.
    qInfo() << "test";
	// Logs an informational message in the "network" category
    qInfo(network) << "test";
	// Logs a warning message in the "network" category.
    qWarning(network) << "test";

    //This line sets a filter rule that disables debug-level messages for the "network" category
    QLoggingCategory::setFilterRules("network.debug=false");

    //Will not log
	// Since debug messages are currently disabled for this category, nothing will be logged.
    qDebug(network) << "kitty";

	// Checks if debug messages for the "network" category are disabled.
	//  If they are, the filter rule is updated to enable debug logging.
    if(!network().isDebugEnabled())
    {
		
        QLoggingCategory::setFilterRules("network.debug=true");
        qDebug(network) << "We turned it back on!";
    }

    qDebug(network) << "yes";

    return a.exec();
}
