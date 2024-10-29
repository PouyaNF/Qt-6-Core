/*

  What
  Make a custom macro

  Macros in C++: Macros perform textual substitution and can lead to dangerous or unexpected behavior
  if misused, especially when working with different data types.
  Type Safety: The macro add does not enforce any type safety. Passing incompatible types (like strings 
  or booleans) could cause compilation errors or incorrect behavior.
  
  Safer Alternative: Use functions or templates instead of macros to ensure type safety and avoid issues 
  with type mismatch.

 */

#include <QCoreApplication>
#include <QDebug>

//Custom macro :  This line defines a macro called add, which takes two parameters a and b. 
#define add(a,b) a+b

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Easy...but dangerous
    qInfo() << add(1,2);

    //Lets break it
    //    qInfo() << add("Test",22);
    //    qInfo() << add(true,true);
    //    qInfo() << add(false, true);
    //    qInfo() << add(false, false);
    //    qInfo() << add("Test",'\n');
    //    qInfo() << add("Test",'/n');

    return a.exec();
}
