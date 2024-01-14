# Data Conversion

## Data Conversion between Same Data-Types (Basic or User-Defined)

The assignment operator (`=`) is used to assign a value from one variable to another. For instance:

```cpp
int y = 10;
int x = y;
```

In the context of user-defined data types, such as complex objects, the assignment works similarly:

```cpp
complex c1(2.5, 5), c2, c3;
c3 = c1 + c2;
```

When the value of one object is assigned to another object of the same type, the values of all the data members are copied into the corresponding data members of the new object. The compiler handles these assignments automatically, requiring no special instructions.

## Data Conversion between Different Data-Types

Consider the case when variables on the two sides of the `=` are of different types. For basic-type variables, the compiler handles conversion automatically:

```cpp
int i;
float f = 7.5;
i = f;
```

Many such conversions, like from float to double or char to float, are handled by built-in routines in the compiler. These are known as implicit conversions.

In situations where explicit conversion is needed, typecasting can be employed. For example:

```cpp
float a = 7.5;
int b;
b = int(a);
```

Typecasting provides explicit conversion, using the same built-in routines as implicit conversions.

## Conversion Between Objects of Different Classes

There are three types of situations in data conversion between incompatible types:

1. **Conversion from built-in type to class type.**
2. **Conversion from class type to built-in type.**
3. **Conversion from one class type to another class type.**

### Program: This program illustrates the conversion from built-in type to user defined and from user-defined type to the built-in type
```cpp
#include<iostream.h>
const float M = 1.61 ;
class Distance
{
int Kmeter ;
int meter ;
public:
Distance( ) // Default constructor without any argument
{ Kmeter= 0;
 meter = 0;
}
 // This function converts built-in type i.e. mile to the user-defined type i.e. Distconv
Distance(float mile) // Constructor with one argument
{
 float Km = M * mile ; // converts mile to Km
 Kmeter = int(Km); // converts float Km to int and assigns to Kmeter
 meter = (Km - Kmeter) * 1000 ; // converts to meter
}
Distance(int k, float m) // Constructor with two arguments
{
Kmeter = k ;
meter = m ;
}
Cont.
void Display(void)
{
 cout << Kmeter << " Kilometers and " << meter << " meters "
;
}
// ********Conversion Function************
operator float( ) // converts user-defined type i.e. Distconv to the
{ // basic-type i.e. meter
float K = float(meter)/1000.0 ; // Converts the meters to Kilometers
K += float(Kmeter) ; // Adds the Kmeter
return K / M ; // Converts to mile
}
}; // End of the Class Definition
void main(void)
{
float mile = 5.0;
Distance d1(mile); // Uses the constructor with one argument
//Distance d1 = 5.0 ;
//Distance d1 = Distance(5.0);
cout << "\n d1 = " ;
d1.Display( ) ;
d1 = 2.0 ; // This form also uses the constructor with one argument
cout << "\n d1 = " ;
d1.Display( ) ;
Distance d2( 2, 25 ); // Uses the constructor with two arguments
float ml = float(d2) ; // This form uses the conversion function and
 // converts Distconv to mile
cout << "\n d2 = " << ml << " miles " ;
ml = d1 ; // This form also uses conversion function and
 // converts Distconv to mile
cout << "\n d1 = " << ml << " miles " ;
}
```
### Output:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/bdcfb6f6-071d-4751-a592-89d271761020)

## Conversion from Basic Type to User-Defined (Class) Type

Basic types can be easily converted to class types using a constructor. For example, in the following program, a constructor with one argument is used to convert the basic type `float` to the user-defined type `Distconv`:

```cpp
Distconv(float mile)
{
    float Km = M * mile;
    Kmeter += int(Km);
    meter = (Km - Kmeter) * 1000;
}
```

This constructor is called when an object of type `Distconv` is created with a single argument, as demonstrated by the statement:

```cpp
Distconv d1 = 5.0;
```

Here, the function assumes that the argument represents miles and converts it to kilometers and meters.

Another way to perform the same conversion is shown in the main program:

```cpp
d1 = 2.0;
```

This statement converts the basic type `float` to `Distconv` without creating a new object, utilizing the one-argument constructor. However, it creates a nameless temporary object with `Kmeter` and `meter` values corresponding to 2.0 miles.

## Conversion from User-Defined (Class) Type to Basic Type

While constructors handle type conversion from a basic type to a user-defined type, they cannot be used when converting from a user-defined type to a basic type. C++ allows defining an overloaded casting operator, known as a conversion function, for this purpose. The general form is:

```cpp
operator typename( )
{
    // Statements for conversion
}
```

For instance, in the program, the conversion function `operator float( )` converts a class object to the `float` type:

```cpp
Distconv::operator float( )
{
    float K = meter / 1000;
    K += float(K);
    return (K / M);
}
```

- Conversion functions have no arguments.
- Conversion functions don't have any explicit return type (implicitly the conversion type).
- Conversion functions can be inherited, and virtual conversion functions are possible.
- Conversion functions cannot be made static.

## Conversion Between Objects of Different Classes

The conversion between objects of different classes can be done using a one-argument constructor or a conversion function. The choice depends on whether the conversion routine has to be declared in the source class or the destination class.

