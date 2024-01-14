# Inheritance in C++

Inheritance is the process of creating new classes from existing class or classes. Using inheritance, one can create a general class that defines traits common to a set of related items. This class can then be inherited (reused) by other classes, utilizing the properties of existing ones with the addition of their unique properties.

The old class is referred to as the base class, and the new classes, which are inherited from the base class, are called derived classes.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/1dfa78c7-45a8-417a-b464-1444dfe2bb18)

- In above figure, the class B contains the three member i.e. Property1, Property2 and Property3.
- The second class named as D contains four members i.e. Property1, Property2, Property3 and Property4.
- Out of these, three members (Property1, Property2, Property3) of the class D are same as that of class B, while the one member i.e. Property4 is unique.
- In the class D, instead of defining all the three members again, one can reuse them from the class B. This feature is known as
inheritance which saves time, space, money and increases the reliability and efficiency.

## Types of Inheritance

1. **Single Inheritance:**
   - If a class is derived from a single base class, it is called single inheritance.

2. **Multiple Inheritance:**
   - If a class is derived from more than one base class, it is known as multiple inheritance.

3. **Multilevel Inheritance:**
   - The classes can also be derived from classes that are already derived. This type of inheritance is called multilevel inheritance.

4. **Hierarchical Inheritance:**
   - If a number of classes are derived from a single base class, it is called hierarchical inheritance.

## Syntax of Derived Class

A derived class can be defined as follows:

```cpp
class derived_class_name : access_specifier base_class_name
{
    // Data members of the derived class ;
    // Member functions of the derived class ;
}
```

- The colon (`:`) indicates that the class `derived_class_name` is derived from the class `base_class_name`.
- The `access_specifier` may be public, private, or protected (will be discussed further).
- If no `access_specifier` is specified, it is private by default.
- The `access_specifier` indicates whether the members of the base class are privately derived or publicly derived.

## Public Inheritance

When a derived class publicly inherits the base class, all the public members of the base class become public to the derived class, and objects of the derived class can access the public members of the base class.

Here's a basic example:

```cpp
class B {
    // Base class members
};

class D : public B {
    // Derived class members
};
```

This program illustrates the use of single inheritance where class `D` is publicly inherited from the base class `B`.

### Example: 
```cpp
#include<iostream.h>
class Rectangle
{
 private:
float length ; // This can't be inherited
 public:
float breadth ; // The data and member functions are inheritable
void Enter_lb(void)
{
 cout << "\n Enter the length of the rectangle : ";
 cin >> length ;
 cout << "\n Enter the breadth of the rectangle : ";
 cin >> breadth ;
}
float get_l(void)
{ return length ; } // This member function is used to get the value of data member ‘length’ in the derived class
}; // End of the class definition
class Rectangle1 : public Rectangle //The base class is publicly inherited by the derived class. Thus all the public members of the base class can be inherited by the derived class.
{
 private:
float area ;
 public:
void Rec_area(void)
{ area = get_l( ) * breadth ; }
// area = length * breadth ; can't be used here
//The data member “length” of the base class can’t be inherited as it is defined in private mode.
//Thus the member function Enter_l() is used here which is declared in the public mode in the base class.
void Display(void)
 {
 cout << "\n Length = " << get_l( ) ; // Object of the derived class can't
 // inherit the private member of the base class. Thus the member
 // function is used here to get the value of data member 'length'.
 cout << "\n Breadth = " << breadth ;
 cout << "\n Area = " << area ;
 }
}; // End of the derived class definition D
void main(void)
{
Rectangle1 r1 ;
r1.Enter_lb( );
r1.Rec_area( );
r1.Display( );
}
```
### Public inheritance diagram:

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/168b8946-8289-4e16-90b9-d1fcd1e9a60a)

