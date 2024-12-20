/*
This code defines a Watcher class that uses Qt's QFileSystemWatcher to monitor changes in the file system,
specifically tracking changes to files and directories. 
 
*/



#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFileSystemWatcher>

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = nullptr);

signals:

public slots:
    void fileChanged(const QString &path);
    void directoryChanged(const QString &path);

private:
    QFileSystemWatcher fsw;
};

#endif // WATCHER_H
