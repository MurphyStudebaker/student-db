#include <string>
using namespace std;

class Student
{
public:
  Student();
  ~Student();

  void setID(int i);
  void setAdvisor(int i);
  void setName(string n);
  void setLevel(string l);
  void setGPA(double g);
  int getID();
  int getAdvisor();
  string getName();
  string getLevel();
  double getGPA();

  //override cout operator
private:
  int studentID;
  int advisorID;
  string name;
  string level;
  double gpa;
};
