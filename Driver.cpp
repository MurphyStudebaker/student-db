#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;

int main ( )
{
  Faculty professor;
  ifstream input;
  input.open("facultyTable.txt");
  professor.load(input);
  cout << professor << endl;
  input.close();
}