## Private inheritance
- When a derived class privately inherits a base class, all the public members of the base class become private for the derived class.
- In this case, the public members of the base class can only be accessed by the member functions of the derived class.
- The objects of the derived class cannot access the public members of the base class.
- Note that whether the derived class is inherited publicly or privately from the base class, the private members of the base class cannot be inherited.

- ## Example:
```cpp
#include<iostream.h>
class Rectangle // Base class
{
private:
float length ; // This data member can't be inherited
public:
float breadth ; // This data member is inheritable
void Enter_lb(void)
{
cout << "\n Enter the length of the rectangle: "; cin >> length ;
cout << "\n Enter the breadth of the rectangle: "; cin >> bredth ;
}
float Enter_l(void)
{
return length ;
}
void Display_l(void)
{
cout << "\n Length = " << length ;
}
}; // End of the base class Rectangle
// Defining the derived class Rectangle1. This class has been derived from the
// base class i.e. Rectangle, privately.
class Rectangle1 : private Rectangle // All the public members of the base class
{ // Rectangle become private for the derived class Rectangle1.
private:
float area ;
public:
void Rec_area(void)
{
 Enter_lb( );
 area = Enter_l( ) * bredth ; // length can't be used directly
}
void Display(void)
{
Display_l( ); // Displays the value of length.
cout << "\n Bredth = " << bredth ;
cout << "\n Area = " << area << endl ;
}
};
void main(void)
{
Rectangle1 r1 ;
r1.Rec_area( ) ;
// r.Enter_lb( ); will not work as it has become private for the derived class.
r1.Display( ) ;
 // r.Display_l( ) will not work as it also has become private for the derived class.
}
  ```

## Diagram Private Inheritance

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/51d44462-0174-4603-bf41-160b09c4a747)

## Protected Access Specifier in C++

The protected access specifier in C++ is the third access specifier provided by the language. It introduces a level of visibility between public and private.

- Members declared as protected can be accessed by the member functions within their own class and any other class immediately derived from it.
- These protected members cannot be accessed by functions outside these two classes.
- Consequently, objects of the derived class cannot directly access the protected members of the base class.

### Inheritance and Protected Members

- When protected members (data and functions) are inherited in public mode, they become protected in the derived class. This allows them to be accessed by the member functions of the derived class.
- If the protected members are inherited in private mode, they become private in the derived class. Although accessible by the member functions of the derived class, they cannot be inherited further.

### Accessibility Table:

| Access Specifier | Accessibility from Own Class | Accessibility from Derived Class | Accessibility from Objects Outside the Base Class |
| ---------------- | ---------------------------- | --------------------------------- | ------------------------------------------------- |
| public           | Valid                        | Valid                             | Valid                                             |
| protected        | Valid                        | Valid                             | Not Valid                                          |
| private          | Valid                        | Not Valid                         | Not Valid                                          |

This table summarizes the accessibility of members based on the access specifier.

