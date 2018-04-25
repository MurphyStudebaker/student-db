#include "Database.h"
#include <iostream>
using namespace std;
/** Handles all user I/O for menu printing, user selection, and user input */
class DBMenu {
public:
  DBMenu();
  ~DBMenu();

  void init(); //holds loop for menu until quit
  void printMenu(); //prints main 14 options
  Student* studentInfo(); //prompts for adding a new student if selected
  Faculty* facultyInfo(); //prompts for adding new faculty if selected
private:
  Database *db;
};
