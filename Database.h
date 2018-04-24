#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include <iostream>
#include <fstream>
using namespace std;
/** Holds two BSTs as tables to store student and faculty data and methods to access
  * and update information */
class Database {
public:
  Database(); //read in from file
  ~Database(); //serialize to final

  int generateID(bool isStudent); //true if student, false if faculty
  void save();
  void undo(); //change pointers
  void registerAction();

  void printStudents();
  void printFaculty();
  void findStudent(int id);
  void findFaculty(int id);
  void findAdvisor(int id); //id of student
  void findAdvisees(int id); //id of faculty, print all advisees

  void addStudent(Student s); //info input from menu class, generate id in implementation
  void deleteStudent(int id);
  void addFaculty(Faculty f); //same as add student
  void deleteFaculty(int id);

  void updateAdvisor(int student, int newAdvisor);
  void removeAdvisee(int student, int advisor);

private:
  ifstream studentIn;
  ofstream studentOut;
  ifstream facultyIn;
  ofstream facultyOut;
  BST<Student*> *studentTree;
  BST<Faculty*> *facultyTree;
  TDLL<BST<Student>*> studentTables; //stack of past tables somehow
  TDLL<BST<Faculty>*> facultyTables;
};