```cpp
#include<iostream.h>

class Base
{
private:
    int basedata1;
protected:
    int basedata2;
public:
    int basedata3;

    void get_base_data()
    {
        cout << "\n Enter basedata1: ";
        cin >> basedata1; // accessible
        cout << "\n Enter basedata2: ";
        cin >> basedata2; // accessible
        cout << "\n Enter basedata3: ";
        cin >> basedata3; // accessible
    }

    void display_base_data()
    {
        cout << "\n basedata1 = " << basedata1;
        cout << "\n basedata2 = " << basedata2;
        cout << "\n basedata3 = " << basedata3;
    }
};

class Derive : public Base
{
private:
    int derivedata1;
protected:
    int derivedata2;
public:
    int derivedata3;

    void get_derive_data()
    {
        cout << "\n Enter basedata1: ";
        // cin >> basedata1; // not accessible; private data of base class
        cout << "\n Enter basedata2: ";
        cin >> basedata2; // accessible; protected data of base class
        cout << "\n Enter basedata3: ";
        cin >> basedata3; // accessible; public data of the base class
        cout << "\n Enter derivedata1: ";
        cin >> derivedata1; // accessible
        cout << "\n Enter derivedata2: ";
        cin >> derivedata2; // accessible
        cout << "\n Enter derivedata3: ";
        cin >> derivedata3; // accessible
    }

    void display_derive_data()
    {
        cout << "\n basedata1 = " << basedata1; // Note: basedata1 not accessible in derived class
        cout << "\n basedata2 = " << basedata2;
        cout << "\n basedata3 = " << basedata3;
        cout << "\n derivedata1 = " << derivedata1;
        cout << "\n derivedata2 = " << derivedata2;
        cout << "\n derivedata3 = " << derivedata3;
    }
};

void main()
{
    Base bobj;
    // bobj.basedata1 = 10; // Not accessible; private data of base class
    // bobj.basedata2 = 20; // Not accessible; protected data of base class
    bobj.basedata3 = 30; // Accessible
    bobj.get_base_data(); // accessible
    bobj.display_base_data(); // accessible

    Derive dobj;
    // dobj.basedata1 = 5; // Not accessible; private data of base class
    // dobj.basedata2 = 6; // Not accessible; protected data of base class
    dobj.basedata3 = 7; // Accessible
    // dobj.derivedata1 = 8; // Not accessible; private data of derived class
    // dobj.derivedata2 = 9; // Not accessible; protected data of derived class
    dobj.derivedata3 = 10; // Accessible
    dobj.get_base_data(); // Accessible
    dobj.display_base_data(); // Accessible
    dobj.get_derive_data(); // Accessible
    dobj.display_derive_data(); // Accessible
}
```
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/16b093a5-93a9-46be-b44e-d464354b388b)

## Overriding the member functions:
- The member functions can also be used in a derived class, with the same name as those in the base class.
- One might want to do this so that calls in the program work the same way for objects of both base and derived classes. 

## Example: Overriding of member function
```cpp
#include<iostream.h>
const int len = 20 ;
class Employee
{
private:
char F_name[len];
int I_number ;
int age ;
float salary ;
public:
void Enter_data(void)
{
cout << "\n Enter the first name = " ; cin >> F_name ;
cout << "\n Enter the identity number = " ; cin >> I_number ;
cout << "\n Enter the age = " ; cin >> age ;
cout << "\n Enter the salary = " ; cin >> salary ;
}
void Display_data(void)
{
cout << "\n Name = " << F_name ;
cout << "\n Identity Number = " << I_number ;
cout << "\n Age = " << age ;
cout << "\n Salary = " << salary ;
}
}; // End of the base class
class Engineer : public Employee
{
private:
char design[len] ; // S_Engineer, J_Engineer, Ex_Engineer etc
public:
void Enter_data( )
{
Employee :: Enter_data( ) ; // Overriding of the member function
cout << "\n Enter the designation of the Engineer: " ; cin >> design ;
}
void Display_data(void)
{
cout << "\n *******Displaying the particulars of the Engineer**** \n" ;
Employee :: Display_data( ) ; // Overriding of the member function
cout << "\n Designition = " << design ;
}
}; // End of the derived class
void main(void)
{
Engineer er ;
er.Enter_data( ) ;
er.Display_data( );
}
```
## Hierarchical Inheritance:
When two or more classes are derived from a single base class, then
Inheritance is called hierarchical inheritance. The representation
of the hierarchical inheritance is shown in the following Fig.
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/fdecc062-5231-4370-b6ad-b70f4062470e)
- In the above Fig., student is a base class, from which the three
classes viz. arts, science and commerce have been derived. Now,
let us write a program that illustrates the hierarchical inheritance,
based on the above design.

