#ifndef FBCURSES
#define FBCURSES
#include "ncurses.h"

typedef int colorcode_t;

//initScreen()
//Initializes the curses library and sets up the screen for use
//Parameters: none
//Returns: none
//Side effects: Disrupts the terminal making normal input difficult until cleanupScreen is called.
void initScreen();

//cleanupScreen()
//Cleans up after a previous call to initScreen
//Parameters: none
//Returns: none
//Side effects: Resets the terminal to its previous state before the call to initScreen.
void cleanupScreen();

//initColor: Initializes a color using one of the curses colors:  
//parameters: color: pass one of COLOR_BLACK,COLOR_RED,COLOR_GREEN,COLOR_YELLOW,COLOR_BLUE,COLOR_MAGENTA,COLOR_CYAN,COLOR_WHITE
//returns: an ncurses color identifier for use with all other methods
//Side effects: creates a color in curses that remains until cleanupScreen is called
colorcode_t initColor(int color);

//clearScreen: blanks the virtual screen
//paramters: colorcode: A colorcode_t returned from a previous call to initColor
//returns: none
//Side effects: Erases the virtual screen area with the specified background color
void clearScreen(colorcode_t colorcode);

//setPixel: Sets a pixel on the virtual 8x8 screen
//parameters: 	x: column number for the pixel (0-7)
//				y: row number for the pixel (0-7)
//				colorcode: A colorcode_t returned from a previous call to initColor
//returns: 		none
//Side effects: Turns on a pixel on the virtual screen
void setPixel(int x,int y, colorcode_t colorcode);

//kbhit: check for user keypress (non-blocking)
//parameters: none
//returns: non-zero if a key was pressed, zero otherwise
//notes: 	This is not the normal unix behavior.  This function will block (wait for a keypress) and always return non-zero unless 
//			it is called between initScreen and cleanupScreen.  If it is it will not block but return immediately with the appropriate
//			return value.
int kbhit(void);
#endif
