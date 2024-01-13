#include <iostream>

using namespace std;
class Singleton{
    static Singleton *instance;
    int data;
    Singleton(){
        data=0;
    }
    public:
    static Singleton *getInstance(){
        if(!instance)
        instance=new Singleton;
        return instance;
    }
    int getdata(){
        return data;
    }
    void setdata(int d){
        data=d;
    }};
    Singleton *Singleton::instance=0;

int main()
{
    Singleton *s=s->getInstance();
    cout<<s->getdata()<<endl;
    cout<<&s<<endl;
    s->setdata(100);
    cout<<s->getdata()<<endl;
    cout<<&s<<endl;


    return 0;
}
