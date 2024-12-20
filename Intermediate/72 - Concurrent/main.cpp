/*

  QtConcurrent is a high-level API in Qt designed to simplify running parallel
  tasks without directly managing threads. It allows you to run tasks concurrently 
  and provides easy access to multi-core processing capabilities. QtConcurrent 
  abstracts away the complexity of thread management by automatically managing
  a pool of threads and handling the details of scheduling and execution.


 */

#include <QCoreApplication>
#include <QtConcurrent>
#include <QThread>
#include <QDebug>
#include <QFuture>

int test()
{
    QThread *thread = QThread::currentThread();

    qInfo() << "Starting" << thread;

    int value = 0;
    for(int i = 0; i < 10; i++)
    {
        qInfo() << i << "on" << thread;
        value = value + i;
    }
    qInfo() << "Finished" << thread;

    return value;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<int> future1 = QtConcurrent::run(&test);
    QFuture<int> future2 = QtConcurrent::run(&test);
    QFuture<int> future3 = QtConcurrent::run(&test);

    qInfo() << "Value1" << future1.result();
    qInfo() << "Value2" << future2.result();
    qInfo() << "Value3" << future3.result();

    return a.exec();
}
