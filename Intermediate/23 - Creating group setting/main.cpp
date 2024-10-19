/*
  Creating groups
  
  By using beginGroup() and endGroup(), developers can manage settings in distinct groups,
  ensuring that keys with the same name can coexist without overwriting each other. 
  For instance, if two keys named "Brian" exist in different groups like "people" and "beer,"
  they won’t interfere with each other, allowing for more structured and organized settings.
  
  The process involves defining a group, setting key-value pairs, and always ensuring to end the group
  to avoid confusion later. The same logic applies when retrieving values from the settings.
  You begin by specifying the group, check if the key exists, retrieve the value, and then end the group.
  This methodology allows for complex logic and error handling while making it easier to organize data into
  meaningful groups without conflicts. The main takeaway is that keys are specific to their group, making
  it simple to manage multiple settings in a clean and logical manner.







  
  

 */

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void saveAge(QSettings *setting,QString group,QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *setting, QString group, QString name)
{
    setting->beginGroup(group);

    if(!setting->contains(name))
    {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok)
    {
        qWarning() << "Could not convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("VoidRealms");
    QCoreApplication::setOrganizationDomain("VoidRealms.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings,"people","Bryan",44);
    saveAge(&settings,"beer","twoheart",1);
    saveAge(&settings,"beer","Bryan",11);

    qInfo() << "TwoHeart" << getAge(&settings,"beer","twoheart");
    qInfo() << "Bryan (people)" << getAge(&settings,"people","Bryan");
    qInfo() << "Bryan (beer)" << getAge(&settings,"beer","Bryan");

    return a.exec();
}
