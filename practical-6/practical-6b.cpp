#include <iostream>
#include <string>
using namespace std;

class Education {
private:
    string general;
    string professional;

public:
    Education() {
        general = "";
        professional = "";
    }

    Education(string g, string p) {
        general = g;
        professional = p;
    }

    void EnterEducation() {
        cout << "\n\t Enter the highest general qualification: ";
        cin.ignore();
        getline(cin, general);
        cout << "\t Enter the highest professional qualification: ";
        getline(cin, professional);
    }

    void DisplayEducation() {
        cout << "\n\t Highest General Qualification = " << general;
        cout << "\n\t Highest Professional Qualification = " << professional;
    }
};

class Staff {
private:
    int code;
    string name;

public:
    Staff() {
        code = 0;
        name = "";
    }

    Staff(int c, string n) {
        code = c;
        name = n;
    }

    void EnterData() {
        cout << "\n\t Enter the code: "; cin >> code;
        cout << "\t Enter the name: "; cin.ignore(); getline(cin, name);
    }

    void DisplayData() {
        cout << "\n\t Code = " << code;
        cout << "\n\t Name = " << name;
    }
};

class Teacher : public Staff, public Education {
private:
    string subject;
    string publication;

public:
    Teacher() : Staff(), Education() {
        subject = "";
        publication = "";
    }

    void EnterData() {
        Staff::EnterData();
        Education::EnterEducation();
        cout << "\n\t Enter the subject: "; cin.ignore(); getline(cin, subject);
        cout << "\t Enter the publication: "; getline(cin, publication);
    }

    void DisplayData() {
        Staff::DisplayData();
        Education::DisplayEducation();
        cout << "\n\t Subject = " << subject;
        cout << "\n\t Publication = " << publication;
    }
};

class Officer : public Staff, public Education {
private:
    string grade;

public:
    Officer() : Staff(), Education() {
        grade = "";
    }

    void EnterData() {
        Staff::EnterData();
        Education::EnterEducation();
        cout << "\n\t Enter the grade: "; cin.ignore(); getline(cin, grade);
    }

    void DisplayData() {
        Staff::DisplayData();
        Education::DisplayEducation();
        cout << "\n\t Grade = " << grade;
    }
};

int main() {
    Teacher a;
    cout << "\n Entering details of the teacher\n";
    a.EnterData();
    cout << "\n Displaying the details of the teacher\n";
    a.DisplayData();

    Officer c;
    cout << "\n\n Entering details of the officer\n";
    c.EnterData();
    cout << "\n Displaying the details of the officer\n";
    c.DisplayData();

    return 0;
}
