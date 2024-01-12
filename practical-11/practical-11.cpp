#include <iostream>

using namespace std;

class Distance {
private:
    float kmeter;
    float meter;

public:
    Distance(float miles) {
        kmeter = miles * 1.60934;
        meter = kmeter * 1000;
    }
    operator float(){
        float miles = kmeter / 1.60934;
        return miles;
    }

    void display() {
        cout << "Distance: " << kmeter << " kilometers and " << meter << " meters." << endl;
    }
};

int main() {
    Distance distance1(10.0);
    distance1.display();
    float miles=distance1;
    cout << "Distance in miles: " << miles << " miles." << endl;
    return 0;
}
