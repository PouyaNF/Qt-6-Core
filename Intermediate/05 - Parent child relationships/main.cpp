/*
    
    Parent child relationships


*/


#include <QCoreApplication>
#include "test.h"

Test* makeTree()
{
	// Creates a new Test object named "Root" with no parent (nullptr). 
	// This object will serve as the root of the tree structure.
    Test* root = new Test(nullptr,"Root");

	// A loop to create 5 parent nodes for the root.
    for(int p = 0; p < 5; p++)
    {
		// new Test object pobj, assigning the root as the parent.
        Test* pobj = new Test(root,"Parent-" + QString::number(p));

		// creating 3 child objects for each parent
        for(int c = 0; c < 3; c++)
        {
            Test* cobj = new Test(pobj,"Child-"  + QString::number(p) + " " + QString::number(c));
			
			// creating 3 sub-child objects for each child.
            for(int s = 0; s < 3; s++)
            {
                Test* sobj = new Test(cobj,"Sub-"  + QString::number(p) + " " + QString::number(c)  + " " + QString::number(s));
                Q_UNUSED(sobj); // This macro suppresses compiler warnings about the sobj variable being unused later in the function
            }
        }
    }

    return root;
}

void printTree(Test* root, int level = 0)
{
    if(root->children().length() == 0) return;

    QString lead = "-";
	// Fills the string lead with a number of dashes proportional to the current level of depth
	// in the tree (5 dashes per level)
    lead.fill('-', level * 5);

	// Loops through each child of the current root object. 
	// The children() method returns a list of the object's children as QObject* pointers.
    foreach(QObject* obj, root->children())
    {
		// cast each QObject* child to a Test* object using qobject_cast, which safely casts QObject-derived objects.
        Test* child = qobject_cast<Test*>(obj);
		
		// If the cast fails (i.e., the object is not of type Test), the function exits.
        if(!child) return;

        qInfo() << lead << child;

		// Prints the entire tree structure, starting from the root at level 1 (which will have 5 dashes)
        printTree(child,level + 1);  
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test* tree = makeTree();
    printTree(tree,1);
	
	// deleting the root object will automatically delete all its children, preventing memory leaks
    delete tree;

    return a.exec();
}
