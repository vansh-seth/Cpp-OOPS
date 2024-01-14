# C++ Basics: Preprocessor, Input/Output, Functions, and More

## Preprocessor Directive
- The first line of the program `#include<iostream.h>` tells the compiler to add the source file `iostream.h` to the program’s source file.
- It contains the declarations needed by the `cout`, `cin` identifiers, and the `<<`, `>>` operators.
- Instead, it starts with a sign (#) called a preprocessor directive.

## Output using `cout`
- The identifier `cout` (pronounced as "Console out") is actually an object predefined in C++ to correspond to the standard output stream.
- The operator `<<` is called the insertion or put-to operator. It directs the contents of the variable on its right to the object on its left.
- Example:
  ```cpp
  cout << "Welcome to the world of C++";
  ```

## Input using `cin`
- The identifier `cin` (pronounced "console in") is an object, predefined in C++ to correspond to the standard input stream.
- The `>>` is the extraction or get-from operator. It takes the value from the stream object on its left and places it in the variable on its right.
- Example:
  ```cpp
  int temp;
  cin >> temp; // Input using cin object
  ```

## Cascading of `<<` and `>>` operators
- When the operator (`<<`) is used repeatedly in the `cout` statement, it is called cascading of insertion or output operator.
- The insertion operator (`>>`) can be cascaded with `cin` in the same way, allowing the user to enter a series of values.
- Example:
  ```cpp
  #include<iostream.h>
  void main() {
      int x, float f, char c, char str[20];
      cout << "\n Enter the value of x, f, c and str ";
      cin >> x >> f >> c >> str; // Cascading of input operator
      // Cascading of output operator
      cout << "\n x = " << x << " f = " << f << " c= " << c << " str= " << str;
  }
  ```

## Flexibility in the declaration of variables
- C requires that all variables be declared before the first executable statement. As against this, C++ allows the definition of variables at the point where they are used.

## Function Prototypes
- The prototype describes the function interface to the compiler by giving details such as the number of arguments, the type of arguments, and the type of the return value.
- Function prototype is a declaration statement in the calling program.
- Example:
  ```cpp
  #include<iostream.h>
  int sum(int, int); // Function prototype
  void main() {
      int a = 4, b = 6;
      int c = sum(a, b); // Calling function
      cout << "\n The sum is: " << c;
  }
  // function definition
  int sum(int x, int y) {
      int z = x + y ;
      return z ;
  }
  ```

## Function Overloading
- Overloading refers to the use of the same thing for different purposes.
- C++ also permits overloading of functions.
- One can use the same function name to create functions that perform a variety of different tasks. This is known as the function overloading in OOP.

## `const` Qualifier
- If the keyword `const` precedes the data type of a variable, the value of the variable will not change throughout the program.
- Any attempt to alter the value of the variable defined with this qualifier will result in an error message from the compiler.
- Example:
  ```cpp
  #include<iostream.h>
  const float PI = 3.14;
  void main() {
      float radius;
      cout << "\n Enter the radius :";
      cin >> radius;
      float area = PI * radius * radius;
      cout << "\n Area of circle = " << area;
      // PI = PI + 1; // Error! The symbolic constant cannot be modified
  }
  ```

## `new` and `delete` Operators
- The `new` operator allocates memory from free store.
- The `delete` operator returns the allocated memory back to the free store.

Example:
```cpp
int *p = new int;
float *q = new float;
*p = 25; // assigns 25 to the newly created int object
*q = 7.5; // assigns 7.5 to the float object.

// Initializing memory
int *p = new int(25);
float *q = new float(7.5);

// Deleting memory
delete p;
delete q;
```
