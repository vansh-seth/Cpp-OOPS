#include <iostream>
using namespace std;
template <typename T, int max>
class list {
private:
    T elements[max];
    int size;

public:
    list() : size(0) {}

    void create(T value) {
        if (size < max) {
            elements[size++] = value;
        } else {
            cout << "List is full. Cannot add more elements." << endl;
        }
    }

    void disp() {
        for (int i = 0; i < size; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    void insert(T value) {
        if (size < max) {
            for (int i = size; i > 0; --i) {
                elements[i] = elements[i - 1];
            }
            elements[0] = value;
            ++size;
        } else {
            cout << "List is full. Cannot insert more elements." << endl;
        }
    }

    void del(T value) {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == value) {
                for (int j = i; j < size - 1; ++j) {
                    elements[j] = elements[j + 1];
                }
                --size;
                break;
            }
        }
    }
};

int main() {
    const int max = 5;

    list<int, max> intList;
    intList.create(6);
    intList.create(76);
    intList.create(34);
    intList.disp();
    intList.insert(56);
    intList.disp();
    intList.del(76);
    intList.disp();

    list<float, max> floatList;
    floatList.create(11.5);
    floatList.create(25.5);
    floatList.create(34.5);
    floatList.disp();
    floatList.insert(47.5);
    floatList.disp();
    floatList.del(25.5);
    floatList.disp();

    return 0;
}
