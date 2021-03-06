#include "Student.h"
using namespace std;

Student::Student()
{
  studentID = 0;
  advisorID = 0;
  gpa = 0.0;
  name = "null";
  level = "null";
}
Student::Student(int id, string n, string l, double g, int advID)
{
  studentID = id;
  advisorID = advID;
  gpa = g;
  name = n;
  level = l;
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

void Student::print()
{
  cout << studentID << "   " << name << "   " << level << "   " << gpa << "   " << advisorID << endl;
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
/** Loads in member variables from the given input stream. */
void Student::load(ifstream& file)
{
  file >> studentID;
  file >> name;
  file >> level;
  file >> gpa;
  file >> advisorID;
}
/** Writes out member variables to the given output stream. */
void Student::save(ofstream& file)
{
  if (studentID != 0)
  {
    file << studentID << "\n";
    file << name << "\n";
    file << level << "\n";
    file << gpa << "\n";
    file << advisorID << "\n";
  }
}
