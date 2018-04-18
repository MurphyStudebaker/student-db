#include <string>
#include "TDLL.h"
using namespace std;

class Faculty {
public:
  Faculty();
  ~Faculty();

  void setID(int i);
  void setName(string n);
  void setLevel(string l);
  void setDep(string d);
  int getID();
  string getName();
  string getLevel();
  string getDep();

  void addAdvisee(int id);
  void rmvAdvisee(int id);

  //override cout operator
private:
  int facultyID;
  string name;
  string level;
  string department;
  TDLL<int> studentIDs;
};
