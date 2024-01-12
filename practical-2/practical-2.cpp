#include <iostream>
#include <cstring>

class String {
private:
    char *data;

public:
    String() {
        data = nullptr;
        std::cout << "Default constructor is invoked." << std::endl;
    }

    String(const char *str) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
        }
        std::cout << "Parameterized constructor is invoked." << std::endl;
    }

    ~String() {
        if (data) {
            delete[] data;
            std::cout << "Destructor is invoked." << std::endl;
        }
    }

    void concatenate(const String &s1, const String &s2) {
        if (s1.data && s2.data) {
            data = new char[strlen(s1.data) + strlen(s2.data) + 1];
            strcpy(data, s1.data);
            strcat(data, s2.data);
        } else {
            data = nullptr;
        }
    }

    void display() {
        if (data) {
            std::cout << "String: " << data << std::endl;
        } else {
            std::cout << "String is empty." << std::endl;
        }
    }
};

int main() {
    String s1;  // Default constructor
    String s2("Well done");  // Parameterized constructor

    String s3;
    s3.concatenate(s2, s2);  // Concatenate s2 with s2
    s3.display();

    s1 = s2;  // Copy s2 to s1
    s1.display();

    return 0;
}
