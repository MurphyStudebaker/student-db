#include "Database.h"
using namespace std;
/** The Database constructor searches for input faculty and student files within the
  * directory. If found, the constructor loads in these files to set up the database.
  * If the files do not exist or cannot be read, the Databse initializes blank tables. */
Database::Database()
{
  studentTree = new BST<Student*>;
  facultyTree = new BST<Faculty*>;

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

Database::~Database()
{
//  if (!facultyTree->isEmpty())
//  {
    facultyOut.open("facultyTable.txt");
    facultyTree->saveTree(facultyOut);
    facultyOut.close();
//  }
//  if (!studentTree->isEmpty())
//  {
    studentOut.open("studentTable.txt");
    studentTree->saveTree(studentOut);
    studentOut.close();
//  }
  delete studentTree;
  delete facultyTree;
}

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
      theID = 50000 + (rand() % int(100000 - 50000+1));
      if (!facultyTree->contains(theID)) //no other faculty has this ID
        break;
    }
  }
  return theID;
}

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
  cout << studentTree->fetch(id) << endl;
}
void Database::findFaculty(int id)
{
  cout << facultyTree->fetch(id) << endl;
}
void Database::findAdvisor(int id)
{
  int advisorID = studentTree->fetch(id)->getAdvisor();
 cout << facultyTree->fetch(advisorID) << endl;
}
void Database::findAdvisees(int id)
{
  TDLL<int> adv = facultyTree->fetch(id)->getAdvisees();
  while (!adv.isEmpty())
  {
    cout << studentTree->fetch(adv.front()) << endl;
    adv.removeFront();
  }
}

void Database::addStudent(Student *s)
{
  int key = generateID(true);
  s->setID(key);
  studentTree->insert(key, s);
}
void Database::deleteStudent(int id)
{
  if (studentTree->contains(id))
  {
    studentTree->deleteNode(id);
  }
  else
    cout << "Error: No student with that ID exists in database." << endl;
}
void Database::addFaculty(Faculty *f)
{
  int key = generateID(false);
  f->setID(key);
  facultyTree->insert(key, f);
}
void Database::deleteFaculty(int id)
{
  if (facultyTree->contains(id))
  {
    facultyTree->deleteNode(id);
  }
  else
    cout << "Error: No faculty with that ID exists in database." << endl;
}
