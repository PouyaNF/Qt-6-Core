/*
 

  QObject::moveToThread
  In Qt, QObject::moveToThread is a method that transfers a QObject to a different thread,
  allowing it to execute its tasks in that thread instead of the main (GUI) thread. 
  This approach is essential for making applications responsive, as it allows long-running 
  or background tasks to operate in a separate thread, avoiding blocking the main thread.
  

 */

#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QScopedPointer>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThread worker;
    worker.setObjectName("Worker Thread");

    qInfo() << "Starting work" << QThread::currentThread(); // is the main thread.
    //Task *task = new Task(&a);
    QScopedPointer<Task> t(new Task()); // QScopedPointer is used to manage the Task object, ensuring it will be automatically deleted when it goes out of scope, preventing memory leaks.
    Task *task = t.data();  //  assigns a raw pointer to the Task object managed by QScopedPointer 
    task->moveToThread(&worker); // that task’s methods, when executed via signals/slots, will now run in worker rather than in the main thread.

	// Connects the worker thread’s started signal to the work method of the task.
    worker.connect(&worker,&QThread::started, task,&Task::work);
	
    //Connect to QThread::finished if you need to know when the thread is done

    worker.start(); // The worker thread is started, which will trigger the connected task->work() method to execute in worker.
    qInfo() << "Free to do other things..." << QThread::currentThread(); // the main thread is free to handle other tasks while worker handles task operations in the background.

    return a.exec();
}
