/*

  What
  Process timeout

  Why
  We want to kill a process if it takes too long

  How
  See example

 */


#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proc;
    proc.start("xed"); //  launches the xed text editor. If xed is available in the system's PATH, it will open the application.

    QTimer::singleShot(3000,&proc,&QProcess::terminate);

    return a.exec();
}
