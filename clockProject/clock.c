#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "FBCurses.h"

void showTime(colorcode_t oncolor,colorcode_t offcolor){
	//your code goes here
}

int main(){
	initScreen();
	//feel free to change the color scheme to your liking.
	colorcode_t background=initColor(COLOR_RED);
	colorcode_t offcolor=initColor(COLOR_BLACK);
	colorcode_t oncolor=initColor(COLOR_WHITE);
	clearScreen(background);

 	while (!kbhit()){
		showTime(oncolor,offcolor);
		sleep(.5);

	}
	cleanupScreen();
}
