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

