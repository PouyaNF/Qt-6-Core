/*

 In Qt, threads allow you to perform tasks concurrently, which can be especially useful
 for handling time-consuming operations without blocking the main GUI thread. Qt offers 
 various classes and mechanisms for working with threads, with QThread being the central
 class to create and manage threads.

 Key Concepts
 Main (GUI) Thread: In a Qt application, the main thread runs the event loop and is 
 responsible for handling GUI updates. Any long-running task in this thread can make 
 the application unresponsive.

 QThread: This class represents a single thread of execution. By subclassing QThread 
 or moving an object to a new QThread, you can run code in parallel with the main thread.

 moveToThread(): Objects can be moved to different threads using this function. This is 
 helpful for running specific tasks in a separate thread without subclassing QThread.

 Signals and Slots: Qt’s signals and slots provide a safe way to communicate between threads. Emitting signals across threads is safe, and Qt handles synchronizing data between threads.

 */

#include <QCoreApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *thread = QThread::currentThread();  // retrieves a pointer to the currently running thread, which in this case is the main thread.
    thread->setObjectName("Main Thread"); //  assigns a human-readable name, "Main Thread", to this thread. 

    qInfo() << "Starting" << thread;

    for(int i = 0; i < 10; i++)
    {
        qInfo() << i << "on" << thread;
    }
    qInfo() << "Finished" << thread;



    return a.exec();
}
