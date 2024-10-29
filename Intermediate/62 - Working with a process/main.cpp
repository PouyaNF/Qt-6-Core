/*

  What
  Working with a process

  Why
  We want to see the exit code

 This program demonstrates how to start an external process, in this case, opening a URL in 
 the text editor xed (default text editor on some Linux systems), using Qt's QProcess. 
 It also retrieves the process’s exit code to check if it executed successfully.
 
 every process managed by QProcess has an exit code.

 */

#include <QCoreApplication>
#include <QDebug>
#include<QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Starting...";
    QProcess proc;
    proc.execute("xed",QStringList() << "http://www.voidrealms.com"); // This command runs xed with the argument "http://www.voidrealms.com". The execute() method blocks the current thread until the process completes.
    qInfo() << "Exit code: " << proc.exitCode(); //Logs the exit code of the process. An exit code of 0 indicates success, meaning xed executed without errors.

    return a.exec();
}
