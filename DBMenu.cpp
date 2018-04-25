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
  while (true)
    int response = 0;
    printMenu();
    cin >> response;
    if (response == 1) {
      db.printStudents();
    } else if (response == 2) {
        db.printFaculty();
    } else if (response == 3) {
        cout << "Enter the Student's ID:" << endl;
        int id = 0;
        cin >> id;
        db.findStudent(id);
    } else if (response == 4) {
        cout << "Enter the Faculty ID:" << endl;
        int id = 0;
        cin >> id;
        db.findFaculty(id);
    } else if (response == 5) {
        cout << "Enter the student's ID: " << endl;
        int id = 0;
        cin >> id;
        db.findAdvisor(id);
    } else if (response == 6) {
        cout << "Enter the Faculty ID:" << endl;
        int id = 0;
        cin >> id;
        db.findAdvisees(id);
    } else if (response == 7) {
        Student *newStudent = studentInfo();
        db.addStudent(newStudent);
    } else if (response == 8) {
        cout << "Enter the student's ID: " << endl;
        int id = 0;
        cin >> id;
        db.deleteStudent(id);
    } else if (repsonse == 9) {
        Faculty *newFac = facultyInfo();
        db.addFaculty();
    } else if (response == 10) {
        cout << "Enter the Faculty ID:" << endl;
        int id = 0;
        cin >> id;
        db.deleteFaculty(id);
    } else if (response == 11) {
        cout << "Enter the student's ID: " << endl;
        int sid = 0;
        cin >> sid;
        cout << "Enter the Faculty ID:" << endl;
        int fid = 0;
        cin >> fid;
        db.updateAdvisor(sid, fid);
    } else if (response == 12) {
        cout << "Enter the Faculty ID:" << endl;
        int fid = 0;
        cin >> fid;
        cout << "Enter the student's ID: " << endl;
        int sid = 0;
        cin >> sid;
        db.removeAdvisee(sid, fid);
    } else if (response == 13) {
        db.undo();
    } else if (response == 14) {
      break;
    } else {
      cout << "Error: Invalid Selection. Please choose again." << endl;
    }
}
void DBMenu::printMenu()
{
  cout << "1. Print all students\n
            2. Print all faculty\n
            3. Look up student by ID\n
            4. Look up faculty by ID\n
            5. Look up a student's advisor\n
            6. Look up a faculty member's advisees\n
            7. Add a new student\n
            8. Delete a student\n
            9. Add a new faculty member\n
            10. Delete a faculty member\n
            11. Change a student’s advisor\n
            12. Remove an advisee from a faculty member\n
            13. Rollback\n
            14. Exit" << endl;
}
void DBMenu::studentInfo()
{
  string name, level;
  double gpa;
  int advisor;
  cout << "Name: " << endl;
  cin >> name;
  cout << "Level: (Freshman, Sophomore, Junior, Sebior)" << endl;
  cin >> level;
  cout << "GPA: " << endl;
  cin >> gpa;
  cout << "ID of faculty advisor: " << endl;
  cin >> advisor;
  Student *newStudent = new Student(db.generateID(true), name, level, gpa, advisor);
  return newStudent;
}
void DBMenu::facultyInfo()
{
  string name, level, department;
  cout << "Name: " << endl;
  cin >> name;
  cout << "Level: (Adjunct, Full-Time)" << endl;
  cin >> level;
  cout << "Department Code: (CPSC, ENG, FP)" << endl;
  cin >> department;
  Faculty *newFac = new Faculty(db.generateID(false), name, level, department);
  return newFac;
}
