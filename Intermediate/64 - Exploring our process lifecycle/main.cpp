/*

  What
  Exploring our process lifecycle

  Why
  To see how we interact with the world

  How
  main function
  QCoreApplication

 */

#include <QCoreApplication>
#include <QTimer>  // Includes QTimer, used here to schedule a delayed action.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Args:";
    for(int i = 0; i < argc; i++)  // Loops through each command-line argument.
    {
        qInfo() << argv[i];  // Prints each argument individually. 
    }

    QTimer::singleShot(6000,&a, SLOT(quit())); // This line schedules a single-shot timer to call the quit slot of QCoreApplication after 6000 milliseconds (6 seconds). This effectively closes the application after 6 seconds.

    int code = a.exec();   //  Starts the event loop and waits for QCoreApplication::quit() to exit it. The return value of exec() typically reflects the exit code.
    qInfo() << "Code" << code;

    return code;
}
