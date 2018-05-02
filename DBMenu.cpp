#include "DBMenu.h"
using namespace std;

DBMenu::DBMenu()
{
  db = new Database;
}
DBMenu::~DBMenu()
{
  delete db;
}

void DBMenu::init()
{
  int response = 0;
  while (true)
  {
    printMenu();
    cin >> response;
    if (response == 1) {
      db->printStudents();
    } else if (response == 2) {
        db->printFaculty();
    } else if (response == 3) {
        cout << "Enter the Student's ID:" << endl;
        int id = 0;
        cin >> id;
        db->findStudent(id);
    } else if (response == 4) {
        cout << "Enter the Faculty ID:" << endl;
        int id = 0;
        cin >> id;
        db->findFaculty(id);
    } else if (response == 5) {
        cout << "Enter the student's ID: " << endl;
        int id = 0;
        cin >> id;
        db->findAdvisor(id);
    } else if (response == 6) {
        cout << "Enter the Faculty ID:" << endl;
        int id = 0;
        cin >> id;
        db->findAdvisees(id);
    } else if (response == 7) {
        Student *newStudent = studentInfo();
        db->addStudent(newStudent);
    } else if (response == 8) {
        cout << "Enter the student's ID: " << endl;
        int id = 0;
        cin >> id;
        db->deleteStudent(id);
    } else if (response == 9) {
        Faculty *newFac = facultyInfo();
        db->addFaculty(newFac);
    } else if (response == 10) {
        cout << "Enter the Faculty ID:" << endl;
        int id = 0;
        cin >> id;
        db->deleteFaculty(id);
    } else if (response == 11) {
        cout << "Enter the student's ID: " << endl;
        int sid = 0;
        cin >> sid;
        cout << "Enter the Faculty ID:" << endl;
        int fid = 0;
        cin >> fid;
        db->updateAdvisor(sid, fid);
    } else if (response == 12) {
        cout << "Enter the Faculty ID:" << endl;
        int fid = 0;
        cin >> fid;
        cout << "Enter the student's ID: " << endl;
        int sid = 0;
        cin >> sid;
        db->removeAdvisee(sid, fid);
    }  else if (response == 13) {
        db->undo();
    } else if (response == 14) {
      break;
    } else {
      cout << "Error: Invalid Selection. Please choose again." << endl;
    }
  }
}
void DBMenu::printMenu()
{
  cout << "1. Print all students" << endl <<
          "2. Print all faculty" << endl <<
          "3. Look up student by ID" << endl <<
          "4. Look up faculty by ID" << endl <<
          "5. Look up a student's advisor" << endl <<
          "6. Look up a faculty member's advisees" << endl <<
          "7. Add a new student" << endl <<
          "8. Delete a student" << endl <<
          "9. Add a new faculty member" << endl <<
          "10. Delete a faculty member" << endl <<
          "11. Change a student’s advisor" << endl <<
          "12. Remove an advisee from a faculty member" << endl <<
          "13. Rollback" << endl <<
          "14. Exit" << endl;
}
Student* DBMenu::studentInfo()
{
  string name, level;
  double gpa;
  int advisor;
  cout << "Name: " << endl;
  cin >> name;
  cout << "Level: (Freshman, Sophomore, Junior, Senior)" << endl;
  cin >> level;
  cout << "GPA: " << endl;
  cin >> gpa;
  cout << "ID of faculty advisor (Enter 0 if advisor is unknown): " << endl;
  cin >> advisor;
  Student *newStudent = new Student(db->generateID(true), name, level, gpa, advisor);
  return newStudent;
}
Faculty* DBMenu::facultyInfo()
{
  string name, level, department;
  cout << "Name: " << endl;
  cin >> name;
  cout << "Level: (Adjunct, Full-Time)" << endl;
  cin >> level;
  cout << "Department Code: (CPSC, ENG, FP)" << endl;
  cin >> department;
  Faculty *newFac = new Faculty(db->generateID(false), name, level, department);
  return newFac;
}
