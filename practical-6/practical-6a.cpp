#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: $";
        cin >> price;
    }

    void putdata() const {
        cout << "Title: " << title << "\nPrice: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Page Count: " << pageCount << " pages" << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter book details:" << endl;
    book.getdata();
    cout << "\nBook details:" << endl;
    book.putdata();

    cout << "\nEnter tape details:" << endl;
    tape.getdata();
    cout << "\nTape details:" << endl;
    tape.putdata();

    return 0;
}
