#include <iostream>
using namespace std;
class complex{
    private :
    float real, img;
    public :
    complex(){
        real = 0;
        img = 0;
    }
    void inp();
    void add(complex c1, complex c2);
    void sub(complex c1, complex c2);
    void prod(complex c1, complex c2);
    void divi(complex c1, complex c2);
    void disp();
};
void complex :: inp(){
    cout << "enter real part : "; cin >> real;
    cout << "enter imaginary part : "; cin >> img;
}
void complex :: add(complex c1, complex c2){
    real = c1.real + c2.real;
    img = c1.img + c2.img;
}
void complex :: sub(complex c1, complex c2){
    real = c1.real - c2.real;
    img = c1.img - c2.img;
}
void complex :: prod(complex c1, complex c2){
    real = c1.real * c2.real - c1.img * c2.img;
    img = c1.real * c2.img + c2.real * c1.img;
}
void complex :: divi(complex c1, complex c2){
    real = (c1.real * c2.real + c1.img * c2.img)/(c2.real*c2.real + c2.img*c2.img);
    img = (c2.real * c1.img - c1.real * c2.img)/(c2.real*c2.real + c2.img*c2.img);
}
void complex :: disp(){
    cout << real << " + " << img << "i";
}
int main(){
    complex c1,c2,c3,c4,c5,c6;
    cout << "enter first complex number\n";
    c1.inp();
    cout << "enter second complex number\n";
    c2.inp();
    c3.add(c1,c2);
    c4.sub(c1,c2);
    c5.prod(c1,c2);
    c6.divi(c1,c2);
    cout << "\nAddition : "; c3.disp();
    cout << "\nSubtraction : "; c4.disp();
    cout << "\nMultiplication : "; c5.disp();
    cout << "\nDivision : "; c6.disp();
    return 0;
}
/* Output
enter first complex number
enter real part : 3
enter imaginary part : 5
enter second complex number
enter real part : 2
enter imaginary part : 7

Addition : 5 + 12i
Subtraction : 1 + -2i
Multiplication : -29 + 31i
Division : 0.773585 + -0.207547i
*/
