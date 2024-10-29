/*

  What
  Timers

  Why
  We want to wait without blocking execution

  How
  QTimer
  Example of single shot

 */

#include <QCoreApplication>
#include <QTimer>

void test()
{
    qInfo() << "Thank you for waiting!";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Please wait...";
	
	// This line sets up a single-shot timer that will wait 5000 milliseconds (5 seconds) 
	// before calling the test function. The singleShot method triggers the test function 
	// exactly once after the delay.
    QTimer::singleShot(5000,&test);

    return a.exec();
}
