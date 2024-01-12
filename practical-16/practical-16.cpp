#include <iostream>
#include <string>
using namespace std;
bool Numeric(string str);
class Employee {
public:
    string name;
    int age;
    double salary;

    Employee() {
        name = "";
        age = 0;
        salary = 0.0;
    }
    void enterData() {
        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the age: ";
        cin >> age;
        cout << "Enter the salary: ";
        cin >> salary;
    }

    void displayData() {
        cout << "Employee Details:\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Salary: " << salary << "\n";
    }
};

int main() {
    Employee emp;
    try 
    {
        emp.enterData();
        emp.displayData();
        int a = Numeric(emp.name);
        if (a) 
        {
            throw "Invalid name";
        }
        if (emp.age < 18 || emp.age > 60) 
        {
            throw "Invalid age";
        }
    } 
    catch (const char* e) 
    {
        cout << "Error: " << e << endl; 
    }
    return 0;
}

bool Numeric(string str) {
    for (char c : str) {
        if (isdigit(c)) {
            return true;
        }
    }
    return false;
}
