//routines of functions from <ncurses>

void clearScreen(){  
   for(int x = 0; x < 24; x++)
      for(int y = 0; y < 54; y++)
         mvaddch(y, x, ' ');
}

void drawFullscreenBorder(char graphic){
   for(int x = 0; x < 54; x++){   //Top and bottom borders
      mvaddch(0, x, graphic);
      mvaddch(23, x, graphic);
   }

   for(int y = 0; y < 24; y++){   //Left and right borders
      mvaddch(y, 0, graphic);
      mvaddch(y, 54, graphic);
   }
}

void init_curses(){
   initscr();           //This block of stuff starts Curses mode,
   cbreak();            //disables the input buffer (inputs sent immediately after keypress), 
   keypad(stdscr, true);//allows nonstandard keyboard inputs,
   noecho();            //disables drawing inputs to the screen, 
   start_color();       //gives us pretty colors,
   curs_set(0);         //and disables the cursor graphic
   return;
}