# ## Templates
- Templates enable us to define generic classes.
- Templates are mechanism that make it possible to use one function or class to handle many different data types.
- By using templates, one can design a single class/ function that operates on data of many types, instead of having to create a separate class/function for each type.
- templates can significantly reduce source code size and increase code flexibility without reducing type safety.

- ## Program:1 (Function Overloading)

 ```cpp
#include<iostream.h>
int sum(int a, int b)
{ return (a+b); } // Function
float sum(float a, float b) // Definitions
{ return (a+b); }
char sum(char a, char b)
{ return (a+b); }
void main()
{
int x = 10, y = 5 ;
int z = sum(x, y); // Calling function with int arguments and return type of int
cout << “\n The sum of two int numbers is: “ << z ;
float f1 = 3.5, f2 = 7.5 ;
float f = sum(f1, f2); // Calling function with float arguments and
 // return type of float
cout << “\n The sum of two float numbers is: “ << f ;
char c1 = ‘a’, c2 = ‘b’;
char c = sum(c1, c2); // Calling function with char type arguments and
//return type of char
cout << “\n The sum of two char variables is: “ << c ;
}
  ```
## Types of templates:
- **Function Templates**: Templates used with functions are called function templates.
- **Class Templates**: Templates used with classes are called class templates.

## Function templates
The general syntax of a function template is:
```cpp
 template <class T>
 returntype T functionname( arguments of type T)
 {
 // Body of function with type T
 }
```
- In a function template a data type can be represented by a name (T in our case) that stand for any type.

- ## Example:
 ```cpp
#include<iostream.h>
template<class T>
T sum(T a, T b)
{
T c = a + b ;
return c ;
}
void main()
{
int x = 10, y = 5 ;
int z = sum(x, y);
cout << “\n The sum of two int numbers is: “ << z ;
float f1 = 3.5, f2 = 7.5 ;
float f = sum(f1, f2);
cout << “\n The sum of two float numbers is: “ << f ;
char c1 = ‘a’, c2 = ‘b’;
char c = sum(c1, c2);
cout << “\n The sum of two char variables is: “ << c ;
}
  ```
## Output:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/5e4fc0ab-3832-4c66-b266-de29eae91071)

- In above program, one can see that the sum() function works with different data types that we use as arguments.
- It will even work on user-defined data types, provided the + operator is appropriately overloaded in the class of the user-defined type.
- The code generation takes place when the function is actually called from within the program through statements like:
```Int z = sum(x, y);```
- When the compiler sees such a function call, it knows that the type to use it is int, because that’s the type of the arguments x, and y. Now it generates a specific version of the min() for type int, replacing every T with an int.
- This process is called instantiating the function template. The compiler also generates a call
to the newly instantiated function, and inserts it into the code where sum(x, y) is.
- Similarly, the expression f= sum(f1, f2) causes the compiler to generate a version of sum() that operates on type float and a call to this function; while the sum(c1, c2) call generates a function that works on type char.
- Templates don’t help us to save the memory. Even when we use templates, the three functions (for int, float, char) do get generated.
- The advantage is we are not required to type them out.

## Multiple argument types
```cpp
#include<iostream.h>
template<class T1, class T2>
T1 sum(T1 a, T2 b)
{
T1 c = a + b ;
return c ;
}
void main()
{
int a1 = 10;
float a2 = 5.5 ;
int a = sum(a1, a2);
cout << “\n The sum of a1 and a2 is: “ << a ;
float f1 = 3.5;
int f2 = 7;
float f = sum(f1, f2);
cout << “\n The sum of f1 and f2 is: “ << f ;
char c1 = ‘a’;
int c2 = 5 ;
char c = sum(c1, c2);
cout << “\n The sum of c1 and c2 is: “ << c ;
}
```
## Class Templates:
- The concept of templates can be extended for classes also.
- The following program will illustrates the use of class template.

