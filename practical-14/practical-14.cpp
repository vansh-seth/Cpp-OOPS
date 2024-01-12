#include <iostream>
#include <string>
using namespace std;
class Distance {
public:
    int kmeter;
    int meter;

    Distance(int km = 0, int m = 0) : kmeter(km), meter(m) {}

    static bool isSmaller(const Distance& a, const Distance& b) {
        if (a.kmeter != b.kmeter) {
            return a.kmeter < b.kmeter;
        } else {
            return a.meter < b.meter;
        }
    }
};

template <typename T, size_t N, typename Compare>
void bubbleSort(T (&arr)[N], Compare compare) {
    for (size_t i = 0; i < N - 1; ++i) {
        for (size_t j = 0; j < N - i - 1; ++j) {
            if (compare(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int intArray[5];
    string stringArray[5];
    float floatArray[5];
    Distance distanceArray[5];

    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; ++i) {
        cin >> intArray[i];
    }

    cout << "Enter 5 strings: ";
    for (int i = 0; i < 5; ++i) {
        cin >> stringArray[i];
    }

    cout << "Enter 5 floating-point numbers: ";
    for (int i = 0; i < 5; ++i) {
        cin >> floatArray[i];
    }

    cout << "Enter 5 distances (km meter): ";
    for (int i = 0; i < 5; ++i) {
        cin >> distanceArray[i].kmeter >> distanceArray[i].meter;
    }

    bubbleSort(intArray, less<int>());
    bubbleSort(stringArray, less<string>());
    bubbleSort(floatArray, less<float>());
    bubbleSort(distanceArray, Distance::isSmaller);

    cout << "Sorted intArray: ";
    for (int i = 0; i < 5; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    cout << "Sorted stringArray: ";
    for (int i = 0; i < 5; ++i) {
        cout << stringArray[i] << " ";
    }
    cout << endl;

    cout << "Sorted floatArray: ";
    for (int i = 0; i < 5; ++i) {
        cout << floatArray[i] << " ";
    }
    cout << endl;

    cout << "Sorted distanceArray: ";
    for (int i = 0; i < 5; ++i) {
        cout << distanceArray[i].kmeter << " km " << distanceArray[i].meter << " m, ";
    }
    cout << endl;

    return 0;
}
