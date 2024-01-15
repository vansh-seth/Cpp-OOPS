# Exception Handling
- Exception handling is designed to orderly way to handle abnormal events. This means error handler must do something rational when an error occurs
-  C++ exception handling is built upon three keywords: try, throw, and catch.
  1. Statements to monitor for exceptions are contained in a try block.
  2. If an exception happens, it is thrown using the throw keyword.
  3. The exception is caught, using catch, and processed. catch is not called, rather, program execution is transferred to it.
- There can be more than one catch statement. If there is no applicable catch statement, then
abnormal program termination may occur (results in calling terminate( ) which further calls
abort())

## Example:
```cpp
#include <iostream>

int main() {
    std::cout << "Start\n";

    try {
        // Start a try block
        std::cout << "Inside try block\n";

        // Throw an error
        throw 100;

        // The code after the throw statement won't be executed
        std::cout << "This will not execute";
    }
    catch (int i) {
        // Catch block for handling the thrown integer
        std::cout << "Caught an exception -- value is: " << i << "\n";
    }

    return 0;
}
```

Explanation:

- The `try` block contains the code that might throw an exception. In this case, it throws an integer value `100` using `throw 100`.
- If an exception occurs, the control is transferred to the `catch` block.
- The `catch` block specifies the type of exception it can catch (`int` in this case). If an exception of this type is thrown in the associated `try` block, this block will be executed.
- In this example, if the `throw 100` statement is encountered, the control moves to the `catch` block, which prints a message indicating that an exception was caught and displays the value of the caught exception (in this case, `100`).
- The code after the `throw` statement won't be executed since an exception was thrown.

When you run this program, you should see the output:

```
Start
Inside try block
Caught an exception -- value is: 100
```

### An exception can be thrown from outside the try block as long as it is thrown by a function that is called from within try block
```cpp
void Xtest (int test) {
cout << "Inside Xtest, test is: " << test << "\n";
If (test) throw test;
}
int main () {
cout << "Start\n";
try { // start a try block
cout << "Inside try block\n";
Xtest(0);
Xtest(1);
Xtest(2);
}
catch (int i) { // catch an error
cout << "Caught an exception -- value is: ";
cout << i << "\n";
}
cout << "End";
return 0; }
```

### Output:

```
Start
Inside try block
Inside Xtest, test is: 0
Inside Xtest, test is: 1
Caught an exception -- value is: 1
End

```

### A try block can be localized to a function. When this is the case, each time the function is entered, the exception handling relative to that function is reset
```cpp
// Localize a try/catch to a function.
void Xhandler (int test)
{
try{
if(test) throw test;
}
catch (int i) {
cout << "Caught Exception #: " << i << '\n';
}
}
int main() {
cout << "Start\n";
Xhandler (1);
Xhandler (2);
Xhandler (0);
Xhandler (3);
cout << "End";
return 0;
}
```
### Output:
```
Start
Caught Exception #: 1
Caught Exception #: 2
Caught Exception #: 3
End

```
### Catch is skipped if there is no exception.

```cpp
int main ()
{
cout << "Start\n";
try { // start a try block
cout << "Inside try block\n";
cout << "Still inside try block\n";
}
catch (int i) { // catch an error
cout << "Caught an exception -- value is: ";
cout << i << "\n";
}
cout << "End";
return 0;
}

```
## Catching Class Types
In real-world programs, most exceptions will be class types rather than built-in types.
```cpp
class MyException {
public:
char str_what[80];
int what;
MyException()
{
*str_what = 0; what = 0;
}
MyException(char *s, int e)
{
strcpy(str_what, s);
what = e;
}
};
int main()
{
int i;
try {
cout << "Enter a positive number: ";
cin >> i;
if(i<0)
throw MyException("Not Positive",
i);
}
catch (MyException e)
{
cout << e.str_what << ": ";
cout << e.what << "\n";
}
return 0;
}
```

## Catching All Exceptions
A useful default or "catch all" statement
```cpp
void Xhandler(int test) {
try{
if(test==0) throw test; // throw int
if(test==1) throw 'a'; // throw char
if(test==2) throw 123.23; // throw double
}
catch(...) { // catch all exceptions
cout << "Caught One!\n";
}
}
int main() {
cout << "Start\n";
Xhandler(0);
Xhandler(1);
Xhandler(2);
cout << "End";
return 0;
}
```

- One very good use for catch(...) is as the
last catch of a cluster of catches
- Catching all exceptions implies you prevent
an unhandled exception from causing an
abnormal program termination.

## Handling Derived-Class Exceptions
A catch clause for a base class will also match any class derived from that base.
```cpp
class B {
};
class D: public B {
};
int main()
{
D derived;
try {
throw derived;
}
catch(B b) {
cout << "Caught a base class.\n";
}
catch(D d) {
cout << "This won't execute.\n";
}
return 0;
}
```

- A catch clause for a base class will also
match any class derived from that base
- Second catch clause will never execute |
compiler may give warning or error
message.
- Put the derived class first in the catch
sequence if you want to catch exceptions
of both a base class type and a derived
class type.

## Restricting Exceptions

