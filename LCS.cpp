#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdio.h>
#include <curses.h>
#include "bookClass.cpp"
#include "curses.cpp"

using namespace std;

int main(int argc, char** argv){
   string filename = argv[1];
   vector<Book*> library;
   init_curses();
   populateLibrary(library, filename);
   mainMenu(library);
   return 0;
};
