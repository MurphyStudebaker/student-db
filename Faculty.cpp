#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty()
{
  facultyID = 0;
  name = "";
  level = "";
  department = "";
}
Faculty::~Faculty()
{
  cout << "Faculty deleted" << endl;
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

void Faculty::addAdvisee(int id)
{
  advisees.addFront(id);
}
bool Faculty::rmvAdvisee(int id)
{
  if (advisees.find(id) != nullptr)
  {
    advisees.remove(advisees.find(id));
    return true;
  } else {
    return false;
  }
}

void Faculty::printAdvisees() {
  advisees.printList();
}
/**The save method writes all member variables of an object out to the param fstream.
void Faculty::save(ofstream& file)
{
  file << facultyID << "\n";
  file << name << "\n";
  file << level << "\n";
  file << department << "\n";
  file << numAdvisees << "\n";
  file <<
}

void Faculty::load(ifstream& file)
{

}*/