- **Using Conversion Function:** If the conversion routine should be in the source class B, then the conversion function is used.
- **Using Constructor with One Argument:** If the conversion routine should be in the destination class A, then the constructor with one argument is used. The constructor in the destination class A must be able to access the data in the source class B to perform the conversion.

### Program using the conversion function:
```cpp
#include<iostream.h>
class Distance1 // Destination class
{
private:
float Kmeter ;
public:
Distance1( )
{ Kmeter = 0.0 ; }
Distance1(float k)
{ Kmeter = k ; }
void display( )
{ cout << Kmeter << " Kilometers" ; }
};
class Distance2 // Source class
{
private:
int meter, cmeter;
public:
Distance2( )
{ meter = cmeter = 0 ; }
Distance2(int m, int c)
{
 meter = m ;
 cmeter = c ;
}
void display(void)
{ cout << meter << " Meters " << cmeter << " Centimeters" ; }
operator Distance1 ( ) // Conversion Function
{
float Km = meter/1000.0 ;
Km += cmeter/100000.0 ;
Distance1 d1(Km);
return d1 ;
//return Distance1(Km) ;
}
}; // End of the class definition
void main(void)
{
Distance1 d1 ; // Object of the destination class
Distance2 d2(1000, 100) ; // Object of the source class
d1 = d2 ; // Conversion of type Distance2 to the type Distance1
cout << "\n Distance2 = " ;
d2.display ( ) ;
cout << "\n Distance1 = " ;
d1.display( ) ;
}
```
### Output:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/0ed4cba9-cc50-477b-9b90-193a5f94c27e)

# C++ Program Explanation: Conversion Between Objects of Different Classes

## Program Overview

The above program contains two classes: `Distance1` and `Distance2`. In the `main()` function, the first statement declares an object `d1` of class `Distance1`:

```cpp
Distance1 d1;
```

The second statement declares an object `d2` of class `Distance2` and initializes it to (1000, 100):

```cpp
Distance2 d2(1000, 100);
```

The third statement:

```cpp
d1 = d2;
```

Converts the object `d2` of the source class `Distance2` to the object `d1` of the destination class `Distance1`.

## Conversion Function

The conversion function is declared in the source class `Distance2` as:

```cpp
operator Distance1( ) // Conversion Function
{
    float Km = meter / 1000.0;
    Km += cmeter / 100000.0;
    return Distance1(Km);
}
```

This function transforms the object of which it is a member to a `Distance1` object and returns this object. The `main()` function then assigns this object to `Distance2`.
### This program illustrates the conversion from an object of a class to the object of another class, using the constructor. 
```cpp
#include<iostream.h>
class Distance2 // Source class
{
private:
int meter, cmeter ;
public:
Distance2( )
{ meter = cmeter = 0 ; }
Distance2(int m, int c)
{ meter = m; cmeter = c;
}
void display(void)
{
cout << meter << "Meters " << cmeter << "Centimeters" ;
}
int getm(void) // This function allows the data member “meter” to be
{ // accessed from outside the class.
 return meter ;
}
int getcm(void) // This function allows the data member “cmeter” to be
{ // accessed from outside the class.
 return cmeter ;
}
} ;
class Distance1 // Destination Class
{
private:
 float Kmeter ;
public:
 Distance1( )
 { Kmeter = 0.0; }
 Distance1(float k)
 { Kmeter = k ; }
 // Converstion routine
 Distance1(Distance2 d2) // Constructor with an argument of type Distance2
 {
 float a = d2.getm( ); // Access “meter” from the class Distance2, using the
//member function getm( )
 float b = d2.getcm( ); // Access “cmete”r from the class Distance2, using the
 // member function getcm()
 Kmeter = a/1000.0 + b/100000.0 ;
 }
 void display(void)
 { cout << Kmeter << " Kilometers" ; }
};
void main(void)
{
Distance1 d1 ;
Distance2 d2(1000, 100);
d1 = d2 ;
cout << "\n Distance2 = " ; d2.display( );
cout << "\n Distance1 = " ; d1.display( );
}
```
### Output:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/3bbaad2b-07ff-48b1-9a3e-623301027cd4)

## Program Overview

The above program uses the constructor with one argument to convert an object `d2` of class `Distance2` to the object `d1` of the class `Distance1`. This conversion constructor is utilized in the destination class `Distance1`. To perform the conversion, this constructor must be able to access the data members (`meter` and `cmeter`) of the `Distance1` object sent as an argument.

For this purpose, the `Distance1` class contains the following member functions, defined in the public area:

```cpp
int getm(void)
{
    return meter;
}

int getcm(void)
{
    return cmeter;
}
```

## Conversion Constructor

The one-argument constructor is specified in the destination class `Distance1` as:

```cpp
Distance1(Distance2 d2) // Constructor with an argument of type Distance2
{
    float a = d2.getm();
    float b = d2.getcm();
    Kmeter = a / 1000.0 + b / 100000.0;
}
```

This constructor converts the object (`meter` and `cmeter`) of the class `Distance2` to the object (`Kmeter`) of the `Distance1` class type.
