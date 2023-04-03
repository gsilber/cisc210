#include <stdio.h>
#include "FBCurses.h"

void drawCheckerboard(colorcode_t oncolor,colorcode_t offcolor){
	int selector=1;
	for (int y=0;y<8;y++){
		for (int x=0;x<8;x++){
			//selector chooses black or white for this dot
			if (selector)
				setPixel(x,y,oncolor);
			else 
				setPixel(x,y,offcolor);
			//alternate as we go accross the row
			selector=!selector; 
		}
		//when we get to a new row, start it on the other color
		selector=!selector; 
	}
}

int main(){
	initScreen();
	colorcode_t background=initColor(COLOR_RED);
	colorcode_t offcolor=initColor(COLOR_BLACK);
	colorcode_t oncolor=initColor(COLOR_WHITE);
	clearScreen(background);
	drawCheckerboard(oncolor,offcolor); 
 	while (!kbhit());
	cleanupScreen();
}