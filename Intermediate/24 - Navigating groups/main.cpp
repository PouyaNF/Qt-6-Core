/*

  What
  Navigating groups

  Why
  Sometimes we don't know what groups are there

   It uses beginGroup() and endGroup() to structure settings logically and avoid key collisions, even if the same key 
   is used in multiple groups. For instance, keys like "Brian" can exist in both "people" and "beer" groups with distinct
   values. The code demonstrates saving multiple people and random values into a test group and ensuring that changes
   are synced to permanent storage using sync(). By saving keys under separate groups, even with repeated names, the values
   are kept distinct.

   To navigate through groups, childGroups() and childKeys() are used to loop through available groups and keys.
   The text emphasizes the importance of closing groups with endGroup() to prevent issues with accessing the wrong group 
   later, which can lead to bugs that are hard to trace. The example provided shows how the same key, "Brian," can exist
   in multiple groups ("people," "beer," and "test") without causing conflicts, as long as the group context is correctly
   managed.
  
 
*/

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void saveAge(QSettings *setting,QString group, QString name, int age) {
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *setting,QString group, QString name) {
    setting->beginGroup(group);

    if(!setting->contains(name)) {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok) {
        qWarning() << "Failed to convert ot int!!!";
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

    QStringList people;
    people << "Bryan" << "Tammy" << "Heather" << "Chris";

    foreach(QString person, people)
    {
        int value = QRandomGenerator::global()->bounded(100);
        saveAge(&settings,"test",person,value);
    }

    //SAVE
    settings.sync();
    qInfo() << "File:" << settings.fileName();

    foreach(QString group, settings.childGroups())
    {
        settings.beginGroup(group);
        qInfo() << "Group:" << group;
        foreach(QString key, settings.childKeys())
        {
            qInfo() << "... key:" << key << " = " << settings.value(key).toString();
        }


        settings.endGroup();
    }

    return a.exec();
}
