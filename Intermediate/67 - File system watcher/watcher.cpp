


#include "watcher.h"

Watcher::Watcher(QObject *parent) : QObject(parent)
{
    fsw.addPath(QDir::currentPath()); // Monitor the current directory.
    fsw.addPath(QDir::currentPath() + QDir::separator() + "test.txt"); // Monitor a specific file, 'test.txt'.

	// Connect the signals to the corresponding slots.
    connect(&fsw,&QFileSystemWatcher::fileChanged, this, &Watcher::fileChanged);
    connect(&fsw,&QFileSystemWatcher::directoryChanged, this, &Watcher::directoryChanged);
}

void Watcher::fileChanged(const QString &path)
{
    qInfo() << "File changed: " << path;
    if(fsw.files().length())    // // Check if there are any monitored files that have changed.
    {
        qInfo() << "Files that have changed:";
		
		// Iterate through the list of changed files: Log each changed file.
        foreach(QString file, fsw.files())
        {
            qInfo() << file;
        }
    }
}


void Watcher::directoryChanged(const QString &path)
{
    qInfo() << "Dir changed: " << path;
    if(fsw.directories().length())
    {
        qInfo() << "Dir that have changed:";
        foreach(QString dir, fsw.directories())
        {
            qInfo() << dir;
        }
    }
}
