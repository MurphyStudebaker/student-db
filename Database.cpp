#include "Database.h"
using namespace std;
/** Creates new instances of the data tables and loads in the information from file.*/
Database::Database()
{
  studentTree = new BST<Student*>;
  facultyTree = new BST<Faculty*>;
  load();
}
/** Saves both data tables to a file before deleting the pointers. */
Database::~Database()
{
  save();
  delete studentTree;
  delete facultyTree;
}

/** Reads in information for the student and faculty data tables from two text files.
  * If using your own text files, they must be located within this directory and
  * named studentTable.txt and facultyTable.txt */
void Database::load()
{
  studentIn.open("studentTable.txt");
  if (!studentIn) {
    cout << "Could not locate studentTable.txt, creating an empty table." << endl;
  } else {
    while (!studentIn.eof()) //not end of file
    {
      Student *loadedStudent = new Student;
      loadedStudent->load(studentIn);
      studentTree->insert(loadedStudent->getID(), loadedStudent);
    }
  }
  studentIn.close();
  facultyIn.open("facultyTable.txt");
  if (!facultyIn) {
    cout << "Could not locate facultyTable.txt, creating an empty table" << endl;
  } else {
    while (!facultyIn.eof()) //not end of file
    {
      Faculty *loadedFaculty = new Faculty;
      loadedFaculty->load(facultyIn);
      if (loadedFaculty->getID() != 0) //prevent
      {
        facultyTree->insert(loadedFaculty->getID(), loadedFaculty);
      }
    }
  }
  facultyIn.close();
}
/** Writes the content of each data table to file. */
void Database::save()
{
  studentOut.open("studentTable.txt");
  studentTree->saveTree(studentOut);
  studentOut.close();
  facultyOut.open("facultyTable.txt");
  facultyTree->saveTree(facultyOut);
  facultyOut.close();
}

/* This method must be called after each manipulation operation to enable
 * the undo method. It saves the current tables to file and adds a copy of
 * both tables to the operation stack. */
void Database::recordOperation()
{
  save();
  Database *newDB = new Database;
  newDB->load();
  operationStack.addFront(newDB);
}
/* Removes the most recent operation from the stack and resets both data tables
 * to their previous state. */
void Database::undo()
{
  operationStack.removeFront();
  studentTree = operationStack.front()->studentTree;
  facultyTree = operationStack.front()->facultyTree;
}
/** Generates a random ID for added students and faculty. If a student,
  * the ID is generated between 10000 and 50000. If a faculty member,
  * the ID is generated between 50001 and 100000. */
int Database::generateID(bool isStudent)
{
  int theID = 0;
  if (isStudent)
  {
    while (true)
    {
      //generate ID between 10000 and 50000
      theID = 10000 + (rand() % int(50000 - 10000+1));
      if (!studentTree->contains(theID)) //no other student has this ID
        break;
    }
  } else {
    while (true)
    {
      theID = 50001 + (rand() % int(100000 - 50000+1));
      if (!facultyTree->contains(theID)) //no other faculty has this ID
        break;
    }
  }
  return theID;
}

/** These are simple look up methods that print the information of either all
  * or specific students and faculty given their ID. */
void Database::printStudents()
{
  studentTree->printTree();
}
void Database::printFaculty()
{
  facultyTree->printTree();
}
void Database::findStudent(int id)
{
  studentTree->fetch(id)->print();
}
void Database::findFaculty(int id)
{
  facultyTree->fetch(id)->print();
}
void Database::findAdvisor(int id)
{
  int advisorID = studentTree->fetch(id)->getAdvisor();
  facultyTree->fetch(advisorID)->print();
}
void Database::findAdvisees(int id)
{
  TDLL<int> adv = facultyTree->fetch(id)->getAdvisees();
  while (!adv.isEmpty())
  {
    studentTree->fetch(adv.front())->print();
    adv.removeFront();
  }
}

/** Add and delete functions for students and faculty. If a new student
  * or faculty member is added, an ID is generated for them. */
void Database::addStudent(Student *s)
{
  int key = generateID(true);
  s->setID(key);
  studentTree->insert(key, s);
  recordOperation();
}
void Database::deleteStudent(int id)
{
  if (studentTree->contains(id))
  {
    studentTree->deleteNode(id);
    recordOperation();
  }
  else
    cout << "Error: No student with that ID exists in database." << endl;
}
void Database::addFaculty(Faculty *f)
{
  int key = generateID(false);
  f->setID(key);
  facultyTree->insert(key, f);
  recordOperation();
}
void Database::deleteFaculty(int id)
{
  if (facultyTree->contains(id))
  {
    TDLL<int> advisees = facultyTree->fetch(id)->getAdvisees();
    int i = 0;
    while (!advisees.isEmpty()) //set advisees' advisor to the mins and maxs
    {
      int newAdvisor = 0;
      studentTree->fetch(advisees.front())->setAdvisor(newAdvisor);
      cout << "Student " << studentTree->fetch(advisees.front())->getID() << " no longer has an advisor. Please assign them a new one." << endl;
      advisees.removeFront();
    }
    facultyTree->deleteNode(id);
    recordOperation();
  }
  else
    cout << "Error: No faculty with that ID exists in database." << endl;
}

/** Updates the advisor of the given student to the given faculty member. */
void Database::updateAdvisor(int student, int newAdvisor)
{
  if (facultyTree->contains(newAdvisor))
  {
    studentTree->fetch(student)->setAdvisor(newAdvisor);
    recordOperation();
  } else {
    cout << "Error: That faculty ID is not in the database. " << endl;
  }
}

/**Removes a given student from the given faculty member's list of advisees.*/
void Database::removeAdvisee(int student, int advisor)
{
  if (studentTree->contains(student))
  {
    if (facultyTree->contains(advisor))
    {
      facultyTree->fetch(advisor)->rmvAdvisee(student);
      recordOperation();
    } else {
      cout << "Error faculty member does not exist in database." << endl;
    }
  } else {
    cout << "Error: Student does not exist in database. " << endl;
  }
}
