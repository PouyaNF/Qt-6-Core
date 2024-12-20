/*
    
    Getting the parent and children: 
    Finding objects next to you in the tree


*/

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    parent.setObjectName("Parent");

    QObject child;
    child.setObjectName("Child");

    child.setParent(&parent);

    //Get the parent
    qInfo() << child.parent();

    //get the children
    qInfo() << parent.children();

    foreach(QObject* obj, parent.children())
    {
        qInfo() << obj;
    }

    return a.exec();
}
