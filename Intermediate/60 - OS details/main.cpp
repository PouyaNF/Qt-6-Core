/*

  What
  Look at the OS details

  Why
  We want to know what we are running on

  How
  QSysInfo : a class that provides system-related information.
  
  This Qt application retrieves and displays various system information using the QSysInfo class,
  demonstrating how to access platform-specific data in a cross-platform way.
  The use of conditional compilation ensures that platform-specific code can be included or excluded 
  based on the target operating system.


 */

#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System Info";
    qInfo() << "Boot Id: " << sys.bootUniqueId(); // Logs the unique identifier for the current boot session of the system.
    qInfo() << "Build: " << sys.buildAbi(); // Logs the Application Binary Interface (ABI) used to build the application.
    qInfo() << "Cpu: " << sys.buildCpuArchitecture(); // Logs the architecture of the CPU, such as x86_64 or ARM.
    qInfo() << "Kernel: " << sys.kernelType(); // Logs the type of the operating system kernel (e.g., Linux, Windows, etc.).
    qInfo() << "Version: " << sys.kernelVersion(); //  Logs the version of the operating system kernel currently in use.

    //Qt 5
    //qInfo() << "Mac: " << sys.macVersion();
    //qInfo() << "Windows: " << sys.windowsVersion();

    qInfo() << "Host: " << sys.machineHostName();  // Logs the host name of the machine.
    qInfo() << "Product: " << sys.prettyProductName(); // Logs a human-readable name of the product (e.g., Ubuntu, Windows 10).
    qInfo() << "Type: " << sys.productType(); // Logs the type of the product (e.g., operating system type).
    qInfo() << "Version: " << sys.productVersion(); // Logs the version of the product (e.g., version number of the OS).

// Conditional Compilation: This section checks the operating system the code is being compiled on:
#ifdef Q_OS_LINUX  // If it's Linux, it logs "Linux code here".
    qInfo() << "Linux code here";  
#elif defined(Q_OS_WIN)
    qInfo() << "Windows code here";
#elif defined(Q_OS_MACX)
    qInfo() << "Mac code here";
#else
    qInfo() << "Unknown OS code here";
#endif


    return a.exec();
}
