# Operator Overloading in C++

## Overview
- The term operator overloading means giving the C++ operators such
as ( -, +, --, ++, *, /, >, <, >=, <= etc.) , additional meanings while
applying on user-defined data types.
- For example, the statement:
 z = x + y ;
can be applied only to basic data-types such as float, int, double,
long etc.
- But consider a case where x, y and z are objects of a user-defined
class. In this case, the above statement is not legal.
- However, by making use of operator overloading, the above
statement can be made legal.
- Operator overloading provides a flexibility to create new definitions
for most of the C++ operators.
- By using classes to create new variables and operator overloading
to create definitions for operators, one can create a new language of
one’s own design. 
### Supported Operators
The following operators can be overloaded:
```
+ - * / % ^ & | ~
! = < > += -= /= *= %=
^= &= |= << >> >= <= == !=
>>= <<= && || ++ -- ->* , ->
[] () new new[] delete delete[]
```
### Unsupported Operators
The following operators cannot be overloaded:
- :: (scope resolution operator)
- . (member selection)
- .* (member selection through pointer to function)
- sizeof (size of operator)
- ?: (conditional operator)

## Overloading Unary Operator
Unary operators act on a single operand. The program below demonstrates how to overload the unary minus operator (-) for a user-defined class named `Minus`.

```cpp
#include<iostream.h>

class Minus {
private:
    int a, b, c;

public:
    // ... (constructor and other member functions)

    // Declaration of the unary minus operator function
    void operator - ();
};

// Definition of the unary minus operator function
inline void Minus::operator - () {
    a = -a;
    b = -b;
    c = -c;
}

// Main function
void main(void) {
    Minus M(5, 10, -15);
    cout << "\n Before activating the operator - ( )\n";
    M.display();
    -M;
    cout << "\n After activating the operator - ( )\n";
    M.display();
}
```
## Output

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/04c5a5ca-8247-4b1a-b8ab-75accf1019a8)

## Operator Function
To overload an operator, a special function known as the operator function is used. The general syntax for an operator function is as follows:

```cpp
return_type class_name::operator operator_type(arguments) {
    // Body of the function
}
```

In the provided program, the unary minus operator function is declared and defined for the `Minus` class.
- This declarative tells the compiler to call this member function, whenever the –
operator is encountered, provided the operand is of type Minus.
- In the main( ) function of this program, the object M of type Minus is declared
and initialized to ( 5, 10, -15 ) as:
Minus M( 5, 10, -15 ) ;
- Before activating the operator function, the values of a, b and c are displayed
as:
```
a = 5
b = 10
c = -15
```
After the statement
```
-M ;
```
the operator function gets activated and the values of a, b and c are displayed
as:
```
a = -5
b = -10
c = 15
```
### Operator Function with Return Value
The initial implementation of the unary minus operator function has a void return type. If you wish to use the result in an assignment, you need to modify the return type. Here's an example:

```cpp
Minus operator - () {
    Minus temp;
    temp.a = -a;
    temp.b = -b;
    temp.c = -c;
    return temp;
}
```

Now, you can use statements like `M2 = -M1;` in the main function.

### program
```cpp
#include<iostream.h>
//******Class Definition********
class Minus
{
private:
int a, b, c ;
public:
//**********Member Functions***************
Minus( ) // Default Constructor
{ }
Minus(int A, int B, int C)
{ a = A ; b = B ; c = C ; }
void display(void)
{
cout << "\t a = " << a << endl ;
cout << "\t b = " << b << endl ;
cout << "\t c = " << c << endl ;
}
//********Operator Function Definition *******
Minus operator - (void) // Declarative with the return type Minus
{
Minus temp ;
temp.a = -a ;
temp.b = -b ;
temp.c = -c ;
return temp ;
}
} ; // End of the class definition
//*******Main Functiion************
void main(void)
{
Minus M1(5, 10, -15); // Initialization of the object M1 of type Minus
cout << "\n Before activating the operator -( ):\n" ;
M1.display( ) ;
Minus M2 ; // Definining the object M2 of type Minus
M2 = -M1 ; // Activates the function operator -( ) and
// assigns the value of -M1 to M2
cout << "\n After activating the operator -( ):\n" ;
M2.display( ) ;
}
```
### Output :

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/2d3e495a-8645-4368-aade-bb454c30b8b9)

In the above program, the `operator – ( )` function creates a new object,
named as temp of type Minus, for returning the values.
- This type of object is known as `temporary object`. The values of the
member data i.e. a, b and c are assigned to this temporary object temp as:
```
temp.a = -a ;
temp.b = -b ;
temp.c = -c ;
```
- Finally, the function returns the object `temp` as:
```
return temp ;
```
- Thus, the statement like
```
M2 = -M1 ;
```
- can be used in the main( ) function.

