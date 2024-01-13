#include <iostream>

using namespace std;


class demo{

public :
    int data;
    static int count;



    demo(){
   cout<<"constructor is called"<<endl;
    count++;
    }

    ~demo(){

     cout<<"destructor is called"<<endl;

    }

            static int display(){
            return count;

            }




};

int demo:: count=0; //intitialising static variable

int main()
{
   demo d1;
   demo d2;
   demo d3; // 3 objects created

cout<<d1.count<<endl;
   cout<<d2.count<<endl;
   cout<<demo::display()<<endl;
    return 0;
}
