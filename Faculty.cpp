#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty()
{
  facultyID = 0;
  name = "null";
  level = "null";
  department = "null";
  numAdvisees = 0;
}
Faculty::Faculty(int id, string name, string level, string department)
{
  facultyID = id;
  name = name;
  level = level;
  department = department;
  numAdvisees = 0;
}
Faculty::~Faculty()
{
  cout << "Faculty deleted" << endl;
  for (int i=0; i < numAdvisees; ++i)
  {
    advisees.removeFront();
  }
}

ostream& operator<<(ostream& os, const Faculty& f)
{
    os << f.facultyID << "   " << f.name << "   " << f.level << "   " << f.department;
    return os;
}

/** Accessors and Mutators */
void Faculty::setID(int i)
{ facultyID = i; }
void Faculty::setName(string n)
{ name = n; }
void Faculty::setLevel(string l)
{ level = l; }
void Faculty::setDep(string d)
{ department = d; }
int Faculty::getID()
{ return facultyID; }
string Faculty::getName()
{ return name; }
string Faculty::getLevel()
{ return level; }
string Faculty::getDep()
{ return department; }

void Faculty::print()
{
  cout << facultyID << "   " << name << "   " << level << "   " << department << endl;
}

void Faculty::addAdvisee(int id)
{
  advisees.addFront(id);
  numAdvisees++;
}
bool Faculty::rmvAdvisee(int id)
{
  if (advisees.find(id) != nullptr)
  {
    advisees.remove(advisees.find(id));
    numAdvisees--;
    return true;
  } else {
    return false;
  }
}

TDLL<int> Faculty::getAdvisees() {
  return advisees;
}
/**The save method writes all member variables of an object out to the param fstream.*/
void Faculty::save(ofstream& file)
{
  file << facultyID << "\n";
  file << name << "\n";
  file << level << "\n";
  file << department << "\n";
  file << numAdvisees << "\n";
  for (int i=0; i < numAdvisees; ++i)
  {
    file << advisees.front() << "\n";
    advisees.removeFront();
  }
}

void Faculty::load(ifstream& file)
{
  file >> facultyID;
  file >> name;
  file >> level;
  file >> department;
  file >> numAdvisees;
  int number = 0;
  if (numAdvisees > 0)
  {
    for (int i=0; i < numAdvisees; ++i)
    {
      file >> number;
      advisees.addFront(number);
    }
  }
}
