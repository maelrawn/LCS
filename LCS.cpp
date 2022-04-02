/*ASSIGNMENT INFORMATION
Due Date
Monday, April 11, 2022
6:30 PM
Points Possible
100
A menu-driven program that gives the user the option to track statistics about different players on some sort of team. The program reads all the statistics from a file and stores the data for a minimum of ten players, including player’s name, player’s team, and a minimum of 5 additional statistics.

Requirements – 80% of Grade

Menu driven program that loops after each selection until user chooses to exit
Read initial data in from a file
Minimum of 10 Players
Players Name, Team, and minimum of 5 additional statistics
Use Class to store the data from the file
Menu Options:
Print out all users and statistics
Print out the statistics for a specific player
Print out all data for a specific team
Update the data for a specific player
Let the users Insert a new player and their statistics
Let the user export the data to an output file
Organized in 3 files:
Main CPP
Class Header
Class CPP
All work and procedures to completed in Member Functions
Comment all code*/


/*PROJECT GOALS:

Real-time TUI
Navigable menus:
   
   - team select
      - save/load
   - display stats
   - edit players
   - quit

Have to ask professor if we are allowed to use external packages,
I would like to use ncurses to do this but I can use unicode chars
to simulate flashing menu options otherwise. Probably can simulate
real time graphics by printing a screen of text at a time? Problem
becomes not printing one line at a time without the ability to blit,
but I could probably just create one gigantic 80x24 monster string 
and print the entire thing at once? Alternatively, find some way to 
pause the terminal refresh until printing is done (wow I just
am describing ncurses or analogues).

Professor said I can use ncurses. Project screen mockup:

##############################################################################
#                                    |                                       #
#  Literary Cataloguing Software LCS | Arrows move, return selects, q quits  #
#                                    |                                       #
#----------------------------------------------------------------------------#
#                           |                                                #
#   Browse Entire Library   |   Kodansha Press                               #
#                           |                                                #
# ->Browse By Publisher     | ->Penguin Random House                         #
#                           |                                                #
#   Search For Title        |   ...                                          #
#                           |                                                #
#   Insert Title            |                                                #
#                           |                                                #
#   Library Stats           |                                                #
#                           |                                                #
#----------------------------                                                #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
##############################################################################

##############################################################################
#                                    |                                       #
#  Literary Cataloguing Software LCS | Arrows move, return selects, q quits  #
#                                    |                                       #
#----------------------------------------------------------------------------#
#                           |                                                #
#   Browse Entire Library   |  --> Kodansha Press <--                        #
#                           |                                                #
# ->Browse By Publisher     |     book1                                      #
#                           |                                                #
#   Search For Title        |     book2                                      #
#                           |                                                #
#   Insert Title            |     ...                                        #
#                           |                                                #
#   Library Stats           |                                                #
#                           |                                                #
#----------------------------                                                #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
#                                                                            #
##############################################################################

Teams must be stored in a class, as per project specifications

   Class should have:
   Publisher info (stats), playersVec (class)

   setter/getter methods
   methods for adding/removing players from the vector
   methods for writing/instantiating to/from file

   Players class should have:
   lots of stats
   setter/getter methods

   Remember to use #IFNDEFS and hpp/cpp structure

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <curses.h>
#include "publisherClass.hpp"
#include "curses.cpp"

using namespace std;

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

int main(){


   // initscr();           //This block of stuff starts Curses mode,
   // cbreak();            //disables the input buffer (inputs sent immediately after keypress), 
   // keypad(stdscr, true);//allows nonstandard keyboard inputs,
   // noecho();            //disables drawing inputs to the screen, 
   // start_color();       //gives us pretty colors,
   // curs_set(0);         //and disables the cursor graphic

   // drawFullscreenBorder('a');
   // refresh();
   // sleep(3);
   // clearScreen(); uncomment this stuff when the work part is done
   // curs_set(1);



};