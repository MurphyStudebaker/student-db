#include "Student.h"
using namespace std;

Student::Student()
{
  studentID = 0;
  advisorID = 0;
  gpa = 0.0;
  name = "";
  level = "";
}
Student::Student(int id)
{
  studentID = id;
  advisorID = 0;
  gpa = 0.0;
  name = "";
  level = "";
}
Student::~Student()
{
  cout << "Student deleted" << endl;
}

/** Overload cout operator so BST function works correctly for printing students */
ostream& operator<<(ostream& os, const Student& s)
{
    os << s.studentID << "   " << s.name << "   " << s.level << "   " << s.gpa << "   " << s.advisorID;
    return os;
}

/** Accessors and Mutators */
void Student::setID(int i)
{ studentID = i; }
void Student::setAdvisor(int i)
{ advisorID = i; }
void Student::setName(string n)
{ name = n; }
void Student::setLevel(string l)
{ level = l; }
void Student::setGPA(double g)
{ gpa = g; }
int Student::getID()
{ return studentID; }
int Student::getAdvisor()
{ return advisorID; }
string Student::getName()
{ return name; }
string Student::getLevel()
{ return level; }
double Student::getGPA()
{ return gpa; }
