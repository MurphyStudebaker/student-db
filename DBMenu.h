#include "Database.h"
#include <iostream>
using namespace std;
/** Handles all user I/O for menu printing, user selection, and user input */
class DBMenu {
public:
  DBMenu();
  ~DBMenu();

  void init(); //holds loop for menu until quit
  void mainMenu(); //prints main 14 options
  void studentInfo(); //prompts for adding a new student if selected
  void facultyInfo(); //prompts for adding new faculty if selected
private:
  Database universityDB;
};
