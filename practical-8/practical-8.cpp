#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class dict
{
public:
    string name;
    int ph;
    void input()
    {


            cout<< "Enter the name: ";
            cin>> name;
            cout<<"Enter the phone number: ";
            cin>> ph;

    }
};
int main()
{
    int a;
    cout<< "Enter the of objects: ";
    cin>> a;
    dict d;


    fstream file;
    file.open("phone.txt",ios::out);
    if(!file)
    {
        cout<<"could not open file";
    }
    else
    {
        for(int i=0;i<a;i++)
        {
            d.input();
            file<<"\nname = "<<d.name<<"\nphone number = " <<d.ph;
        }
        file.close();
    }
    file.open("phone.txt",ios::in);
    if(!file)
    {
        cout<<"could not open file";
    }
    else
    {
        string ch;
        while(!file.eof())
        {
            file>>ch;
            cout<<ch<< " ";
        }
        file.close();
    }

}
