/*
In C++, static scope (also called lexical scope) refers to when the binding of variables is determined
 at compile time. In static scoping, the scope of a variable is defined by its location in the source
 code, and it can be accessed within the block in which it is defined and in any nested blocks.
 C++ uses static scoping, meaning that when a variable is referenced, the compiler looks for its 
 declaration in the current scope or in outer scopes.

Dynamic scope, on the other hand, is when the binding of variables is determined at runtime.
In languages that use dynamic scoping (like some Lisp dialects), a variable reference is resolved
by looking up the call stack for the most recent binding of that variable. C++ does not support
dynamic scoping directly, but dynamic behavior can be simulated using function calls, pointers, or 
references, though this is less common.

*/





// A C program to demonstrate static scoping.
#include<stdio.h>
int x = 10;

// Called by g()
int f()
{
   return x;
}

// g() has its own variable
// named as x and calls f()
int g()
{
   int x = 20;
   return f();
}

int main()
{
  printf("%d", g());   // output : 10
  printf("\n");
  return 0;
}