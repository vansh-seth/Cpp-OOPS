#include <iostream>
using namespace std;
class Distance2;
class Distance1 {
private:
    double miles;
public:
    Distance1(double m) : miles(m) {}
    friend class Distance2; 
    void display() {
        cout << "Distance in miles: " << miles << " miles" << endl;
    }
};
class Distance2 {
private:
    int km;
    double meters;
public:
    Distance2(int k, double m) : km(k), meters(m) {}
    friend class Distance1; 
    void display() {
        cout << "Distance in kmeters & meters: " << km << " km " << meters << " meters" << endl;
    }
    Distance2 addDistance(const Distance1 &d1) {
        double totalMeters = km * 1000 + meters + d1.miles * 1609.34;
        int newKm = (totalMeters / 1000);
        double newMeters = totalMeters - newKm * 1000;
        return Distance2(newKm, newMeters);
    }
};

int main() {
    float a;
    int c,b;
    cout << "Enter the distance in miles: ";
    cin >> a;
    cout << "Enter the distance in km: "; 
    cin >> b; 
    cout << "Enter the distance in meter: ";
    cin >> c;
    Distance1 d1(a); 
    Distance2 d2(b, c); 

    cout << "Original distances:" << endl;
    d1.display();
    d2.display();

    Distance2 result = d2.addDistance(d1);

    cout << "\nSum of distances:" << endl;
    result.display();

    return 0;
}