## Example:
```cpp
include<iostream.h>
const int len = 20 ;
class student // Base class
{
private: char F_name[len] , L_name[len] ;
 int age, int roll_no ;
public:
void Enter_data(void)
{
cout << "\n\t Enter the first name: " ; cin >> F_name ;
cout << "\t Enter the second name: "; cin >> L_name ;
cout << "\t Enter the age: " ; cin >> age ;
cout << "\t Enter the roll_no: " ; cin >> roll_no ;
}
void Display_data(void)
{
cout << "\n\t First Name = " << F_name ;
cout << "\n\t Last Name = " << L_name ;
cout << "\n\t Age = " << age ;
cout << "\n\t Roll Number = " << roll_no ;
}
};
class arts : public student
{
private:
 char asub1[len] ;
 char asub2[len] ;
 char asub3[len] ;
public:
void Enter_data(void)
{
student :: Enter_data( );
cout << "\t Enter the subject1 of the arts student: "; cin >> asub1 ;
cout << "\t Enter the subject2 of the arts student: "; cin >> asub2 ;
cout << "\t Enter the subject3 of the arts student: "; cin >> asub3 ;
}
void Display_data(void)
{
student :: Display_data( );
cout << "\n\t Subject1 of the arts student = " << asub1 ;
cout << "\n\t Subject2 of the arts student = " << asub2 ;
cout << "\n\t Subject3 of the arts student = " << asub3 ;
}
};
class science : public student
{
private:
char ssub1[len] ;
char ssub2[len] ;
char ssub3[len] ;
public:
void Enter_data(void)
{
student :: Enter_data( );
cout << "\t Enter the subject1 of the science student: "; cin >> ssub1;
cout << "\t Enter the subject2 of the science student: "; cin >> ssub2;
cout << "\t Enter the subject3 of the science student: "; cin >> ssub3;
}
void Display_data(void)
{
student :: Display_data( );
cout << "\n\t Subject1 of the science student = " << ssub1 ;
cout << "\n\t Subject2 of the science student = " << ssub2 ;
cout << "\n\t Subject3 of the science student = " << ssub3 ;
}
};
class commerce : public student
{
private: char csub1[len], csub2[len], csub3[len] ;
public:
void Enter_data(void)
{
student :: Enter_data( );
cout << "\t Enter the subject1 of the commerce student: ";
cin >> csub1;
cout << "\t Enter the subject2 of the commerce student: ";
cin >> csub2 ;
cout << "\t Enter the subject3 of the commerce student: ";
cin >> csub3 ;
}
void Display_data(void)
{
student :: Display_data( );
cout << "\n\t Subject1 of the commerce student = " << csub1 ;
cout << "\n\t Subject2 of the commerce student = " << csub2 ;
cout << "\n\t Subject3 of the commerce student = " << csub3 ;
}
};
void main(void)
{
arts a ;
cout << "\n Entering details of the arts student\n" ;
a.Enter_data( );
cout << "\n Displaying the details of the arts student\n" ;
a.Display_data( );
science s ;
cout << "\n\n Entering details of the science student\n" ;
s.Enter_data( );
cout << "\n Displaying the details of the science student\n" ;
s.Display_data( );
commerce c ;
cout << "\n\n Entering details of the commerce student\n" ;
c.Enter_data( );
cout << "\n Displaying the details of the commerce student\n";
c.Display_data( );
}
```

## Multiple Inheritance
- When a class is inherited from more than one base class, it is known as multiple inheritance.
- The syntax for defining a subclass, which is inheriting more than one classes is:
 ```cpp
class Subclass : access_specifier Baseclass1,
 access_specifier Baseclass2, ………
 …….. access_specifier Baseclass_n
{
members of the derived class ;
};
```
- The following figure illustrates the use of multiple inheritance.
  
![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/bf02c56b-96f1-45b3-908f-57bbf96514a0)

- In the above figure, Circle and Rectangle are two base classes from which the class Cylinder is being inherited.
- The data members of both the base classes are declared in protected mode. Thus, the class Cylinder can access the data member radius of class Circle and data member length, breadth of the class Rectangle, but the objects of the class Cylinder cannot access these protected data members.
- The volume of the cylinder is equal to 22/7*(radius*radius*length). Thus, instead of defining these data again, they can be inherited from the base classes Circle and Rectangle ( radius from class Circle and length from class Rectangle ).

