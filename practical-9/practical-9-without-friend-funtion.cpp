#include <iostream>
#include <stdexcept>
using namespace std;
class Queue {
private:
    static const int max = 100; 
    int elements[5];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1, rear = -1;
    }
    Queue operator+(int element) {
        if (isFull()) {
            cout<< "Queue is full" << endl;
        } else if (isEmpty()) {
            front = rear = 0;
            elements[rear] = element;
        } else {
            rear = (rear + 1) % max;
            elements[rear] = element;
        }
        return *this;
    }
    Queue operator-(int element) {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            element = elements[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % max;
            }
        }
        return *this;
    }

    bool isEmpty() const {
        return (front == -1 && rear == -1);
    }

    bool isFull() const {
        return ((rear + 1) % max == front);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << elements[i] << " ";
            i = (i + 1) % max;
        }
        cout << elements[i] << endl;
    }
};

int main() {
    Queue q;

    q = q + 1;
    q = q + 2;
    q = q + 3; 

    q.display(); 
    int removed;
    q = q - removed; 
    cout << "Removed Element: " << removed << endl;

    q.display(); 

    return 0;
}
