/*

  Looking at QSettings

  Why
  Its super easy to save application settings

	
  allows developers to store and retrieve application settings in a platform-independent way. 
  It is commonly used to save configuration settings, user preferences, or any other persistent
  data that needs to be recalled between sessions of an application.
  
  
  The way QSettings saves data depends on the format and platform being used. By default, 
  QSettings uses platform-specific storage:
  On Windows, it typically saves data in the system registry.
  On macOS and Linux, it may use configuration files in system-specific locations like .plist files or .conf files.
  However, if you explicitly set the format to something like INI format (which is platform-independent), 
  it saves the data in a flat file with a .ini extension. So the behavior can vary based on whether you use 
  the native format (default) or a specified format like INI.


 */

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>


// This is a function that accepts a reference to a QSettings object and outputs information about the settings.
void info(QSettings &settings)
{
	// Outputs the file location or registry key where the settings are being stored. 
	// On Windows, this might be in the system registry; on Linux/macOS, this could be a config file.
    qInfo() << "File:" << settings.fileName();
	// Outputs all the keys that have been stored in the settings. 
    qInfo() << "Keys:" << settings.allKeys();
}


// This function saves a value to the settings and outputs status messages.
void save(QSettings &settings)
{
	// Stores the key "test" with the value 123 in the settings.
    settings.setValue("test",123);
	// Outputs the status of the QSettings object, such as whether the settings file or registry key is valid and writable.
    qInfo() << settings.status();
    qInfo() << "Saved";

}

// This function loads and reads values from the settings and outputs the results.
void load(QSettings &settings)
{
    info(settings);

	// Retrieves the value for the key "test" from the settings and outputs it as a string. 
	// If the key does not exist, it returns a default empty value.
    qInfo() << settings.value("test").toString();
	
	// Retrieves the value for the key "test" and attempts to convert it to an integer. 
	// The conversion status (whether successful or not) is stored in the ok variable.
    bool ok;
    qInfo() << settings.value("test").toInt(&ok);
    if(!ok)
    {
        
        qInfo() << "Could not convert to int";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	// This part of the code is setting application-wide metadata that is used by QSettings and potentially
	// other parts of the Qt framework. These settings define the organization and application-specific information
    //	for the application.
    QCoreApplication::setOrganizationName("Voidrealms");
    QCoreApplication::setOrganizationDomain("Voidrealms.com");
    QCoreApplication::setApplicationName("Tester");

	// Creates a QSettings object using the organization and application names. This settings object will handle loading and saving settings for this application.
    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());
    if(settings.allKeys().length() == 0)
    {
        qInfo() << "No setting...saving...";
        save(settings);
    }
    else
    {
        qInfo() << "Loading the settings...";
        load(settings);
    }

    return a.exec();
}
