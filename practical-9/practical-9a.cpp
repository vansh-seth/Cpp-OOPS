#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_ENTRIES = 100;

class Directory {
public:
    string name;
    int phoneNumber;

    void display() {
        cout << name << " " << phoneNumber << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of entries: ";
    cin >> n;

    if (n > MAX_ENTRIES) {
        cout << "Number of entries exceeds the maximum limit." << endl;
        return 1;
    }

    Directory entries[MAX_ENTRIES];

    fstream file("phone.txt", ios::out);
    if (!file) {
        cout << "Could not open file for writing." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << "Enter the name: ";
            cin >> entries[i].name;
            cout << "Enter the phone number: ";
            cin >> entries[i].phoneNumber;
            file << entries[i].name << " " << entries[i].phoneNumber << endl;
        }
        file.close();
    }

    file.open("phone.txt", ios::in);
    if (!file) {
        cout << "Could not open file for reading." << endl;
    } else {
        string name;
        int phoneNumber;

        while (file >> name >> phoneNumber) {
            cout << name << " " << phoneNumber << endl;
        }
        file.close();
    }

    return 0;
}
