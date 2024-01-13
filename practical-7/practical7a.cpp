#include <iostream>
using namespace std;
class Staff //base class
{
protected:
  int code;
  string name;
public:
    Staff ()
  {
    code = 0;
    name = " null";
  }
  void getdata ()
  {
    cout << "Enter code:";
    cin >> code;
    cout << "Enter name:";
    cin >> name;
  }
  void setdata ()
  {
    cout << "code:" << code << endl << "name:" << name << endl;
  }
};
class Education{//part b:education base class for teacher and office
    protected :
    string hedu;
    string gedu;
    public:
    Education(){
        hedu="null";
        gedu="null";
    }
  };
class Teacher:public Staff,public Education{//inherited class
protected:
  string subject, publication;
public:
  Teacher ()
  {
    subject = "null ";
    publication = " null";
  }
  Teacher(string h,string g){
      subject = " ";
    publication = " ";
      hedu=h;
      gedu=g;
  }
  void getdata ()
  {
    Staff::getdata ();
    cout << "Enter subject:";
    cin >> subject;
    cout << "Enter Publication:";
    cin >> publication;
  }
  void setdata ()
  {
    Staff::setdata ();
    cout << "subject:" << subject << endl << "Publication:" << publication
      << endl<<"general education: "<<hedu<<endl<<"qualification: "<<gedu<<endl;
  }
};
class Officer:public Staff,public Education//inherited class
{
protected:
  string grade;
public:
  Officer ()
  {
    grade = " null";
  }
    Officer(string h,string g){
    grade = " null";
      hedu=h;
      gedu=g;
  }
  void getdata ()
  {
    Staff::getdata ();
    cout << "Enter grade:";
    cin >> grade;
  }
  void setdata ()
  {
    Staff::setdata ();
    cout << "Grade:" << grade << endl<<"general education:"<<hedu<<endl<<"qualification:"<<gedu<<endl;
  }
};

class Typist:public Staff//inherited class
{
protected:
  float speed;
public:
    Typist ()
  {
    speed = 0.0;
  }
  void getdata ()
  {
    Staff::getdata ();
    cout << "Enter speed:";
    cin >> speed;
  }
  void setdata ()
  {
    Staff::setdata ();
    cout << "Speed:" << speed << endl;
  }
};
class Regular:public Typist//inherited class
{
};
class Casual:public Typist//inherited class
{
protected:
  float daily_wages;
public:
    Casual ()
  {
    daily_wages = 0.0;
  }
  void getdata ()
  {
    Typist::getdata ();
    cout << "Enter daily wages:";
    cin >> daily_wages;
  }
  void setdata ()
  {
    Typist::setdata ();
    cout << "daily wages:" << daily_wages << endl;
  }
};


int
main ()
{
  Staff s;
  s.getdata ();
  s.setdata ();
  Teacher t;
  t.getdata ();
  t.setdata ();
  Teacher t1("Btech","Phd");
  t1.getdata();
  t1.setdata();
 
  Typist ty;
  ty.getdata ();
  ty.setdata ();
  Officer o;
  o.getdata ();
  o.setdata ();
  Officer o2("Phd","cyber");
  o2.getdata();
  o2.setdata();
  Regular r;
  r.getdata ();
  r.setdata ();
  Casual c;
  c.getdata ();
  c.setdata ();
  return 0;
}
