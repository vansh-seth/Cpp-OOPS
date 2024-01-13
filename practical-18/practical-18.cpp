#include <iostream>
#include <typeinfo>

using namespace std;

class Shape {
public:
    virtual void printType() const {
        cout << "This is a generic shape." << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void printType() const override {
        cout << "This is a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void printType() const override {
        cout << "This is a Rectangle." << endl;
    }
};

int main() {
    const int arraySize = 5;
    Shape* shapeArray[arraySize];

    Circle circle1;
    Rectangle rectangle1;
    Circle circle2;
    Rectangle rectangle2;
    Circle circle3;

    shapeArray[0] = &circle1;
    shapeArray[1] = &rectangle1;
    shapeArray[2] = &circle2;
    shapeArray[3] = &rectangle2;
    shapeArray[4] = &circle3;

    for (int i = 0; i < arraySize; ++i) {
        if (typeid(*shapeArray[i]) == typeid(Circle)) {
            cout << "Element at index " << i << " is a Circle." << endl;
            Circle* circlePtr = dynamic_cast<Circle*>(shapeArray[i]);
            if (circlePtr) {
                circlePtr->printType();
            }
        } else if (typeid(*shapeArray[i]) == typeid(Rectangle)) {
            cout << "Element at index " << i << " is a Rectangle." << endl;
            Rectangle* rectanglePtr = dynamic_cast<Rectangle*>(shapeArray[i]);
            if (rectanglePtr) {
                rectanglePtr->printType();
            }
        } else {
            cout << "Element at index " << i << " is of unknown type." << endl;
        }
    }

    return 0;
}
