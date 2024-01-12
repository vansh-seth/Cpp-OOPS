#include <iostream>
using namespace std;
class complex
{
    private:
    double real;
    double img;
    public:
    complex()
    {
        real=0;
        img=0;
    }
    complex(int a,int b)
    {
        real = a;
        img=b;
    }
    complex operator -()
    {
        real = -real;
        img= -img;
    }
    complex operator ++()
    {
        return complex(++real,++img);
    }
    complex operator ++(int)
    {
        return complex(real++,img++);
    }
    complex operator --()
    {
        return complex(--real,--img);
    }
    complex operator --(int)
    {
        return complex(real--,img--);
    }
    void display()
    {
        if (img>0)
        {
            cout<<real<<"+"<<img<<"i"<<endl;
        }
        else
        {
            cout<<real<<img<<"i"<<endl;
        }
    }
};
int main()
{
    complex c(5,7),d;
    c.display();
    -c;
    c.display();
    -c;
    c.display();
    d=c++;
    d.display();
    d=++c;
    d.display();
}
