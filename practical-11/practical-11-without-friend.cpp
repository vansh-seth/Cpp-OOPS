#include <iostream>
using namespace std;
const int MAX = 100;

class Array {
private:
    int size;
    int elements[MAX];

public:
    Array(int arr[], int n) {
        size = n;
        for (int i = 0; i < n; ++i)
        {
            elements[i] = arr[i];
        }
    }

    bool operator==(Array other) const {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; ++i) {
            if (elements[i] != other.elements[i])
                return false;
        }
        return true;
    }

    void operator=(Array other) {
        size = other.size;
        for (int i = 0; i < other.size; ++i)
            elements[i] = other.elements[i];
    }
};

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};

    Array a1(arr1, 3);
    Array a2(arr2, 3);

    if (a1 == a2) {
        cout << "Arrays are equal." << endl;
    } else {
        cout << "Arrays are not equal." << endl;
    }

    int arr3[] = {4, 5, 6};
    Array a3(arr3, 3);
    a3 = a1;

    return 0;
}
