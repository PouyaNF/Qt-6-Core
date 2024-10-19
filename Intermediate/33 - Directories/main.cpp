/*

  What
  Directories

  Why
  We need to navigate and manipulate them

  How
  QDir : Provides an interface for accessing and manipulating directories and their contents.
  
  QFileInfo: Contains information about a file or directory, such as its name, size, 
  permissions, and whether it's a directory.
  
  QFileInfoList: A list of QFileInfo objects, which is useful for handling multiple
  file or directory entries.
  
 */

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

// unction list that takes a reference to a QDir object. This function lists the contents of the specified directory.
void list(QDir &root)
{
    qInfo()  << "---Listing---";
	
	// Iterates through each QFileInfo object in the list returned by root.entryInfoList().
	// entryInfoList(QDir::Filter::Dirs, QDir::Name): Retrieves a list of all entries in the directory that are directories (QDir::Filter::Dirs) and sorts them by name (QDir::Name).
    foreach(QFileInfo fi, root.entryInfoList(QDir::Filter::Dirs,QDir::Name))
    {
        if(fi.isDir())
        {
            qInfo() << fi.absoluteFilePath();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	// Creates a QDir object initialized to the application's directory path (the directory where the executable is located).
    QDir dir(QCoreApplication::applicationDirPath());
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();

	// The cdUp() function changes the current directory to the parent directory.
    dir.cdUp();
    qInfo() << dir.absolutePath();
	
	// List Directories: Calls the list function to display the directories within the current (parent) directory.
    list(dir);
	
	// Create Directory: Creates a new directory named "test" in the current path. If the directory already exists, it will not be created again.
    dir.mkdir("test");
    list(dir);

    //recursive exists but dont do it unless you KNOW it should be gone
	// The rmdir("test") function attempts to remove the "test" directory. This only succeeds if the directory is empty
    dir.rmdir("test");
    list(dir);


    return a.exec();
}
