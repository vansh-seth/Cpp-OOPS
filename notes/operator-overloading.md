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
- After the statement
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

