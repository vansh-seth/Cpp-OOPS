#include <iostream>

using namespace std;

class Array {

	int** data;
	int s1;
	int s2;
public:
	Array(int arr[][2], int r, int c) {
    	s1 = r;
    	s2 = c;
    	data = new int*[s1];
    	for (int i = 0; i < s1; i++) {
         	data[i] = new int[s2];
        	for (int j = 0; j < s2; j++) {
         	data[i][j] = arr[i][j];
     	}
 	}
	}

	friend bool operator == (Array& arr, const Array& other);

	Array& operator = (const Array& other);
	/*A friend function is a non-member function of the class to which it has been defined as friend.
	Therefore it just uses the functionality (functions and data) of the class.
	So it does not consist the implementation for that class.
	That's why it cannot be used to overload the assignment operator.*/
 	void display() {
     	for (int i = 0; i < s1; i++) {
         	for (int j = 0; j < s2; j++) {
             	cout << data[i][j] << " ";
        	}
        	cout << endl;
     	}
 	}
};

bool operator == (Array& arr, const Array& other){
    	if (arr.s1 != other.s1 || arr.s2 != other.s2) {
        	return false;
    	}
    	for (int i = 0; i < arr.s1; i++) {
        	for (int j = 0; j < arr.s2; j++) {
            	if (arr.data[i][j] != other.data[i][j]) {
                	return false;
         	}
         	}
    	}
    	return true;
 	}

Array& Array :: operator = (const Array& other) {
	if (this != &other) {
    	for (int i = 0; i < s1; i++)
        	delete[] data[i];
     	delete[] data;
     	s1 = other.s1;
     	s2 = other.s2;
     	data = new int*[s1];
     	for (int i = 0; i < s1; i++) {
        	data[i] = new int[s2];
         	for (int j = 0; j < s2; j++)
             	data[i][j] = other.data[i][j];
    	}
	}
	return *this;
}

int main() {
 	int n1, n2;
	cout << "Enter size1 of array 1: ";
 	cin >> n1;
 	cout << "Enter size2 of array 1: ";
 	cin >> n2;

 	int arr1[n1][2];
 	int arr2[n1][2];

 	cout << "Enter the elements of arr1:\n";
 	for (int i = 0; i < n1; i++) {
    	for (int j = 0; j < n2; j++) {
         	cin >> arr1[i][j];
     	}
 	}

	cout << "Enter the elements of arr2:\n";
 	for (int i = 0; i < n1; i++) {
    	for (int j = 0; j < n2; j++) {
         	cin >> arr2[i][j];
     	}
 	}

 	Array a1(arr1, n1, n2);
 	Array a2(arr2, n1, n2);

 	if (a1 == a2) {
    	cout << "Array 1:\n";
    	a1.display();
     	cout << "Array 2:\n";
     	a2.display();
     	cout << "Array1 and Array2 are equal.\n";
 	} else {
    	cout << "Array 1:\n";
     	a1.display();
     	cout << "Array 2:\n";
     	a2.display();
     	cout << "Array1 and Array2 are not equal.\n";
 	}

	a1 = a2;
	cout << "Copied Array2 to Array1.\n";
	cout << "Array 1:\n";
	a1.display();
	cout << "Array 2:\n";
	a2.display();

 	return 0;
}
