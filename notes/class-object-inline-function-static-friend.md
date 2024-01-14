# C++ Basics: Classes, Objects, and More

## Class & Objects
- C++ offers another user-defined data type known as a **class**, which is a fundamental feature of object-oriented programming.
- A class can declare and define both data and functions that are hidden from external use.
- The binding of data and functions together into a single class type variable is known as **encapsulation**.
- The general form of declaration of a class is as follows:
```cpp
class class_name
{
private:
    // Variable declaration (data members)
    // Function declaration (member functions)

public:
    // Variable declaration (data members)
    // Function declaration (member functions)
};
```
- The body of the class is delimited by braces `{}` and terminated by a semicolon `;`.
- The variables and functions within the body of the class are collectively known as members.
- Data or variables declared within the class are known as **data members**, while functions declared/defined within the class are known as **member functions**.

## private and public keywords
- Data members and member functions are usually grouped under two sections: **private** and **public**, known as access specifiers.
- These keywords are followed by a colon `:`.
- If no specifier is used, then the members are private by default.
- Private members can only be accessed from within the class, while public members can be accessed from outside the class.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/38548683-5a30-492e-b2cf-1fc6ebf8d534)


## Defining member functions
- Member functions can be defined either outside the class or inside the class.
- Normally, only small functions are defined inside the class definition. However, it is good programming practice to define member functions outside the class.

### Defining member function outside the class:
```cpp
return_type class_name :: function_name(arguments)
{
    // Body of the function
}
```

### Defining member functions inside the class:
```cpp
return-type function-name(arguments)
{
    // Function body
}
```

## Creating Objects
- After defining the class, objects of that class can be declared in the `main()` function.
- The syntax for declaring an object is:
```cpp
class_name obj1, obj2, ..., objN;
```
- Objects can also be created by placing their names immediately after the closing brace.
- For example:
```cpp
class Rectangle
{
private:
    int length, breadth;

public:
    void enterdata();
    void disparea();
} a1, a2;
```
- The objects `a1` and `a2` of type `Rectangle` are created.

## Calling members
- Only an object of a class can access the members of that class.
- The syntax for calling a member of the class is:
```cpp
object_name.data_member; // For calling the data member of the class
object_name.member_function(actual arguments); // For calling the member function of the class
```
- The dot operator `.` is known as the class member access operator.
- Note that the objects of a class can access only those members of the class that are declared in public mode.
- The private members of a class cannot be accessed by the objects of that class.

## Extension to Structures in C++
- So far it has been discussed that structures are used to group data and classes are used to group both data and functions.
- In C++, the structures can also be used to group both data and functions, like the classes.
- The only difference between structure and class is that in a structure the members (data and function) are public by default, while in a class the members are private by default. 

### The following declarations of the class and structure accomplish the same task.
#### class
```cpp
class Rectangle
{
 // private by default
 float length, breadth ;
 public:
 void enterdata(void) ;
 void disparea(void) ;
} ;
```
#### structure
```cpp
struct Rectangle
{
 // public by default
 void enterdata(void) ;
 void disparea(void) ;
 private:
 float length, breadth ;
} ;
```
- Thus in C++, a structure can be thought of as a class. However, it is general practice to use structure to group data, and classes to group both data and functions

## Accessibility of public members of a class:
- **Public members** of a class:
  - Can be accessed by the member function of the same class directly.
  - Can be accessed by the member function of the sub class/derived class directly.
  - Can be accessed by any ordinary function (function which is not a member of any class, e.g., `main()`) outside the class by first defining the object of that class.
  - Can be accessed by the member function of the other class(es) by first defining the object of that class.
- **Private members** of a class:
  - Can only be accessed by the member function of the same class directly.

## Constructor
- A constructor is a special kind of member function that allows setting up values while defining the objects, without the need to make a separate call to a member function.
- A constructor is executed automatically whenever an object is created.
- The class and the constructor(s) in it must have the same names.
- No return type is used for the constructor (not even `void`).
- The constructor that does not accept any parameter is called the **default constructor**, while the one that can take arguments is called the **parameterized constructor**.
- Constructors must be defined under the public access specifier.

