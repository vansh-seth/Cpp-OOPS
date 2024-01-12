#include <iostream>
using namespace std;
class Father {
private:
    int age;

public:
    Father(int father_age) {
        if (father_age < 0) {
            throw -1;
        }
        age = father_age;
    }

    int getAge() const {
        return age;
    }
};

class Son : public Father {
private:
    int son_age;

public:
    Son(int father_age, int son_age) : Father(father_age), son_age(son_age) {
        if (son_age >= getAge()) {
            throw -2; 
        }
    }

    int getson_age() const {
        return son_age;
    }
};

int main() {
    try {
        Father father(-5); 
    } catch (int errorCode) {
        if (errorCode == -1) {
            cerr << "Invalid age, Age cannot be less than 0." << endl;
        }
    }

    try {
        Son son(40, 45); 
    } catch (int errorCode) {
        if (errorCode == -2) {
            cerr << "Son's age cannot be greater than or equal to Father's age." << endl;
        }
    }

    return 0;
}