- ## Example:
- #include<iostream.h>
```cpp
class Circle // First base class
{
protected:
float radius ;
public:
void Enter_r(void)
{
cout << "\n\t Enter the radius: "; cin >> radius ;
}
void Display_ca(void)
{
cout << "\t The area = " << (22/7 * radius*radius) ;
}
};
class Rectangle // Second base class
{
protected:
float length, breadth ;
public:
void Enter_lb(void)
{
cout << "\t Enter the length : "; cin >> length ;
cout << “\t Enter the breadth : ” ; cin >> breadth ;
}
void Display_ar(void)
{
cout << "\t The area = " << (length * breadth);
}
};
class Cylinder : public Circle, public Rectangle // Derived class, inherited
{ // from classes Circle & Rectangle
public:
void volume_cy(void)
{
cout << "\t The volume of the cylinder is: "
 << (22/7* radius*radius*length) ;
}
};
void main(void)
{
Circle c ;
cout << "\n Getting the radius of the circle\n" ;
c.Enter_r( );
c.Display_ca( );
Rectangle r ;
cout << "\n\n Getting the length and breadth of the rectangle\n\n";
r.Enter_lb( );
r.Display_ar( );
Cylinder cy ; // Object cy of the class cylinder which can access all the
 // public members of the class circle as well as of the class rectangle
cout << "\n\n Getting the height and radius of the cylinder\n";
cy.Enter_r( );
cy.Enter_lb( );
cy.volume_cy( );
}
```
## Multilevel Inheritance:
C++ also provides the facility of multilevel
inheritance, according to which the derived class
can also be derived by an another class, which in
turn can further be inherited by another and so on.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/25598ec1-fb58-4a0c-9c7c-baa0926994ee)

In the above figure, class B represents the base class. The class D1
that is called first level of inheritance, inherits the class B. The
derived class D1 is further inherited by the class D2, which is
called second level of inheritance.

## Example
```cpp
#include<iostream.h>
class Base
{
protected:
int b;
public:
void EnterData( )
{
cout << "\n Enter the value of b: ";
cin >> b;
}
void DisplayData( )
{
cout << "\n b = " << b;
}
};
class Derive1 : public Base
{
protected:
int d1;
public:
void EnterData( )
{
Base:: EnterData( );
cout << "\n Enter the value of d1: ";
cin >> d1;
}
void DisplayData( )
{
Base::DisplayData();
cout << "\n d1 = " << d1;
}
};
class Derive2 : public Derive1
{
private:
int d2;
public:
void EnterData( )
{
Derive1::EnterData( );
cout << "\n Enter the value of d2: ";
cin >> d2;
}
void DisplayData( )
{
Derive1::DisplayData( );
cout << "\n d2 = " << d2;
}
};
int main( )
{
Derive2 objd2;
objd2.EnterData( );
objd2.DisplayData( );
return 0;
}
```

## Constructors Revisited in C++

In object-oriented programming, a constructor in a class is a special block of statements executed when an object is created, typically at the moment of declaration. Unlike regular methods, a constructor has no explicit return type, is not inherited, and often shares the same name as the declaring class.

### Key Characteristics of Constructors:

- **Initialization Responsibility:** Constructors are responsible for pre-defining the object's data members, ensuring that an object is in a valid state upon creation.

- **Overloading:** In most languages, constructors can be overloaded, meaning a class can have more than one constructor, each with different parameters.

- **Special Types:**
  - **Default Constructor:** Takes no arguments.
  - **Copy Constructor:** Takes one argument of the type of the class.

### Differences from Other Member Functions:

