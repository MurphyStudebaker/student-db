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
      cout << loadedFaculty << endl;
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
  facultyOut.open("facultyTable.txt");
  facultyTree->saveTree(facultyOut);
  facultyOut.close();
  studentOut.open("studentTable.txt");
  studentTree->saveTree(studentOut);
  studentOut.close();
  delete studentTree;
  delete facultyTree;
}
/*
int generateID(bool isStudent)
{
  int theID = 0;
  if (isStudent)
  {
    while (true)
    {
      //generate ID between 10000 and 50000
      if (!studentTree.contains(theID)) //no other student has this ID
        break;
    }
  }
  else {
    //generate ID between 50000 and 100000
    //check tree to make sure it is unique
  }
  return theID;
}
*/
void Database::printStudents()
{
  studentTree->printTree();
}
void Database::printFaculty()
{
  facultyTree->printTree();
}
