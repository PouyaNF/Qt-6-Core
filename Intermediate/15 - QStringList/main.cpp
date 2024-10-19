/*

  QStringList in Qt is a container class that stores a list of strings (QString objects).

  QStringList is specifically designed for handling lists of strings, and it inherits from QList<QString>. 
  It offers additional, convenient functions like join(), filter(), and replaceInStrings(), which are not
  available in QList<QString>.

  QStringList inherits from QList<QString>.

 */

#include <QCoreApplication>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList names {"Bryan"};
    names << "Tammy" << "Rango";
    names.append("Heather");

    names.replaceInStrings("a", "@");
    qInfo() << names;

    names.replaceInStrings("@", "a");
    names.sort();
    qInfo() << names;

	// combines all the strings in the list into a single QString, using a specified separator between each element.
    QString people = names.join(",");
    qInfo() << people;

	// The filter() function in QStringList returns a new list containing all the strings that match 
	// a specified pattern. You can use a substring or a regular expression as the pattern, and it will
	// search through each string in the list.
    QStringList mylist = names.filter("r");
    qInfo() << mylist;

    QString me = "Bryan";
    qInfo() << "Contains:" << names.contains(me);
    qInfo() << "Index:" << names.indexOf(me);
    qInfo() << "Value:" << names.at(names.indexOf(me));


    return a.exec();
}
