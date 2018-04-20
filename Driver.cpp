#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;

int main ( )
{
//  Student aStudent(1878547);
  ifstream input;
/*  ofstream output;
  aStudent.setName("Judie");
  aStudent.setLevel("Senior");
  aStudent.setGPA(3.8);
  aStudent.setAdvisor(713687);
  output.open("studentTable.txt");
  aStudent.save(output); */
  input.open("studentTable.txt");
  Student loadedStudent;
  loadedStudent.load(input);
  cout << loadedStudent << endl;
  input.close();
//  output.close();
}
