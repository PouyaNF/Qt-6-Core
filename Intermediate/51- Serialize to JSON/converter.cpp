#include "converter.h"

Converter::Converter(QObject *parent) : QObject(parent)
{

}

void Converter::writeJson(Test *obj, QString path)
{
	// QVariantMap: dictionary-like structure
    QVariantMap map; // Creates a QVariantMap named map. This will hold the data to be serialized into JSON.
    QVariantMap items; // This will store key-value pairs from the Test object's internal map.
    map["name"] = obj->name(); // Inserts the name property of the Test object into the map
    foreach(QString key, obj->map().keys()) //  Iterates over each key in the Test object's internal map (assumed to be a method returning a QMap or similar).

    {
        items.insert(key, QVariant(obj->map().value(key)));
    }

    map["items"] = QVariant(items); // Inserts the items map into the map under the key "items".

    QJsonDocument document = QJsonDocument::fromVariant(map); // Creates a QJsonDocument from the map
	
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Could not write file!";
        qCritical() << file.errorString();
        return;
    }

    file.write(document.toJson());  // Writes the JSON representation of the document to the file.
    file.close(); // Closes the file to ensure all data is written and resources are released.
}


Test *Converter::readJson(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not read file!";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data);
    Test *t = new Test();
    t->setName(document["name"].toString());
	
    QVariantMap vmap = qvariant_cast<QVariantMap>(document["items"]);

    QMap<QString,QString> map;
    foreach(QString key, vmap.keys())
    {
        map.insert(key,vmap[key].toString());
    }
    t->setMap(map);

    return t;
}
