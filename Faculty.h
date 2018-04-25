#include <string>
#include <fstream>
#include "TDLL.h"
using namespace std;

class Faculty {
public:
  Faculty();
  Faculty(int id, string name, string level, string department);
  ~Faculty();

  friend ostream& operator<<(ostream& os, const Faculty& s);

  void setID(int i);
  void setName(string n);
  void setLevel(string l);
  void setDep(string d);
  int getID();
  string getName();
  string getLevel();
  string getDep();

  void addAdvisee(int id);
  bool rmvAdvisee(int id); //returns true if student found and successfully removed
  TDLL<int> getAdvisees();

  void save(ofstream& file);
  void load(ifstream& file);
  void print();
private:
  int facultyID;
  string name;
  string level;
  string department;
  int numAdvisees;
  TDLL<int> advisees;
};