#### Example
```cpp
// This program illustrates the use of the constructors in the class
#include<iostream.h>
class Rectangle
{
private:
float length ;
float breadth ;
public:
Rectangle( ) // Default constructor, without any argument
{
length = 0.0;
breadth = 0.0;
 }
Rectangle(float l, float b) // Constructor with two arguments
{
length = l ;
breadth = b ;
}
void Enter_lb(void)
{
cout << "\n\t Enter the length of the rectangle: " ;
cin >> length ;
cout << "\t Enter the breadth of the rectangle: " ;
cin >> breadth ;
}
void Display_area(void)
{
 cout << "\n\t The area of the rectangle = " << length*breadth ;
}
} ; // End of the class definition
void main(void)
{
Rectangle r1 ; // Invokes the first constructor without any argument
cout << "\n First rectangle-------->\n" ;
r1.Enter_lb( );
r1.Display_area( );
cout << "\n\n Second rectangle------->\n" ;
Rectangle r2(5.6, 3.5); //Invokes the second constructor with two
 // arguments
r2.Display_area( );
}
```
## Overloaded constructors
- Constructors obey the same overloading rules, as do other functions.

## Implicit constructor
```cpp
Rectangle( )
{
 // Empty body
}
```
- An implicit constructor is a constructor with an empty body used to create objects without any initial values.
-This constructor is used to create objects without any initial values, as discussed earlier. 

## Copy constructor
- The parameters of a constructor can be of any type except that of the class to which it belongs.
- For example:
```cpp
class Rectangle
{
………
………
public:
 Rectangle(Rectangle r) ; // This is not valid
}; 
```
- is not valid in C++, because the compiler will complain that it is out of memory.
- A constructor can accept a reference to its own class as a parameter, known as the **copy constructor**, used to copy its argument into a new object.
- When an argument is passed by value, a copy of it is constructed by the copy constructor.
- The copy constructor calls itself over and over until the compiler runs out of memory.
- So, in the copy constructor, the argument must be passed by reference, which creates no copies.
- However, a constructor can accept a reference to its own class as a parameter. For example,
```cpp
  class Rectangle
{
public:
Rectangle(Rectangle & r) ; // This is valid
}
  ```
- is valid in C++. Such type of constructor is known as copy constructors, which is used to copy its argument into a new object

## Destructor
- A destructor is a function that is guaranteed to be invoked when an object is destroyed, similar to how a constructor is guaranteed to be invoked when an object is created.
- Destructors typically clean up and release resources.
- The destructor has the same name as the constructor but is preceded by a tilde `~`.
- It is good practice to declare a destructor to release memory space for future use.
- The destructor must be defined in the public access specifier and does not take any argument.
```cpp
class Sample
{
private:
    char *name;

public:
    Sample();   // Constructor
    ~Sample();  // Destructor
};
```
## Some important points about destructors: 
- Destructors take the same name as the class name.
- Like the constructor, the destructor must also be defined in the public. The destructor must be a public member
- The Destructor does not take any argument which means that destructors cannot be overloaded. 
- No return type is specified for destructors. 

## Objects as function arguments
- Objects can be passed as function arguments by value or by reference.
- When an object is passed by value, a copy of the object is passed to the function and any changes made to the object inside the function do not affect the object used to call the function.
- When passed by reference, the function works directly on the actual object used in the call The pass-by-reference method is more efficient since it requires to pass only the address of the object and not the entire object.

## Functions with default arguments
- Member functions of a class may contain arguments with default values.
- Only the trailing argument can have default values.

## Inline functions 
- When the compiler sees a function call, it normally generates a jump to the function. At the end of the function, it jumps back to the instruction following the call. While this sequence of events may save memory space, it takes some extra time.
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/6dbedf5b-157c-46d8-9dda-94938462d8f4)

- Inline functions are used to save execution time in short functions.
- The actual code from the function is inserted instead of a jump to the function, improving efficiency.
- The compiler must have seen the function definition (not just the declaration) before the first function call.
- Example:
```cpp
inline void sum(int a, int b)
{
    int c = a + b;
    cout << "\n The sum of numbers is: " << c;
}

void main()
{
    sum(9, 2);    // First call
    sum(2, 3);    // Second call
    sum(5, 6);    // Third call
    sum(10, 5);   // Fourth call
}
```
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/80c7c024-588e-4b06-8cd9-b5b48c74889a)

## Static data member
- Data members in a class can be defined as static.
- A static member variable is available only within the class but continues to exist until the program execution ends.
- The type and scope of each static member variable must be defined outside the class definition.
- Syntax for defining a static variable:
```cpp
data-type class_name :: variable_name;
```
- By default, a static member variable is initialized to zero. However, some initial value can also be assigned to the variable.
- Static member variables are also known as class variables and are associated with the class itself rather than with any class objects.