- Prevents a function from throwing any exceptions whatsoever.
- Syntax:
```cpp
ret-type func-name(arg-list) throw(type-list) // comma-separated type-list
{
// ...
}
```
- Throwing any other type of expression will cause abnormal program termination | calls
unexpected( ) which further calls abort()
- Use an empty list if a function is unable to throw any exception
- A function can be restricted only in what types of exceptions it throws back to the try block
that called it, i.e., a try block within a function may throw any type of exception so long as it
is caught within that function.
### Example:
```cpp
void Xhandler(int test) throw(int, char, double)
{
if(test==0) throw test; // throw int
if(test==1) throw 'a'; // throw char
if(test==2) throw 123.23; // throw double
}
int main()
{
cout << "start\n";
try{
Xhandler(0);
}
catch(int i) {
cout << "Caught an integer\n";
}
catch(char c) {
cout << "Caught char\n";
}
catch(double d) {
cout << "Caught double\n";
}
cout << "end";
return 0;
}
```
### This function can throw NO exceptions!
```cpp
void Xhandler (int test) throw()
{
/* The following statements no longer work. Instead, they will cause an abnormal
program termination. */
if(test==0) throw test;
if(test==1) throw 'a';
if(test==2) throw 123.23;
}
```

## Rethrowing an Exception
When you rethrow an exception, it will not be recaught by the same catch statement. It will
propagate outward to the next catch statement.

```cpp
void Xhandler() {
try {
throw "hello"; // throw a char *
}
catch (const char *) { // catch a char *
cout << "Caught inside Xhandler\n";
throw ; // rethrow char *
}
}
int main()
{
cout << "Start\n";
try{
Xhandler();
}
catch (const char *) {
cout << "Caught inside main\n";
}
cout << "End";
return 0;
}
```

### Output:
```
Start
Caught inside Xhandler
Caught char * inside main
End

```

## Understanding terminate ( ) and unexpected ( )
- Protorype:
1. void terminate( );
2. void unexpected( );
   
- These functions require the header <exception>. By default, both calls abort( )
-  **terminate( )** is the handler of last resort when no other handlers for an exception are available. By default, it calls abort( ).
-  The terminate( ) function is called if
 1. exception handling subsystem fails to find a matching catch statement for an exception program
 2. attempts to rethrow an exception when no exception was originally thrown
 3. a destructor for an object being destroyed throws an exception during unwinding the stack
- **unexpected( )** is called when a function attempts to throw an exception which is not allowed by its throw list. By default, unexpected( ) calls terminate( ).

## Setting the Terminate and Unexpected Handlers
- Goal: To change the functions that are called by terminate( ) and unexpected( ) to take full control of the exception handling subsystem.

```
terminate_handler set_terminate(terminate_handler newhandler) throw( );
```
```
unexpected_handler set_unexpected(unexpected_handler newhandler) throw( );
```
- newhandler is a pointer to the new terminate/unexpected handler
- Function returns a pointer to the old terminate/unexpected handler
- The new terminate handler must be of type terminate/unexpected_handler, which is defined like this:
```
typedef void (*terminate_handler) ( );
typedef void (*unexpected_handler) ( );
```

## Example:
```cpp
// Set a new terminate handler.
#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;
void my_Thandler() {
cout << "Inside new terminate handler\n";
abort();
}
int main()
{
// set a new terminate handler
set_terminate(my_Thandler);
try {
cout << "Inside try block\n";
throw 100; // throw an error
}
catch (double i) {
// won't catch an int exception
// ...
}
return 0;
}
```

### Output:
```
Inside try block
Inside new terminate handler
abnormal program termination

```
### Applying Exception Handling
```cpp
void divide(double a, double b);
int main()
{
double i, j;
do {
cout << "Enter numerator (0 to stop): ";
cin >> i;
cout << "Enter denominator: ";
cin >> j;
divide(i, j);
} while(i != 0);
return 0;
}
void divide(double a, double b)
{
try {
if(!b) throw b; // check for divide-by-zero
cout << "Result: " << a/b << endl;
}
catch (double b) {
cout << "Can't divide by zero.\n";
}
}
```

### Exceptions with Arguments
Exception arguments carry information about what caused an exception and helps us diagnose the
error that triggered the exception.

```cpp
class Distance
{
private:
int feet;
float inches;
public:
class InchesEx //Exception class - specifying data in an exception class
{
public:
string origin; //for name of routine
float iValue; //for faulty inches value
InchesEx (string or, float in) //2-arg constructor
{
origin = or; //store string
iValue = in; //store inches
}
}; //end of exception class
Distance () //constructor (no args)
{ feet = 0; inches = 0.0; }
Distance (int ft, float in) //constructor (two args)
{
If (in >= 12.0)
throw InchesEx (“2-arg constructor”, in);
feet = ft;
inches = in;
}
void getdist () //get length from user
{
cout << “\nEnter feet: “; cin >> feet;
cout << “Enter inches: “; cin >> inches;
If (inches >= 12.0)
throw InchesEx (“getdist() function”, inches);
}
void showdist () //display distance
{ cout << feet << “\’-” << inches << ‘\”’; }
};
int main()
{
try
{
Distance dist1 (17, 3.5); //2-arg constructor
Distance dist2; //no-arg constructor
dist2.getdist (); //get value
cout << “\ndist1 = “; dist1.showdist(); //display distances
cout << “\ndist2 = “; dist2.showdist();
}
catch(Distance::InchesEx ix) //exception handler
{
cout << “\nInitialization error in “ << ix.origin << “.\n Inches value of “ << ix.iValue <<
“ is too large.”;
}
cout << endl;
return 0;
}
```

## The bad_alloc Class
The bad_alloc Class is one of the most commonly used exception classes, which is thrown if an
error occurs when attempting to allocate memory with new.
```cpp
int main ()
{
const unsigned long SIZE = 10000; //memory size
char* ptr; //pointer to memory
try
{
ptr = new char [SIZE]; //allocate SIZE bytes
}
catch (bad_alloc) //exception handler
{
cout << “\nbad_alloc exception: can’t allocate memory.\n”;
return (1);
}
delete [] ptr; //deallocate memory
cout << “\nMemory use is successful.\n”;
return 0;
}
```
