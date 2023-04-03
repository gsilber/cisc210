#include "FBCurses.h"
#include <stdio.h>
#define START_ROW 1
#define START_COLUMN 1

//initScreen()
//Initializes the curses library and sets up the screen for use
//Parameters: none
//Returns: none
//Side effects: Disrupts the terminal making normal input difficult until cleanupScreen is called.
void initScreen()
{
	initscr();
	start_color();
	nodelay(stdscr,TRUE);
	curs_set(0);
}

//cleanupScreen()
//Cleans up after a previous call to initScreen
//Parameters: none
//Returns: none
//Side effects: Resets the terminal to its previous state before the call to initScreen.
void cleanupScreen()
{
	endwin();
}

//initColor: Initializes a color using one of the curses colors:  
//parameters: color: pass one of COLOR_BLACK,COLOR_RED,COLOR_GREEN,COLOR_YELLOW,COLOR_BLUE,COLOR_MAGENTA,COLOR_CYAN,COLOR_WHITE
//returns: an ncurses color identifier for use with all other methods
//Side effects: creates a color in curses that remains until cleanupScreen is called
colorcode_t initColor(int color){
	static int pairCounter=1;
	init_pair(pairCounter,COLOR_BLACK,color);
	return pairCounter++;
}

//clearScreen: blanks the virtual screen
//paramters: colorcode: A colorcode_t returned from a previous call to initColor
//returns: none
//Side effects: Erases the virtual screen area with the specified background color
void clearScreen(colorcode_t colorCode)
{
	attron(COLOR_PAIR(colorCode));
	for (int i=0;i<17;i++)
		mvhline(i+START_ROW,START_COLUMN,' ',34);
	attroff(COLOR_PAIR(colorCode));
}

//setPixel: Sets a pixel on the virtual 8x8 screen
//parameters: 	x: column number for the pixel (0-7)
//				y: row number for the pixel (0-7)
//				colorcode: A colorcode_t returned from a previous call to initColor
//returns: 		none
//Side effects: Turns on a pixel on the virtual screen
void setPixel(int x,int y, colorcode_t colorCode)
{
	attron(COLOR_PAIR(colorCode));
	mvaddstr(y*2+START_ROW+1,2+x*4+START_COLUMN,"  ");
	attroff(COLOR_PAIR(colorCode));
}

//kbhit: check for user keypress (non-blocking)
//parameters: none
//returns: non-zero if a key was pressed, zero otherwise
//notes: 	This is not the normal unix behavior.  This function will block (wait for a keypress) and always return non-zero unless 
//			it is called between initScreen and cleanupScreen.  If it is it will not block but return immediately with the appropriate
//			return value.
int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}