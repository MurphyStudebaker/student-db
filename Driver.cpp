#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;

int main ( )
{
  Faculty prof;
  prof.addAdvisee(7130124);
  prof.addAdvisee(6875667);
  prof.printAdvisees();
  prof.rmvAdvisee(6875667);
  cout << "-- Deleted --" << endl;
  prof.printAdvisees();
}