- Constructors never have an explicit return type.
- Constructors cannot be overridden, nor are they inherited.
- Constructors cannot be declared as `const`.
- Constructors cannot be declared as `virtual`.
- Constructors cannot be declared as `static`.

## Constructors in single inheritance:
```cpp
// This program illustrates the use of constructors in the single inheritance
#include<iostream.h>
class A // Base class
{
 private:
 int x ;
 public:
 A( ) // Constructor without any argument
 {
 x = 0 ;
cout << "\n The constructor of the class A without any argument is invoked*** " ;
 }
 A(int X) // Constructor with one argument
 {
 x = X ;
 cout << "\n The constructor of the class A with one argument is invoked***" ;
 }
 void Enter_x(void)
 {
cout << "\n\n\t Enter the value of x: "; cin >> x ;
 }
 void Display_x(void)
 { cout << "\n\t x = " << x ; }
};
// ***************Derived Class******************
class B : public A
{
 private:
 int y ;
 public:
 B( ) : A ( ) // Constructor of the derived class B without any argument
 {
 y = 0 ;
 cout << "\n The constructor of the class B without any argument is invoked**" ;
 }
 // Constructor of the derived class B with two arguments
 B(int X, // Argument for constructor A
 int Y) // Argument for constructor B
 : A(X) // Call for the constructor A
 {
 y = Y ;
 cout << "\n The constructor of the class B with two arguments is invoked***" ;
 }
 void Enter_y(void)
 { cout << "\t Enter the value of y: " ; cin >> y ; }
 void Display_y(void)
 { cout << "\n\t y = " << y ; }
};
void main(void)
{
cout << "\n\n The first object b1 is in use********\n " ;
B b1 ; // Invokes the constructor with zero arguments
b1.Enter_x( );
b1.Enter_y( );
b1.Display_x( );
b1.Display_y( );
cout << "\n\n The second object b2 is in use********\n " ;
B b2(5, 6); // Invokes the constructor with two arguments
b2.Display_x( );
b2.Display_y( );
}
```
### Output:
```
The first object b1 is in use********
The constructor of class A without any argument is invoked*******
The constructor of class B without any argument is invoked*******
Enter the value of x: 10
Enter the value of y: 12
x = 10
y = 12
The second object b2 is in use********
The constructor of class A with one argument is invoked******
The constructor of class B with two arguments is invoked*****
x = 5
y = 6
```
### Constructors in multilevel inheritance:
```cpp
# include<iostream.h>
class A
{
protected:
int x ;
public:
A( ) // Constructor without argument
{
 x = 0 ;
 cout << "\n Constructor of class A without any argument is invoked" ;
}
A(int X) // Constructor with one argument
{
 x = X ;
 cout << "\n Constructor of class A with one argument is invoked" ;
}
void Enter_x(void)
{ cout << "\n\t Enter the value of x: " ; cin >> x ; }
void Display_x(void)
{ cout << "\n\t x = " << x ; }
};
class B : public A
{
protected:
int y ;
public:
B( ) : A( ) // Constructor without argument
{
y = 0;
cout << "\n Constructor of class B without any argument is invoked" ;
}
 // Constructor with two arguments
B( int X, // Argument for constructor A
 int Y ) // Argument for constructor B
 : A(X) // Call for constructor A
{
 y = Y;
 cout << "\n Constructor of class B with two arguments in invoked" ;
}
void Enter_y(void)
{ cout << "\t Enter the value of y: " ; cin >> y ; }
void Display_y(void)
{ cout << "\n\t y = " << y ; }
};
class C : public B
{
private:
int z ;
public:
C( ) : B( ) // Constructor without argument
{
 z = 0;
 cout << "\n Constructor of class C without any argument is invoked\n" ;
}
// Constructor with three arguments
C(int X, int Y, // Arguments for constructor B
 int Z) // Argument for constructor C
 : B(X, Y) // Call for constructor B
{
 z = Z ;
 cout << "\n Constructor of class C with three arguments is invoked" ;
}
void Enter_z(void)
{ cout << "\t Enter the value of z: " ; cin >> z ; }
void Display_z(void)
{ cout << "\n\t z = " << z ; }
};
void main(void)
{
cout << "\n The first object is in use now******** \n " ;
C c1 ;
c1.Enter_x( );
c1.Enter_y( );
c1.Enter_z( );
c1.Display_x( );
c1.Display_y( );
c1.Display_z( );
cout << "\n\n The second object is in use now******** \n" ;
C c2(5, 6, 7) ;
c2.Display_x( );
c2.Display_y( );
c2.Display_z( );
}
```

