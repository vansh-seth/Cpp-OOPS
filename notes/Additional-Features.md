# Additional Features in C++ 
## Run-Time Type Identification (RTTI)
- In nonpolymorphic languages there is no need for RTTI because the type of each object is
known at compile time
- In C++, there are situations when the precise nature of that object is not determined until the
program is executed.
- base-class pointers may be used to point to objects of the base class or any object derived
from that base.
- It is not always possible to know in advance what type of object will be pointed to by a base
pointer at any given moment in time. | Need for RTTI

### Syntax:

- Include the header `<typeinfo>`
- Use typeid to know object type.
- Syntax
`typeid(object)`
- where object is the object whose type (built in or class type) you will be obtaining it returns a
reference to an object of type type_info that describes the type of object.
- The type_info class defines the following public members:
```
bool operator==(const type_info &ob);
bool operator!=(const type_info &ob);
bool before(const type_info &ob);
const char *name( );
```
- The overloaded `==` and `!=` provide for the comparison of types.
- The `before( )` function returns `true` if the invoking object is before the object used as a
parameter in collation order | mostly for internal use only
- The `name( )` function returns a pointer to the name of the type.

# Example:
```cpp
#include <iostream>
#include <typeinfo>
using namespace std;
class myclass1 {
// ...
};
class myclass2 {
// ...
};
int main() {
int i, j;
float f;
char *p;
myclass1 ob1;
myclass2 ob2;
cout << "The type of i is: " <<
typeid(i).name();
cout << endl;
cout << "The type of f is: " << typeid(f).name();
cout << endl;
cout << "The type of p is: " << typeid(p).name();
cout << endl;
cout << "The type of ob1 is: " << typeid(ob1).name();
cout << endl;
cout << "The type of ob2 is: " << typeid(ob2).name();
cout << "\n\n";
if(typeid(i) == typeid(j))
cout << "The types of i and j are the same\n";
if(typeid(i) != typeid(f))
cout << "The types of i and f are not the same\n";
if(typeid(ob1) != typeid(ob2))
cout << "ob1 and ob2 are of differing types\n";
return 0;
}
```

### Output:
```
The type of i is: int
The type of f is: float
The type of p is: char *
The type of ob1 is: class myclass1
The type of ob2 is: class myclass2
The types of i and j are the same
The types of i and f are not the same
ob1 and ob2 are of differing types

```
### Another Example
The most important use of typeid occurs when it is applied through a pointer of a polymorphic base class.
Here it will automatically return the type of the actual object being pointed to, which may be a base-class
object or an object derived from that base. 
```cpp
#include <iostream>
#include <typeinfo>
using namespace std;
class Mammal {
public:
virtual bool lays_eggs()
{ return false; }
// ...
};
class Cat: public Mammal {
public:
// ...
};
class Platypus: public Mammal {
public:
bool lays_eggs() { return true; }
// ...
};
int main()
{
Mammal *p, AnyMammal;
Cat cat;
Platypus platypus;
p = &AnyMammal;
cout << "p is pointing to an object of type ";
cout << typeid(*p).name() << endl;
p = &cat;
cout << "p is pointing to an object of type ";
cout << typeid(*p).name() << endl;
p = &platypus;
cout << "p is pointing to an object of type ";
cout << typeid(*p).name() << endl;
return 0;
}
```

### Output:
```
p is pointing to an object of type class Mammal
p is pointing to an object of type class Cat
p is pointing to an object of type class Platypus

```
Removing virtual keyword will result in following output:
```
p is pointing to an object of type class Mammal
p is pointing to an object of type class Mammal
p is pointing to an object of type class Mammal

```
## typeid Can Be Applied to Template Classes
Even though two objects are of the same template class type, if their parameterized data does not
match, they are not equivalent types.

```cpp
#include <iostream>
using namespace std;
template <class T> class myclass {
T a;
public:
myclass(T i) { a = i; }
// ...
};
int main()
{
myclass<int> o1(10), o2(9);
myclass<double> o3(7.2);
cout << "Type of o1 is ";
cout << typeid(o1).name() << endl;
cout << "Type of o2 is ";
cout << typeid(o2).name() << endl;
cout << "Type of o3 is ";
cout << typeid(o3).name() << endl;
cout << endl;
if(typeid(o1) == typeid(o2))
cout << "o1 and o2 are the same type\n";
if(typeid(o1) == typeid(o3))
cout << "Error\n";
else
cout << "o1 and o3 are different types\n";
return 0;
}

```

### Output:

```
Type of o1 is class myclass<int>
Type of o2 is class myclass<int>
Type of o3 is class myclass<double>
o1 and o2 are the same type
o1 and o3 are different types

```
## Applying typeid to object reference

- References to an object of a polymorphic class hierarchy work the same as pointers.
- When typeid is applied to a reference to an object of a polymorphic class, it will return the type of the object actually being referred to, which may be of a derived type.
- A common use of this feature is when objects are passed to functions by reference.

## Example:
```cpp
// Use a reference with typeid.
#include <iostream>
#include <typeinfo>
using namespace std;
class Mammal {
public:
virtual bool lays_eggs () { return false; } //
Mammal is polymorphic
// ...
};
class Cat: public Mammal {
public:
// ...
};
class Platypus: public Mammal {
public:
bool lays_eggs() { return true; }
// ...
};
// Demonstrate typeid with a reference parameter.
void WhatMammal (Mammal &ob)
{
cout << "ob is referencing an object of type ";
cout << typeid(ob).name() << endl;
}
int main()
{
Mammal AnyMammal;
Cat cat;
Platypus platypus;
WhatMammal (AnyMammal);
WhatMammal (cat);
WhatMammal (platypus);
return 0;
}
```

## Object factory:
- A function that produces objects is sometimes called an object factory.
- If there is no way to know in advance what type of object will be generated, use RTTI to know its type

```cpp
class Mammal {
public:
virtual bool lays_eggs() { return false; } //
Mammal is polymorphic
// ...
};
class Cat: public Mammal {
public:
// ...
};
class Platypus: public Mammal {
public:
bool lays_eggs() { return true; }
// ...
};
class Dog: public Mammal {
public:
// ...
};
// A factory for objects derived from Mammal.
Mammal *factory() {
switch(rand() % 3 ) {
case 0: return new Dog;
case 1: return new Cat;
case 2: return new Platypus;
}
return 0;
}
int main()
{
Mammal *ptr; // pointer to base class
int i;
int c=0, d=0, p=0;
// generate and count objects
for(i=0; i<10; i++) {
ptr = factory(); // generate an object
cout << "Object is " << typeid(*ptr).name();
cout << endl;
// count it
if(typeid(*ptr) == typeid(Dog)) d++;
if(typeid(*ptr) == typeid(Cat)) c++;
if(typeid(*ptr) == typeid(Platypus)) p++;
}
cout << endl;
cout << "Animals generated:\n";
cout << " Dogs: " << d << endl;
cout << " Cats: " << c << endl;
cout << " Platypuses: " << p << endl;
return 0;
}
```

### Output:
```
Object is class Platypus
Object is class Platypus
Object is class Cat
Object is class Cat
Object is class Platypus
Object is class Cat
Object is class Dog
Object is class Dog
Object is class Cat
Object is class Platypus
Animals generated:
Dogs: 2
Cats: 4
Platypuses: 4

```
