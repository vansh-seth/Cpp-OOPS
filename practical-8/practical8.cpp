#include<iostream>
using namespace std;

class inches {
    int inch;
public:
    inches() : inch(0) {
        setValue();
    }
    inches(int i) : inch(i) {}
    void setValue() {
        cout << "Enter the value in inches: ";
        cin >> inch;
    }
    void getValue() {
        cout << inch;
    }
};

class feet {
    int ft;
public:
    feet() : ft(0) {
        setValue();
    }
    feet(int f) : ft(f) {}
    void setValue() {
        cout << "Enter the value in feet: ";
        cin >> ft;
    }
    void getValue() {
        cout << ft;
    }
};

class height {
    feet heightFeet;
    inches heightInches;
public:
    height(feet ft, inches inch) : heightFeet(ft), heightInches(inch) {}
    void display() {
        cout << "In Feet: ";
        heightFeet.getValue();
        cout << endl;
        cout << "In Inches: ";
        heightInches.getValue();
        cout << endl;
    }
};

class width {
    feet widthFeet;
    inches widthInches;
public:
    width(feet ft, inches inch) : widthFeet(ft), widthInches(inch) {}
    void display() {
        cout << "In Feet: ";
        widthFeet.getValue();
        cout << endl;
        cout << "In Inches: ";
        widthInches.getValue();
        cout << endl;
    }
};

class building {
    height buildingHeight;
    width buildingWidth;
public:
    building(height ht, width wt) : buildingHeight(ht), buildingWidth(wt) {}
    void display() {
        cout << "For building => " << endl; 
        cout << "Height: " << endl;
        buildingHeight.display();
        cout << "Width:" << endl;
        buildingWidth.display();
    }
};

int main() {
    cout<<"For Height: "<<endl;
    feet heightFeet;
    inches heightInches;
    cout<<"For Width: "<<endl;
    feet widthFeet;
    inches widthInches;
    height h(heightFeet, heightInches);
    width w(widthFeet, widthInches);
    building myBuilding(h, w);
    
    myBuilding.display();

    return 0;
}