# Example 1
```cpp
#include<iostream.h>
class Objcount
{
private:
static int count ; // Member Variable declared as static
public:
Objcount( ) // Constructor
{
count++ ;
}
void display(void)
{
cout << "\n cout = " << count ;
}
} ;
//*********Definition of the Static Member Variable count***************
int Objcount :: count ; // count is initialized to 0 by default
void main(void)
{
Objcount o1, o2, o3 ;
o1.display( ) ;
o2.display( ) ;
o3.display( ) ;
}
```
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/1ba90ad5-a9df-4bee-bb19-d4c4dbe2d86e)

## Example 2:
```cpp
#include<iostream.h>
class StaticSample
{
private:
int count ;
static int staticcount ; // static data
public:
StaticSample( ) // Default constructor, without any argument
{ count = 0;
 count++ ;
 staticcount++ ;
}
void display(void)
{
cout << "\n\tcount = " << count ;
cout << "\n\tstaticcount = "<< staticcount << endl;
}
} ; // End of the class definition
int StaticSample :: staticcount = 0 ; // Definition of static data
void main( )
{
 StaticSample s1
cout << “\nAfter defining first object of StaticSample class---->\n”;
s1.display();
StaticSample s2 ;
 cout<<"\nAfter defining second objects of StaticSample class---->\n";
s1.display();
s2.display();
StaticSample s3;
cout << "\n\n After defining third object of StaticSample class---->\n";
s1.display();
s2.display();
s3.display();
}
```
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/a7efb6b9-6530-4446-a449-e070b9ea05dc)
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/a94484a0-f8fc-400b-8cb3-d500c14d9ce8)

## Static member function:
- Static member functions can also be declared as static.
- A static member function can access only the other static member functions or static data, declared in the same class. 
- A static member function is not part of the objects of a class.
- The static member functions can be called using the class name instead of its objects.
- The syntax for calling a static member function is:
```cpp
 class_name :: function_name( ) ;
```

### Example:
```cpp
#include<iostream.h>
class Test
{
private:
static int total ; // static data member
public:
Test( )
{
total++ ;
}
static void display(void) // static member function
{
cout << "\n total = " << total << endl ;
}
}; // End of the class definition
int Test :: total = 0 ; // Initialize total before main( )
void main(void)
{
cout << "\n When no object is created************** " ;
Test :: display( ); // Accessing static member function
Test obj1, obj2, obj3 ;
cout << "\n When three objects have been created******" ;
Test :: display( ); // Accessing static member function
}
```
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/8029d8f3-dd37-4da7-a632-f2e6489d07fd)

## Friend function
- Friend functions can access private data and act as an interface between two different classes.
- Syntax for the declaration of a friend function:
```cpp
friend return_type function_name(arguments);
```

### Example: Interface between two different classes
```cpp
class Two;  // Forward declaration of class

class One
{
    int o;

public:
    One() { o = 5; }
    friend void sum(One, Two);  // Friend function
};

class Two
{
    int t;

public:
    Two() { t = 10; }
    friend void sum(One, Two);  // Friend function
};

void sum(One one, Two two)  // Friend function definition
{
    int s = one.o + two.t;
    cout << "\n The sum = " << s;
}

void main()
{
    One o1;
    Two t2;
    sum(o1, t2);
}
```
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/143ff81c-8584-4326-8110-2b4832a4df17)

- You can also define the friend function inside the class

## The const keyword
- The `const` keyword is used to prevent normal variables from being modified.
- It can be used on function arguments to keep a function from modifying a variable passed to it by value or by reference.
- It can be used on member functions of a class and member function arguments.

## Const member function
- A constant member function guarantees that it will never modify any of its class's member data.
- To make a member function constant, the keyword `const` is placed after the declaration part but before the function body.
- If the member function is declared inside the class but defined outside it, it is necessary to use `const` in the declaration as well as definition.

### Example:
```cpp
class Sample
{
private:
    int data;

public:
    Sample(int d = 0) { data = d; }
    void ChangeData() const;  // Constant member function
    void DisplayData() { cout << "\n data = " << data; }
};

void Sample::ChangeData() const  // Constant member function definition
{
    data = data + 10;  // This is invalid
}

void main()
{
    Sample s(10);
    s.ChangeData();
    s.DisplayData();
}
```

- Compiler error: Cannot modify a const object.