## Example:
```cpp
#include<iostream.h>
template<class T>
class Vector
{
T *v ;
int size;
public:
Vector(int s)
{
size = s ;
v = new T[size] ;
}
void enter( )
{
for(int i = 0; i < size; i++)
{
cout << "\n Enter the number: ";
cin >> v[ i ];
}
}
void display()
{
for(int i=0; i < size; i++)
{
cout << "\n" << v[i];
}
}
} ; // End of the class definition
class Complex
{
int real, imag;
public:
Complex()
{ real = 0; imag = 0; }
Complex(int r, int i)
{ real =r; imag = i; }
friend ostream& operator << (ostream& o, Complex& c)
{
o << c.real <<"+" << c.imag << "i";
return o;
}
friend istream& operator >> (istream& i, Complex& c)
{
cout << "\n Enter the real part: ";
i >> c.real ;
cout << "\n Enter the imaginary part: ";
i >> c.imag ;
return i ;
}
};
void main( )
{
 Vector <int> v1(5);
v1.enter();
 v1.display();
Vector <float> v2(5);
 v2.enter();
 v2.display();
Vector <Complex> v3(5);
cout << "\n Enter the complex number: ";
v3.enter();
v3.display();
}
```
## Inheriting a class template from a class template
```cpp
template <class T>
class List
{
T data ;
List* next ;
public:
List()
{ next = NULL; }
void create()
{
List<T>* start= this ;
List<T>* node = new List<T> ;
T d ;
cout << "\n Enter the data: ";
cin >> d ;
node->data = d ;
node->next = NULL;
while(start->next != NULL)
start = start->next ;
start->next = node ;
}
void removeAtLast()
{
List<T>* start = this ;
while(start->next->next != NULL)
start=start->next ;
start->next = NULL;
}
void display()
{
List<T>* start = this->next ;
while(start!= NULL)
{
cout << start->data<< " " ;
start=start->next ;
}
}
} ;
template <class T>
class Stack : public List<T>
{
public:
 Stack():List<T>()
 { }
 void push()
 {
create();
 }
 void pop()
 {
removeAtLast();
 }
} ;
void main()
{
clrscr();
Stack <int> s ;
s.push();
s.display();
s.push();
s.display();
s.push();
s.display();
s.push();
s.display();
s.pop();
cout << "\n After removing the element\n";
s.display();
s.pop();
cout << "\n After removing the element\n";
s.display();
getch();
}
```
## Inheritance of template class by a non template class
```cpp
template <class T>
class List
{
T data ;
List* next ;
public:
List()
{ next = NULL; }
void create()
{
List<T>* start= this ;
List<T>* node = new List<T> ;
T d ;
cout << "\n Enter the data: ";
cin >> d ;
node->data = d ;
node->next = NULL;
while(start->next != NULL)
start = start->next ;
start->next = node ;
}
void removeAtLast()
{
List<T>* start = this ;
while(start->next->next != NULL)
start=start->next ;
start->next = NULL;
}
void display()
{
List<T>* start = this->next ;
while(start!= NULL)
{
cout << start->data<< " " ;
start=start->next ;
}
}
} ;
class Stack : public List<int>
{
public:
 Stack():List<int>()
 { }
 void push()
 {
create();
 }
 void pop()
 {
removeAtLast();
 }
} ;
void main()
{
clrscr();
Stack s ;
s.push();
s.display();
s.push();
s.display();
s.push();
s.display();
s.push();
s.display();
s.pop();
cout << "\n After removing the element\n";
s.display();
s.pop();
cout << "\n After removing the element\n";
s.display();
getch();
}
```
## Inheritance of a non template class by a template class
```cpp
class List
{
protected:
int data ;
List* next ;
public:
List()
{ next = NULL; }
void create()
{
List* start= this ;
List* node = new List ;
int d ;
cout << "\n Enter the data: ";
cin >> d ;
node->data = d ;
node->next = NULL;
while(start->next != NULL)
start = start->next ;
start->next = node ;
}
void removeAtLast()
{
List* start = this ;
while(start->next->next != NULL)
start=start->next ;
start->next = NULL;
}
void display()
{
List* start = this->next ;
while(start!= NULL)
{
cout << start->data<< " " ;
start=start->next ;
}
}
} ;
template <class T>
class Stack : public List
{
public:
 Stack():List()
 {}
 void push()
 {
create();
 }
 void pop()
 {
removeAtLast();
 }
} ;
void main()
{
clrscr();
Stack <float> s ;
s.push();
s.display();
s.push();
s.display();
s.push();
s.display();
s.push();
s.display();
s.pop();
cout << "\n After removing the element\n";
s.display();
s.pop();
cout << "\n After removing the element\n";
s.display();
getch();
}
```
### There are many other examples of class template. 
### some important ones are linked list, stack, queue.
