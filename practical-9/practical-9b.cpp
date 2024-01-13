
#include <fstream> //for file streams
#include <iostream>
#include <string.h>
using namespace std;
class Data
{
public:
  string s;
  string phone;
  Data()
  {
    s = "Null";
    phone = "Null";
  }
  Data(string str, string a)
  {
    s = str;
    phone = a;
  }
};
void reading()  //read function
{
  fstream f;
  string n;
  string p;
  char d;
  cout << "Want to find record:(y/n)" << endl;     
  cin >> d;
  char D;

  while (d == 'y')
  {
    cout << "Want to find name or phone number:(n,p)" << endl;
    cin >> D;
    if (D == 'p')
    {
      f.close();
      f.open("phone.txt", ios::in);
      string t;
      cout << "Enter Name :\n";
      cin >> t;
      int flag = 0;
      while (f.good())
      {
        f >> n >> p;

        if (t == n)
        {
          flag = 1;
          cout << p << endl;
        }
      }
      if (flag == 0)
        cout << "Not found";
    }
    if (D == 'n')
    {
      f.close();
      f.open("phone.txt", ios::in);
      string t;
      cout << "Enter Phone number :\n";
      cin >> t;
      int flag = 0;
      while (f.good())
      {
        f >> n >> p;
        if (t == p)
        {
          flag = 1;
          cout << n << endl;
        }
      }
      if (flag == 0)
        cout << "Not found";
    }
    cout << "Want to find record:(y/n)" << endl;
    cin >> d;
  }
}
void update()
{
  fstream f;
  string n;
  string p;
  char d;
  cout << "Want to update phone number:(y/n)" << endl;
  cin >> d;
  char D;

  while (d == 'y')
  {
    f.close();
    f.open("phone.txt", ios::out | ios::in);
    string t;
    cout << "Enter Name :\n";
    cin >> t;
    int flag = 0;
    while (f.good())
    {
      f >> n;

      if (t == n)
      {
        flag = 1;
        string ex;

        cout << "Enter Updated Number (10 digits):\n";
        cin >> ex;
        f << "  ";
        f << ex;
      }
      f >> p;
    }
    if (flag == 0)
      cout << "Not found";

    cout << "Want to update Phone Number:(y/n)" << endl;
    cin >> d;
  }
}
int main()
{
  int s;
  cout << "Enter Size :\n";    
  cin >> s;
  string name;
  string phone;
  Data *dr[s];
  for (int i = 0; i < s; i++)
  {
    cout << "Enter Name :\n";
    cin >> name;
    cout << "Enter Phone number (10 digits):\n";
    cin >> phone;
    dr[i] = new Data(name, phone);
  }
  fstream f;
  f.open("phone.txt", ios::out | ios::trunc | ios::in);
  for (int i = 0; i < s; i++)
  {
    f << dr[i]->s << "    " << dr[i]->phone << "\n";     //input data in files
  }
  f.seekg(0);
  string str;
  while (f.good())        //1st part(reading whole file in given format)
  {
    getline(f, str);
    cout << str << endl;
  }

  f.close();
 
  update();                //2nd part
  reading();               //2nd part
}
