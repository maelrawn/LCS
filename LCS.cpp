#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdio.h>
#include <curses.h>
#include <regex>
#include "bookClass.cpp"
#include "curses.cpp"

using namespace std;

int main(int argc, char** argv){
   if(argc == 1){
      cout<<"Program must be called with an argument for file path.";
      return 1;
   }
   string filename = argv[1];
   vector<Book*> library;
   init_curses();
   populateLibrary(library, filename);
   mainMenu(library);
   return 0;
};
