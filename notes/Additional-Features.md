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
## Mutable
- Class member functions may be declared as const, which causes this to be treated as a const pointer.
- A const object may not invoke a non-const member function. However, a const member
function can be called by either const or non-const objects.
- The main purpose of declaring a member function as const is to prevent it from modifying the
object that invokes it.
- Sometimes, we need const function to modify one or more members, but not all. Mutable overrides constness, i.e., a mutable member can be modified by a const memberfunction.

```cpp
class Demo {
mutable int i;
int j;
public:
int geti () const {
return i; // ok
}
void seti (int x) const {
i = x; // now, OK.
}
/* The following function won't compile.
void setj (int x) const {
j = x; // Still Wrong!
}
*/
};
int main()
{
Demo ob;
ob.seti (1900);
cout << ob.geti();
return 0;
}
```
### Another Example:
```cpp
class scrollbar
{
private:
int size; //related to constness
mutable string owner; //not relevant to constness
public:
scrollbar(int sz, string own) : size(sz), owner(own)
{ }
void setSize(int sz) //changes size
{ size = sz; }
void setOwner(string own) const //changes owner
{ owner = own; }
int getSize() const //returns size
{ return size; }
string getOwner() const //returns owner
{ return owner; }
};
int main()
{
//create constant object
const scrollbar obj (60, “Window1”);
// obj.setSize(100); //Error
obj.setOwner(“Window2”); //this is OK
cout << obj.getSize() << “, “ <<
obj.getOwner() << endl;
return 0;
}
```
## Explicit Constructors
- In one argument constructor, use either `obj (x)` or `obj = x` to initialize an object, i.e., there is a conversion from the type of that argument to the type of the class. To avoid automatic conversion, use explicit specifier.
- The explicit specifier applies only to constructors.
- Now, only constructors of the following form will be allowed: `myclass ob(4);`
- `myclass ob = 4; // Not allowed`
```cpp
#include <iostream>
using namespace std;
class myclass {
int a;
public:
explicit myclass(int x) { a = x; }
int geta() { return a; }
};
```

## Namespace
- Aim: To localize the visibility of names of identifiers to avoid name collisions.
- The namespace keyword allows you to partition the global namespace by creating a declarative region.
- In essence, a namespace defines a scope.
- Syntax:
```cpp
namespace name {
// declarations
}
```

### Example:
```cpp
#include <iostream>
using namespace std;
namespace CounterNameSpace {
int upperbound;
int lowerbound;
class counter {
int count;
public:
counter(int n) {
if(n <= upperbound) count = n;
else count = upperbound;
}
void reset(int n) {
if(n <= upperbound) count = n;
}
int run() {
if(count > lowerbound) return count--;
else return lowerbound;
}
};
}
int main() {
CounterNameSpace::upperbound = 100;
CounterNameSpace::lowerbound = 0;
CounterNameSpace::counter ob1(10);
int i;
do {
i = ob1.run();
cout << i << " ";
} while(i > CounterNameSpace::lowerbound);
CounterNameSpace::counter ob2(20);
do {
i = ob2.run();
cout << i << " ";
} while(i > CounterNameSpace::lowerbound);
ob2.reset(100);
CounterNameSpace::lowerbound = 90;
do {
i = ob2.run();
cout << i << " ";
} while(i > CounterNameSpace::lowerbound);
return 0; }
```
- Observe the declaration of a counter object and the references to upperbound and lowerbound are qualified by CounterNameSpace.
- However, once an object of type counter has been declared, it is not necessary to further qualify it or any of its members. Thus, ob1.run( ) can be called directly; the namespace has already been resolved.

## using statement
- Specifying the namespace and the scope resolution operator each time you need to refer to one quickly becomes a tedious chore. The using statement helps in solving it.
- Syntax: Two forms
```cpp
using namespace name; //all members within the namespace are made visible
using name::member; //a specific member of the namespace is made visible
```
- E.g.
```cpp
using CounterNameSpace::lowerbound; // only lowerbound is visible
lowerbound = 10; // No qualification needed as lowerbound is visible now
using namespace CounterNameSpace; // all members are visible
upperbound = 100; // OK because all members are now visible
```
## Unnamed or Anonymous Namespaces
- Aim: To create identifiers that are unique within a file.
- This means unnamed namespaces allow you to establish unique identifiers that are known only within the scope of a single file. This implies members can be referred directly without any qualification within the file.
- Unnamed namespaces eliminate the need for certain uses of the static storage class modifier. E.g. linking both files, any attempt to use k in File Two will result in an error as there is no definition of k in File Two.

```
File 1
static int k;
void f1(){
k = 99;//ok
}
```
```
File 2
extern int k;
void f2(){
k=10;//error
}
```
-  A better way of writing code is to use unnamed namespace rather than static. E.g.
```
File 1
namespcace{
int k;
void f1(){
k = 99;//ok
}
```
```
File 2
extern int k;
void f2(){
k = 10;//error
}
```

## Some Namespace Options
- There may be more than one namespace declaration of the same name. This allows a namespace to be split over several files or even separated within the same file

```cpp
#include <iostream>
using namespace std;
namespace NS {
int i;
}
// ...
namespace NS {
int j;
}
int main()
{
NS::i = NS::j = 10;
// refer to NS specifically
cout << NS::i * NS::j << "\n";
// use NS namespace
using namespace NS;
cout << i * j;
return 0;
}

```
### Output:
```
100
100

```

- A namespace must be declared outside of all other scopes. This means that you cannot declare namespaces that are localized to a function, for example. There is, however, one exception: a namespace can be nested within another.
```cpp
#include <iostream>
using namespace std;
namespace NS1 {
int i;
namespace NS2 { // a nested namespace
int j;
}
}
int main()
{
NS1::i = 19;
// NS2::j = 10; Error, NS2 is not in view
NS1::NS2::j = 10; // this is right
cout << NS1::i << " "<< NS1::NS2::j << "\n";
// use NS1
using namespace NS1;
/* Now that NS1 is in view, NS2 can be used to
refer to j. */
cout << i * NS2::j;
return 0;
}
```

### Output:
```
19 10
190
```

## The std Namespace
- Standard C++ defines its entire library in its namespace called `std`.<br />
`using namespace std;`
This brings the `std` namespace to be brought into the current namespace, which gives you direct access to the
entire C++ library without having to qualify each one with `std::`.
