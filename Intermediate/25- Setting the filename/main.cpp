/*

  The code explains a straightforward way to manage settings in Qt by manually controlling the settings file location,
  instead of relying on platform-specific defaults like the Windows registry. Developers can specify a filename and format 
  (usually "INI") and store the settings file in a known directory, such as the application's directory. 
  This approach ensures the file is easily accessible and avoids hidden or system-specific storage issues.

  The process involves creating a QSettings object with the specified filename and format. 
  Developers use familiar methods like beginGroup(), setValue(), and value() to store and retrieve settings in a structured
  and human-readable "INI" file. Syncing ensures changes are immediately saved to disk, allowing full control over where and
  how settings are stored.


 */

#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = a.applicationDirPath() + "/settings.ini";
    qInfo() << filename;

    QSettings settings(filename,QSettings::Format::IniFormat);
    settings.beginGroup("people");
    settings.setValue("Bryan",46);
    settings.endGroup();

    settings.sync(); //saving

    settings.beginGroup("people");
    qInfo() << "Tammy:" << settings.value("Tammy",QVariant("Person not found!"));
    qInfo() << "Bryan:" << settings.value("Bryan",QVariant("Person not found!"));
    settings.endGroup();


    return a.exec();
}
