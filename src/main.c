/***********************************************************************************************
Student Name: Benjamin Davey    Student Number: 0885413 
Date: Friday, March 13, 2015  Course Name: CIS2500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "A3.h"

int main(int argc, char * argv[]) {
	if (argc != 2) {
		printf("Incorrect command line arguments\n");
		exit(0);
	}
	char path[100];
	char dir;
	initscr();
    noecho();
    cbreak();
	strcpy(path, argv[1]);
	FILE * input;
	input = fopen(path, "r");
	inputParse(input);
	move(1,1);
	printw("@");
	move(1,1);
	do {
		dir = getch();
		moveHero (dir);
	} while (dir != 'q');
	endwin();
	return 0;
}

