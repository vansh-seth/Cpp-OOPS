#include <iostream>
using namespace std;
class user
{
    string name;
    float accno;
    string type;
    float bal;

public:
    void data() 
    {
        cout << "Enter name :\n";
        cin >> name;
        cout << "Enter Account number :\n";
        cin >> accno;
        cout << "Enter Account type :\n";
        cin >> type;
        cout << "Enter Balance :\n";
        cin >> bal;
    }
    void deposit() 
    {
        cout << "Enter Amount to be deposited in account number " << accno << ":\n";
        float am;
        cin >> am;
        bal += am;
        cout << "Balance : " << bal << "\n";
    }
    void withdraw() 
    {
        cout << "Current Balance : " << bal << "\n";
        cout << "Enter Amount to withdraw from account number " << accno << ":\n";
        float am;
        cin >> am;
        bal -= am;
        cout << "Balance : " << bal << "\n";
    }
    void dispdata() 
    {
        cout << "Name : " << name << "\n"
             << "Balance : " << bal << "\n\n";
    }
};

int main()
{
    cout << "DataBase :\n"; 
    user data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i].data();
        cout<< "Enter new \n";
    }

    string tell;
    cout << "Enter yes or no :\n";
    cin >> tell;
    while (tell == "yes")
    {
        cout << "Enter user Number :\n";
        int num;
        cin >> num;
        cout << "Enter Operation you want to perform\n";
        cout<< "1. deposit\n";
        cout<< "2. withdraw\n";
        cout<< "3. display\n";
        int op;
        cin >> op;
        switch (op)
        {

        case 1:
            data[num].deposit(); 
            break;
        case 2:
            data[num].withdraw(); 
            break;
        case 3:
            data[num].dispdata(); 
            break;
        default:
            cout<<"invalid choice";
        }
        cout << "Want to continue enter yes :\n";
        cin >> tell;
    }
}