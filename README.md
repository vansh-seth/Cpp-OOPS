## Before code implementation please refer to my notes
# C++ Programming Experiments Repository

This repository contains C++ programs for various experiments related to object-oriented programming, classes, inheritance, templates, file handling, operator overloading, exception handling, and more.

## Experiment 1: Complex Numbers Operations

Create a class called Complex in C++ for performing arithmetic with complex numbers. Use double variables to represent the private data of the class. Provide public member functions for:
- Enter the values of real and imaginary part.
- Addition of two Complex numbers.
- Subtraction of two Complex numbers.
- Printing Complex numbers in the form: `a + bi`

## Experiment 2: Bank Account Management

Define a class in C++ to represent a bank account with data members:
- Name of the depositor
- Account number
- Type of account
- Balance amount in the account

Member functions include:
- To assign initial values
- To deposit an amount
- To withdraw an amount after checking the balance
- To display name and balance

Write a main function to create a database of 10 customers.

## Experiment 3: String Class with Constructors and Destructors

Define a class `String` as a user-defined string type in C++. Include constructors for creating an uninitialized string and initializing with a string constant. Include a destructor. Also, add a function to concatenate two strings. Test the class with different tasks.

## Experiment 4: Friend Function

Define classes `Distance1` and `Distance2` in C++. `Distance1` stores distance in miles, and `Distance2` in kilometers & meters. Write a program to add one object of `Distance1` with the object of `Distance2` using a friend function.

## Experiment 5: Static Members

Implement a singleton class in C++ using static members.

## Experiment 6: Inheritance (Books and Tapes)

Create a class `Publication` in C++ that stores title (string) and price (float) of a publication. Derive two classes: `Book` (adds page count) and `Tape` (adds playing time in minutes). Implement `getdata()` and `putdata()` functions. Test with instances and user input.

## Experiment 7: Enhanced Inheritance (with Educational Information)

a) Implement a class hierarchy using C++.
b) Enhance the hierarchy by adding educational information (`Education` class) to `Teacher` and `Officer`. Modify constructors.

## Experiment 8: Aggregation (Feet, Inches, Height, Width, Building)

Implement the class diagram using C++. Define member functions to convert `Feet` class object into `Inches` class object and vice versa. Objects should construct using constructors of `Height` and `Width`, which in turn call the `Building` constructor.

## Experiment 9: File Handling (Directory Class)

a) Define a class `Directory` with members: name and phone number. Store each set of data into a text file `phone.txt`.
b) Write a menu-driven program to:
   - Determine the telephone number of a specified person.
   - Determine the name if a telephone number is known.
   - Update the telephone number.

## Experiment 10: Operator Overloading (Queue)

Define a class `Queue` in C++ containing elements of type integer. Overload operators `+` to insert an element and `--` to remove an element.

## Experiment 11: Operator Overloading (Array Manipulation)

Implement array manipulation using operator overloading (`==` for comparison and `=` for copying). Compare friend function approach and without friends.

## Experiment 12: Conversion Functions

Define a class `Distance` in C++ with data members `kmeter` and `meter`. Implement conversion functions to convert `Distance` object into distance in miles (float type) and vice versa.

## Experiment 13: Conversion Functions (Polar and Rectangle)

Define classes `Polar` and `Rectangle` in C++ to represent points. Use conversion routines to convert between these classes.

## Experiment 14: Function Template

Define a function template in C++ to sort an array of elements of int, string, float, and user-defined type `Distance`.

## Experiment 15: Class Template (Linked List)

Define a template class `LinkedList` in C++ with functions to create, display, insert, and delete elements. Test with integer, float, and complex numbers.

## Experiment 16: Exception Handling (Employee Class)

Define a class `Employee` in C++ with members `name`, `age`, and `salary`. Implement methods to enter and display employee details. Use user-defined exceptions for invalid name and age.

## Experiment 17: Exception Handling (Inheritance Tree)

Demonstrate handling exceptions in an inheritance tree. Create a base class `Father` and a derived class `Son`. Implement a constructor in `Father` to handle the age exception and use it in the `Son` class.

## Experiment 18: Dynamic Binding and RTTI (Shape Hierarchy)

Define a base class `Shape` and derived classes `Circle` and `Rectangle`. Use an array of pointers to the `Shape` class and identify types at runtime using `typeid()` and `dynamic_cast`.

## Experiment 19: Smart Pointers

Write a C++ program that:
- Has a base class called `Query` that contains a list of strings.
- Has a Derived class called `PhrasedQuery` that adds a list of phrases.
- Uses a Boost shared_ptr to create a list of Queries.
- Populates the list with a mixture of Query and PhrasedQuery objects.
- Prints all of the queries in the list.

Feel free to explore each experiment's folder for detailed code and explanations. Contributions and improvements are welcome! 🚀
