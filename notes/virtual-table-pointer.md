# Virtual Table and Virtual Pointer in C++

### Virtual Table (vtable)

- The **virtual table** (vtable, virtual function table, dispatch table) is a lookup table of functions used to resolve function calls in a dynamic/late binding manner.
  
- Every class that uses virtual functions has its own vtable.
  
- **vtable Characteristics:**
  - A static array created by the compiler at compile time.
  - Contains one entry for each virtual function.
  - Each entry is a function pointer pointing to the most-derived function accessible by that class.

### Virtual Pointer

- The compiler adds a hidden pointer to the base class, often denoted as `__vPtr`.
  
- **__vPtr Properties:**
  - Automatically set when a class instance is created.
  - Points to the vtable for that class and initialized within the constructor.
  - Inherited by derived classes.
  - Increases the size of the class object by the size of a pointer.

**Example:**
```cpp
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base class display function\n";
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class display function\n";
    }
};

int main() {
    Base* obj = new Derived();
    obj->display(); // Calls the overridden display function in the Derived class
    delete obj;

    return 0;
}
```

In this example, the vtable is used to dynamically bind the correct function during runtime, showcasing the essence of virtual tables and pointers in C++.

![image](https://github.com/vansh-seth/Cpp-OOPS/assets/111755254/7bc2fdb9-0c0f-45dd-a41f-2bf02669308e)

## Object Slicing
- Assigning an object of a derived class to an instance of a base class results in loss of data
members of derived class, i.e., extra members of derived class are sliced off | object slicing

```cpp
class CB {
int a;
};
class CD : public CB {
int b;
}
int main () {
CD objD;
CB objB = objD;
}
```
- Object slicing can be prevented by making base class function pure virtual thereby disallowing
object creation.