## Overloading the increment operator ( ++ )
```cpp
#include<iostream.h>
class Increment
{
private:
int count ;
public:
//*****Member Function Definitions******
Increment( ) // Default Constructor
{ count = 0 ; }
Increment(int C) // Constructor with Argument
{ count = C ; }
Increment operator ++ ( ) // Operator Function Definition
{
count++ ;
return Increment(count);
}
void display(void) // Function for displaying the output
{
cout << count << endl ;
}
}; // End of the class definition
void main(void)
{
Increment I1, I2(5), I3, I4 ;
cout << "\n Before activating the operator ++( )\n" ;
cout << " I1 = " ;
I1.display( );
cout << " I2 = " ;
I2.display( );
++I1 ; // I1 and I2 are incremented
I2++ ;
cout << "\n After activating the operator ++( )\n" ;
cout << " I1 = " ;
I1.display( );
cout << " I2 = " ;
I2.display( ) ;
I3 = ++I1 ; /* Here, the objects I1 and I2 are incremented again and their
I4 = I2++ ; values are assigned to the objects I3 and I4 respectively */
cout << " I3 = " ;
I3.display( ) ;
cout << " I4 = " ;
I4.display( ) ;
}
```
### Output:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/4b94a603-f4af-40b7-91b5-0d90975462e0)

- In the above program, when the increment operator ++ is overloaded
using the function `operator ++ ( )` there is no distinction between `prefix` and `postfix` notation. That is why all the statements
```cpp
I1++ ;
++I2 ;
```
and
```cpp
I3 = I1++ ;
I4 = ++I2 ;
```
have the same effect i.e. they are incremented using the prefix
notation only.
• In order to make both notations of the increment operator (prefix &
postfix) to work, the programmer must define two separate functions
as:
```cpp
operator ++ ( ) // For prefix
operator ++ ( int ) // For postfix
```
- The operator function for overloading the postfix increment
operator uses a dummy argument int, which is
automatically set to 0 by the postfix operator ++.
- This dummy argument allows the compiler to distinguish
the two forms (prefix, postfix) of the increment operator.
- In reality, it is not an argument and it does not mean an
integer.
- It is simply a signal to the compiler to create the postfix
notation of the operator.
### Program: This program demonstrates the overloading of the increment operator (++), both in the Prefix notation as well as in the Prefix notation
```cpp
#include<iostream.h>
class Pre_post_incr
{
int count ;
public:
Pre_post_incr( ) // Default Constructor
{ count = 0 ; }
// Continued from the previous page
Pre_post_incr( int c) // Constructor with an argument
{ count = c ; }
Pre_post_incr operator ++ ( ) // Operator Function for overloading the
{ // increment operator in prefix notation
return Pre_post_incr(++count);
}
Pre_post_incr operator ++ (int) // Operator Function for overloading the
{ // increment operator in postfix notation
return Pre_post_incr(count++);
}
void display(void) // Function for displaying the output
{ cout << count << endl ; }
}; // End of the class definition
//*******Main Function************
void main(void)
{
Pre_post_incr I1, I2, I3, I4 ; // Object declaration of class Pre_post_incr
cout << "\n Before activating the functions operator++() and operator ++ ( int)"
;
cout << " \n I1 = " ;
I1.display( ) ;
cout << " I2 = " ;
I2.display( ) ;
cout << "\n After activating the functions operator++() and operator ++ ( int )" ;
I3 = ++I1 ; // Prefix incrementation
cout << "\n I3 = ++I1 = " ;
I3.display( ) ;
I4 = I2++ ; // Postfix incrementation
cout << " I4 = I2++ = " ;
I4.display( ) ;
}
```
### Output:
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/2889edb7-5829-4ba8-8a93-782f084dae49)

## Overloading binary operators:
```cpp
#include<iostream.h>
class complex
{
 float real, imaginary ;
public:
 complex( ) // Default Constructor without arguments
 { real = 0.0; imaginary = 0.0; }
 complex(float r, float i) // Constructor with arguments
 {
real = r ;
imaginary = i ;
 }
 void enterdata(void)
 {
 cout << "\n Enter the real part of the second complex number: ” ;
cin >> real ;
cout << "\n Enter the imaginary part of the second complex /
 number: " ;
cin >> imaginary ;
 }
void display(void)
{
 if (imaginary >=0)
cout << real << "+" << imaginary << " i" << endl ;
else
cout << real << imaginary << " i" << endl ;
}
// Operator Function Definition for overloading the binary operator +
complex operator + (complex C)
{
complex temp ;
temp.real = real + c.real ;
temp.imaginary = imaginary + c.imaginary ;
return temp ;
}
// Operator Function Definition for overloading the binary operator -
complex operator - (complex C)
{
complex temp ;
temp.real = real – c.real ;
temp.imaginary = imaginary – c.imaginary ;
return temp ;
}
} ; // End of the class definition
//*************Main Function********************
void main(void)
{
complex c1(2.5, 4.5), c2 ; // Object Definitions
cout << "\n The first complex number i.e. c1 is: " ;
c1.display( ) ; // Displays the first complex number
c2.enterdata( ) ;
cout << "\n The second complex number i.e. c2 is: " ;
c2.display( ) ; // Displays the second complex number
complex c3 = c1 + c2 ;
cout << "\n The sum of two complex numbers i.e. c1 and c2 is: " ;
c3.display( ); // Displays the third complex number
 complex c4 = c1 - c2 ;
 cout << "\The substraction of the complex numbers, c2 from c1 is: "
;
 c4.display( ); // Displays the fourth complex number
}
```
### Output:
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/eedfcac2-99c1-45a3-8327-ced5435578da)

