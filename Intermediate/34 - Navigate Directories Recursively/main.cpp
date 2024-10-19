/*

  What
  Navigate Directories Recursively

 This code recursively lists all files and directories starting from the parent directory 
 of the application’s location:

 Directories and Files are differentiated and listed accordingly.
 Recursive Traversal: The list function navigates into each subdirectory,
 inspecting and listing its contents until all directories and files are processed.

 */

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list(QDir &root)
{
    qInfo() << "---Listing---";
	
	// QDir::AllEntries: Retrieves all entries (files and directories) in the current directory.
	// QDir::NoDotAndDotDot: Excludes the special entries "." (current directory) and ".." (parent directory).
	// QDir::Name: Sorts entries by name.
    foreach(QFileInfo fi, root.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot,QDir::Name))
    {
        if(fi.isDir()) qInfo() << "Dir" << fi.filePath();
        if(fi.isFile()) qInfo() << "File" << fi.filePath();

        if(fi.isDir())
        {
            QDir child(fi.filePath());
            qInfo() << "Inspecting:" << child.absolutePath();
            list(child);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();
    list(dir);

    return a.exec();
}
