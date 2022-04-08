//routines of functions from <ncurses>

const int MAXX = 78;
const int MAXY = 25;



void clearScreen(){  
   for(int x = 0; x < 25; x++)
      for(int y = 0; y < 78; y++)
         mvaddch(y, x, ' ');
}

void clearWorkspace(){
   for(int x = 5; x < 24; x++)
       for(int y = 1; y < 77; y++)
          mvaddch(x, y, ' ');
}
void drawFullscreenBorder(char graphic){
   for(int x = 0; x < 78; x++){   //Top and bottom borders
      mvaddch(0, x, graphic);
      mvaddch(24, x, graphic);
   }

   for(int y = 0; y < 25; y++){   //Left and right borders
      mvaddch(y, 0, graphic);
      mvaddch(y, 78, graphic);
   }
}

void highlightOption(int option, int column){
   string icon = "->";
   mvaddstr(6 + 2 * option, 2 + 15 * column, icon.c_str());
}

void clearOption(int option, int column){
   string icon = "  ";
   mvaddstr(6 + 2 * option, 2 + 15 * column, icon.c_str());
}

void drawHeader(){
   string header = " Literary Cataloguing Software LCS  |  w and s move, enter selects, ` backs";
   mvaddch(1, 38, '|');
   mvaddch(3, 38, '|');
   mvhline(4, 1, '-', 76);
   mvaddstr(2, 2, header.c_str());
}

void displayMainMenuOptions(){
   vector<string> menuitems;
   menuitems.push_back("Browse");
   menuitems.push_back("Read Excerpt");
   menuitems.push_back("Add to Library");
   menuitems.push_back("Edit Book");
   for(int i = 0; i < menuitems.size(); i++){
      mvaddstr(6 + 2*i, 5, menuitems.at(i).c_str());
   }
}

void displayBrowseLabels(){
   clearWorkspace();
   vector<string> menuitems;
   menuitems.push_back("Title:");
   menuitems.push_back("Author:");
   menuitems.push_back("Publisher:");
   menuitems.push_back("Date:");
   menuitems.push_back("Page Count:");
   menuitems.push_back("Reading Time:");
   menuitems.push_back("Completed?");
   for(int i = 0; i < menuitems.size(); i++){
      mvaddstr(6 + 2*i, 5, menuitems.at(i).c_str());
   }
}

void displayBrowseBook(vector<Book*> library, int idx){
   displayBrowseLabels();
   vector<string> menudata;
   Book* book = library.at(idx);
   menudata.push_back(book->getTitle());
   menudata.push_back(book->getAuthor());
   menudata.push_back(book->getPublisher());
   menudata.push_back(book->getDate());
   menudata.push_back(to_string(book->getPageCount()));
   menudata.push_back(as_dhm(book->getReadingTime()));
   menudata.push_back(book->isComplete());
   for(int i = 0; i < menudata.size(); i++){
      mvaddstr(6 + 2*i, 25, menudata.at(i).c_str());
   }
}


void readBook(){}
void createBook(){}
void editBook(){}

int handleVertInput(int maxitem, int column){
   char input = ' ';
   int menuitem = 0;
   while(input != '`'){
      highlightOption(menuitem, column);
      refresh();
      input = getch();
      clearOption(menuitem, column);
      switch(input){
         case '\n':
            return menuitem;
         break;
         case 'w':
            if(menuitem > 0){
               menuitem--;
            }
         break;
         case 's':
            if(menuitem < maxitem - 1){
               menuitem++;
            }
         break;
      }
   }
   return -1;
}

void handleHorInput(int maxitem, int &menuitem){
   char input = ' ';
   string left = "<-";
   string right = "->";
   string clear = "           ";
   while(input != '`'){
      if(menuitem > 0){
         mvaddstr(5, 35, left.c_str());
      }
      if(menuitem < maxitem - 1){
         mvaddstr(5, 40, right.c_str());
      }
      refresh();
      input = getch();
      mvaddstr(5, 34, clear.c_str());
      switch(input){
         case '`':
            menuitem = -1;
            return;
         case 'a':
            if(menuitem > 0){
               menuitem--;
               return;
            }
         break;
         case 'd':
            if(menuitem < maxitem - 1){
               menuitem++;
               return;
            }
         break;
      }
   }
   return;
}

void browseLibrary(vector<Book*> library){
   int idx = 0;
   while(idx != -1){
      displayBrowseBook(library, idx);
      handleHorInput(library.size(), idx);
   }
}

void mainMenu(vector<Book*> library){
   int option = 0;
   while(option != -1){
      clearWorkspace();
      displayMainMenuOptions();
      option = handleVertInput(4, 0);
      switch(option){
            case -1:
               break;
            case 0:
               browseLibrary(library);
               break;
            case 1:
               readBook();
               break;
            case 2:
               createBook();
               break;
            case 3:
               editBook();
               break;
      }
   }
}

void init_curses(){
   initscr();           //This block of stuff starts Curses mode,
   cbreak();            //disables the input buffer (inputs sent immediately after keypress), 
   keypad(stdscr, true);//allows nonstandard keyboard inputs,
   noecho();            //disables drawing inputs to the screen, 
   start_color();       //gives us pretty colors, (not bothering with rn)
   curs_set(0);         //and disables the cursor graphic
   return;
}