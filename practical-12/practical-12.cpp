#include <iostream>
#include <math.h>
using namespace std;
class polar;
class rectangle
{
    private:
    
    public:
    float x;
    float y;
    void scan()
    {
        cout<<"\nEnter the value of x and y: \n";
        cin>> x>>y;
    }
    void print()
    {
        cout<<"\ncoordinates are: \n"<<x<<"\n"<<y;
    }
    operator polar();
    
};
class polar
{
    public:
    float r;
    float theta;
    polar()
    {}
    void scan()
    {
        cout<<"\nEnter the value of r and theta: \n";
        cin>> r>>theta;
    }
    void print()
    {
        cout<<"\ncoordinates are: \n"<<r<<"\n"<<theta;
    }
    
    operator rectangle()
    {
        
        float x;
        float y;
        x = r * cos(theta);
        y = r * sin(theta);
        rectangle c;
        c.x = x;
        c.y = y;
        return c;
    }
};
rectangle :: operator polar()
{
        
        float r;
        float theta;
        r = sqrt((x*x)+(y*y));
        theta = atan(y/x);
        polar b;
        b.r = r;
        b.theta = theta;
        return b;
}
int main()
{
    rectangle a;
    a.scan();
    a.print();
    polar p = a;
    p.print() ;
    rectangle r = p;
    r.print();
    
}