### Output:
```
The first object is in use now*********
Constructor of class A without any argument is invoked
Constructor of class B without any argument is invoked
Constructor of class C without any argument is invoked
Enter the value of x: 11
Enter the value of y: 13
Enter the value of z: 27
x = 11
y = 13
z = 27
The second object is in use now*********
Constructor of class A with one argument is invoked
Constructor of class B with two arguments is invoked
Constructor of class C with three arguments is invoked
x = 5
y = 6
z = 7
```

## Constructors in multiple Inheritance:
```cpp
#include<iostream.h>
class A // First Base class
{
private:
int x ;
public:
A( ) // Constructor of the base class A without any argument
{
 x = 0 ;
 cout << "\n Constructor of class A without any argument is invoked" ;
}
A(int X) // Constructor of the base class A with one argument
{
 x = X ;
 cout << "\n Constructor of class A with one argument is invoked" ;
}
void Enter_x(void)
{ cout << "\n\n\t Enter the value of x: " ; cin >> x ; }
void Display_x(void)
{ cout << "\n\t x = " << x ; }
};
class B // Second Base class
{
private:
int y ;
public:
B( )
{
 y = 0 ; // Constructor of the base class B without any argument
 cout << "\n Constructor of class B without any argument is invoked“ ;
}
B(int Y) // Constructor of the base class B with one argument
{
y = Y ;
cout << "\n Consrtuctor of class B with one argument isinvoked" ;
}
void Enter_y(void)
{ cout << "\t Enter the value of y: " ; cin >> y ; }
void Display_y(void)
{ cout << "\n\t y = " << y ; }
};
class C : public B, public A //Derived class, inherited from base classes A & B
{
private:
int z ;
public:
C( ) : A( ), B( ) // Constructor of the derived class C without any argument
{
z = 0 ;
cout << "\n Constructor of class C without any argument is invoked" ;
}
// *****Constructor of the derived class C with three arguments*****
C(int X, // Argument for the constructor A
 int Y, // Argument for the constructor B
 int Z) // Argument for the constructor C
 : A(X), B(Y) // Calls for the constructors A and B
{
z = Z ;
cout << "\n Consrtuctor of class C with three arguments is invoked\n" ;
}
void Enter_z(void)
{ cout << "\t Enter the value of z: " ; cin >> z ; }
void Display_z(void)
{ cout << "\n\t z = " << z ; }
};
void main(void)
{
cout << "\n The first object c1 is in use********\n" ;
C c1 ;
c1.Enter_x( );
c1.Enter_y( );
c1.Enter_z( );
c1.Display_x( );
c1.Display_y( );
c1.Display_z( );
cout << "\n\n The second object c2 is in use********\n" ;
C c2(5, 6, 7) ;
c2.Display_x( );
c2.Display_y( );
c2.Display_z( );
}
```

### Output:
```
The first object c1 is in use********
The constructor of class B without any argument is invoked
The constructor of class A without any argument is invoked
The constructor of class C without any argument is invoked
Enter the value of x: 9
Enter the value of y: 10
Enter the value of z: 12
x = 9
y = 10
z = 12
The first object c1 is in use********
The constructor of class B with one argument is invoked
The constructor of class A with one argument is invoked
The constructor of class C with three arguments is invoked
x = 5
y = 6
z = 7
```
