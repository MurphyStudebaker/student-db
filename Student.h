#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
  Student();
  Student(int id, string name, string level, double gpa, int advisorID);
  ~Student();
  friend ostream& operator<<(ostream& os, const Student& s);

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

  void save(ofstream& file);
  void load(ifstream& file);
  void print();

private:
  int studentID;
  int advisorID;
  string name;
  string level;
  double gpa;
};
