/* 
QCoreApplication: fundamental class that provides core application functionality.
It's part of the QtCore module, which is essential for all Qt applications

 When you call app.exec(),  it starts the event loop, which keeps running until the application is finished 
(e.g.,when QCoreApplication::quit() is called or when the main window is closed in a GUI application).

Event Loop:  It continually checks for and dispatches events to the appropriate objects in the application.
These events can include user inputs (like mouse clicks or keyboard presses), system messages, and other
 notifications that need to be handled by your application.
*/



#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
