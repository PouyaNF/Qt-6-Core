/*
  QThreadPool:
  QThreadPool in Qt is a class that manages a pool of reusable threads for handling
  concurrent tasks. Rather than creating and managing individual threads manually,
  QThreadPool can automatically manage a set of threads, making it easier and more 
  efficient to run multiple tasks simultaneously.

 */

#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
	
    qInfo() << "Starting work" << QThread::currentThread(); 

    qInfo() << "Max Threads" << QThreadPool::globalInstance()->maxThreadCount(); // returns the maximum number of threads the pool can run concurrently. By default, this is set based on the system's CPU cores but can be adjusted as needed.


    for(int i = 0; i < 50; i++)
    {
        Task *task = new Task();
        task->setAutoDelete(true);  // ensures each task is automatically deleted after it completes, preventing memory leaks.
        QThreadPool::globalInstance()->start(task); //  submits each Task instance to the global thread pool, allowing it to execute when a thread becomes available.
    }


    qInfo() << "Free to do other things" << QThread::currentThread(); // main thread is not blocked by the tasks and is free to perform other operations or exit.

    return a.exec();
}
