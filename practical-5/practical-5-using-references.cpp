#include <iostream>
using namespace std;
class s {
private:
    int num;
    s()
    {
        num++;
    }
    ~s()
    {
        
    }
public:
    static s& getobj() {
        static s obj; 
        return obj;
    }

    void display() {
        cout << "num: " << num << endl;
    }
};

int main() {
    s& s1 = s::getobj();
    s& s2 = s::getobj();
    s1.display(); 
    s2.display();
    return 0;
}
