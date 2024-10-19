/*

  QStringView

  Why
  Read only (fast access) to a QString

  In Qt, the term "view" typically indicates that the data is read-only, meaning it is used to display or 
  access information without modifying it. This concept is related to model-view-controller (MVC) programming
  but focuses on read-only access. For example, a QStringView is a read-only subset of a QString, allowing you 
  to view and display the string without directly modifying the original data. It’s important to note that a view 
  points to the actual data without owning it, maintaining its read-only nature.
  
  
  QStringView:
  Designed specifically for handling UTF-16 encoded text (the format used by QString in Qt).
  Suitable for working with textual data where characters are encoded using Unicode, supporting internationalization and 
  different character sets.
  QByteArrayView:
  Designed for raw byte sequences, which can represent binary data or text encoded in any format (e.g., ASCII, UTF-8).
  Used for handling raw data directly, making it suitable for file data, network packets, or binary buffers where no specific text encoding is assumed.
  
  

 */

#include <QCoreApplication>
#include <QString>
#include <QStringView>

void display(QStringView &view)
{
    qInfo() << view;

    qInfo() << "Size" << view.size();
    qInfo() << "Data" << view.constData();
    qInfo() << "Slice" << view.sliced(3,6);
    qInfo() << "Contains" << view.contains(QString("ello"));
    qInfo() << "Count" << view.count('l');
    qInfo() << "At" << view.at(1);
    qInfo() << "Index" << view[0];
    qInfo() << "Indexof" << view.indexOf('e');

    for(auto c : view)
    {
        qInfo() << c;
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello world how are you today?";

    QStringView view(data);
    display(view);

    return a.exec();
}
