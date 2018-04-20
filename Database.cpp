/**#include "Database.h"
using namespace std;

Database::Database()
{
  studentTable.open("studentTable.txt", ios::out | ios::binary);
  if (!studentTable) {
    cout << "Could not locate studentTable.txt, creating an empty table." << endl;
  } else {
    //build tree
  }
}
Database::~Database()
{
  //save tree
}
*/
