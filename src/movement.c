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

void moveHero(char direction) {
	int y = 0;
	int x = 0;
	int check = 0;
	getyx(stdscr, y, x);
	printw(".");
	switch (direction) {	
		case 'w':
			y--;
			check = checkNext(y,x);
			if (check == 1) {
				y++;
			}
			break;
		case 'a':
			x--;
			check = checkNext(y,x);
			if (check == 1) {
				x++;
			}
			break;
		case 's':
			y++;
			check = checkNext(y,x);
			if (check == 1) {
				y--;
			}
			break;
		case 'd':
			x++;
			check = checkNext(y,x);
			if (check == 1) {
				x--;
			}
			break;
	}
	move (y,x);
	printw("@");
	move(y,x);
}

int checkNext(int y, int x) {
	char test;
	test = mvinch(y,x);
	switch (test) {
		case '.':
			return 0;
			break;
		case '+':
			return 0;
			break;
		case '|':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case ' ':
			return 0;
			break;
		default:
			return 1;
			break;

	}
}