### The definitions of the functions for overloading `+` and `–` binary operators are given as:
In the following C++ program, the binary operators `+` and `-` are overloaded for a complex number class (`complex`). The definitions of the operator functions are provided as follows:

```cpp
complex operator + (complex c)
{
    complex temp;
    temp.real = real + c.real;
    temp.imaginary = imaginary + c.imaginary;
    return temp;
}

complex operator - (complex c)
{
    complex temp;
    temp.real = real - c.real;
    temp.imaginary = imaginary - c.imaginary;
    return temp;
}
```

These operator functions add and subtract two complex numbers, respectively, and return the resultant complex values. Notably, both functions receive only one value as an argument.

### Operator Function Invocation

When using these overloaded operators, an object of the same class can invoke a member function. For example:

```cpp
c3 = c1 + c2; // Invokes operator + ( ) function
c4 = c1 - c2; // Invokes operator - ( ) function
```

These statements are equivalent to the following usual function call syntax:

```cpp
c3 = c1.operator + (c2);
c4 = c1.operator - (c2);
```

In these operator functions (`operator + ( )` and `operator - ( )`), the data members of `c1` are accessed directly, and the data members of `c2` (passed as an argument) are accessed using the dot operator (`.`). Both objects are available for the function.

### Nameless Temporary Object

To avoid the creation of the `temp` object, the entire function body can be replaced with the following statements:

```cpp
complex operator + (complex c)
{
    return complex((real + c.real), (imaginary + c.imaginary));
}

complex operator - (complex c)
{
    return complex((real - c.real), (imaginary - c.imaginary));
}
```

In these cases, the compiler invokes an appropriate constructor, initializes a nameless temporary object, and returns its contents for copying into another object. Using nameless temporary objects can make the code shorter, more efficient, and better to read.

For this purpose, a constructor is already defined in the class definition:

```cpp
complex(float r, float i)
{
    real = r;
    imaginary = i;
}
```
### Program:
```cpp
#include<iostream.h>
class complex
{
private:
 float real, imaginary ;
public:
complex( ) // Default Constructor without arguments
{ }
complex(float r, float i) // Constructor with arguments
{
real = r ;
imaginary = i ;
}
void enterdata(void)
{
 cout << "\n Enter the real part of the second complex number: ” ;
 cin >> real ;
 cout << "\n Enter the imaginary part of the second complex number: "
;
 cin >> imaginary ;
}
void display(void)
{
 if (imaginary >= 0)
cout << real << "+" << imaginary << " i" << endl ;
else
cout << real << imaginary << " i" << endl ;
}
// Operator Function Definition for overloading the binary operator +
complex operator + (complex C)
{
 return complex( (real + C.real), (imaginary + C.imaginary) ) ;
}
// Operator Function Definition for overloading the binary operator -
complex operator - (complex C)
{
 return complex( (real - C.real), (imaginary - C.imaginary) ) ;
}
}; // End of the class definition
void main(void)
{
complex c1(2.5, 4.5), c2 ; // Object Definitions
cout << "\n The first complex number i.e. c1 is: " ;
c1.display( ) ; // Displays the first complex number
c2.enterdata( ) ;
cout << "\n The second complex number i.e. c2 is: " ;
c2.display( ) ; // Displays the second complex number continued
complex c3 = c1 + c2 ;
cout << "\n The sum of two complex numbers i.e. c1 and c2 is: " ;
c3.display( ); // Displays the third complex number
complex c4 = c1 - c2 ;
cout << "\The subtraction of the complex numbers, c2 from c1 is: " ;
c4.display( ); // Displays the fourth complex number
}
```
### Output:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/b6c2738b-48b9-447b-8449-a469753d31b2)

## Similarly you can overload other operators as well to see overloading or other operators please refer to the web.

### Points to remember:
 1. While overloading the binary operator, left
hand operand is used to invoke the operator
function and the right-hand operand is passed as
an argument.
2. An overloaded operator always requires one
less argument than its number of operands,
since one operand is the object of which the
operator is the member function. That’s why
unary operators require no argument.

### Overloading using the friend function
```cpp
#include<iostream.h>
#include<conio.h>
class Complex
{
int real, imag ;
public:
Complex()
{
real = 0;
imag = 0;
}
Complex(int r, int i)
{
real = r ;
imag = i ;
}
// Overloading using friend function
friend Complex operator + (Complex c1, Complex c2)
{
Complex temp ;
temp.real = c1.real + c2.real ;
temp.imag = c1.imag + c2.imag ;
return temp ;
}
void display()
{
cout << "\n The complex no is: ";
if(real >=0)
cout << real << "+" << imag << "i";
else
cout << real << imag << "i";
}
} ;
void main()
{
Complex c1(5, 6);
Complex c2(2, 3);
c1.display();
c2.display();
Complex c3 = c1 + c2 ; // call to the operator function
cout << "\n After addition\n";
c3.display();
}
```
