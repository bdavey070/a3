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

void drawLevel(room * roomOne, room * roomTwo, room * roomThree, room * roomFour, room * roomFive, room * roomSix) {
	int i = 0;
	int j = 0;
	int tempLen = 0;
	int tempWid = 0;

	tempLen = roomOne->rows + 1;
	tempWid = roomOne->col + 1;
	for (i = 0; i < tempLen; i++) {
		move(i, 0);
		printw("|");
		move(i, tempWid);
		printw("|");
	}
	for(i = 0; i < tempWid + 1; i++) {
		move(0, i);
		printw("-");
		move(tempLen, i);
		printw("-");
	}
	for(j = 1; j < tempLen; j++) {

		for(i = 1; i < tempWid; i++) {
			move(j,i);
			printw(".");
		}
	}

	tempLen = roomTwo->rows + 1;
	tempWid = roomTwo->col + 1;
	for (i = 0; i < tempLen; i++) {
		move(i, 28);
		printw("|");
		move(i, tempWid + 28);
		printw("|");
	}
	for(i = 28; i < tempWid + 29; i++) {
		move(0, i);
		printw("-");
		move(tempLen, i);
		printw("-");
	}
	for(j = 1; j < tempLen; j++) {

		for(i = 29; i < tempWid + 28; i++) {
			move(j,i);
			printw(".");
		}
	}

	tempLen = roomThree->rows + 1;
	tempWid = roomThree->col + 1;
	for (i = 0; i < tempLen; i++) {
		move(i, 56);
		printw("|");
		move(i, tempWid + 56);
		printw("|");
	}
	for(i = 56; i < tempWid + 57; i++) {
		move(0, i);
		printw("-");
		move(tempLen, i);
		printw("-");
	}
	for(j = 1; j < tempLen; j++) {

		for(i = 57; i < tempWid + 56; i++) {
			move(j,i);
			printw(".");
		}
	}

	tempLen = roomFour->rows + 1;
	tempWid = roomFour->col + 1;
	for (i = 23; i < tempLen + 23; i++) {
		move(i, 0);
		printw("|");
		move(i, tempWid);
		printw("|");
	}
	for(i = 0; i < tempWid + 1; i++) {
		move(23, i);
		printw("-");
		move(tempLen + 23, i);
		printw("-");
	}
	for(j = 24; j < tempLen + 23; j++) {

		for(i = 1; i < tempWid; i++) {
			move(j,i);
			printw(".");
		}
	}

	tempLen = roomFive->rows + 1;
	tempWid = roomFive->col + 1;
	for (i = 23; i < tempLen + 23; i++) {
		move(i, 28);
		printw("|");
		move(i, tempWid + 28);
		printw("|");
	}
	for(i = 28; i < tempWid + 29; i++) {
		move(23, i);
		printw("-");
		move(tempLen + 23, i);
		printw("-");
	}
	for(j = 24; j < tempLen + 23; j++) {

		for(i = 29; i < tempWid + 28; i++) {
			move(j,i);
			printw(".");
		}
	}

	tempLen = roomSix->rows + 1;
	tempWid = roomSix->col + 1;
	for (i = 23; i < tempLen + 23; i++) {
		move(i, 56);
		printw("|");
		move(i, tempWid + 56);
		printw("|");
	}
	for(i = 56; i < tempWid + 57; i++) {
		move(23, i);
		printw("-");
		move(tempLen + 23, i);
		printw("-");
	}
	for(j = 24; j < tempLen + 23; j++) {

		for(i = 57; i < tempWid + 56; i++) {
			move(j,i);
			printw(".");
		}
	}
	refresh();
}

void drawDoors(room * roomOne, room * roomTwo, room * roomThree, room * roomFour, room * roomFive, room * roomSix) {
	int tempWall = 0;
	int tempDoor = 0;
 
	tempWall = roomOne->doorOne->wall;
	tempDoor = roomOne->doorOne->dist;
	switch (tempWall) {
		case 1:
			move(0, tempDoor);
			printw("+");
			break;
		case 2:
			move(tempDoor, roomOne->col + 1);
			printw("+");
			break;
		case 3:
			move(roomOne->rows + 1, tempDoor);
			printw("+");
			break;
		case 4:
			move(tempDoor, 0);
			printw("+");
			break;

	}
	tempWall = roomTwo->doorOne->wall;
	tempDoor = roomTwo->doorOne->dist;
	switch (tempWall) {
		case 1:
			move(0, tempDoor + 28);
			printw("+");
			break;
		case 2:
			move(tempDoor, roomTwo->col + 29);
			printw("+");
			break;
		case 3:
			move(roomTwo->rows + 1, tempDoor + 28);
			printw("+");
			break;
		case 4:
			move(tempDoor, 28);
			printw("+");
			break;

	}
	tempWall = roomThree->doorOne->wall;
	tempDoor = roomThree->doorOne->dist;
	switch (tempWall) {
		case 1:
			move(0, tempDoor + 56);
			printw("+");
			break;
		case 2:
			move(tempDoor, roomThree->col + 57);
			printw("+");
			break;
		case 3:
			move(roomThree->rows + 1, tempDoor + 56);
			printw("+");
			break;
		case 4:
			move(tempDoor, 56);
			printw("+");
			break;

	}
	
	tempWall = roomFour->doorOne->wall;
	tempDoor = roomFour->doorOne->dist;
	switch (tempWall) {
		case 1:
			move(23, tempDoor);
			printw("+");
			break;
		case 2:
			move(tempDoor + 23, roomFour->col + 1);
			printw("+");
			break;
		case 3:
			move(roomFour->rows + 24, tempDoor);
			printw("+");
			break;
		case 4:
			move(tempDoor + 23, 0);
			printw("+");
			break;
	}
	tempWall = roomFive->doorOne->wall;
	tempDoor = roomFive->doorOne->dist;
	switch (tempWall) {
		case 1:
			move(23, tempDoor + 28);
			printw("+");
			break;
		case 2:
			move(tempDoor + 23, roomFive->col + 29);
			printw("+");
			break;
		case 3:
			move(roomFive->rows + 24, tempDoor + 28);
			printw("+");
			break;
		case 4:
			move(tempDoor + 23, 28);
			printw("+");
			break;

	}
	tempWall = roomSix->doorOne->wall;
	tempDoor = roomSix->doorOne->dist;
	switch (tempWall) {
		case 1:
			move(23, tempDoor + 56);
			printw("+");
			break;
		case 2:
			move(tempDoor + 23, roomSix->col + 57);
			printw("+");
			break;
		case 3:
			move(roomSix->rows + 24, tempDoor + 56);
			printw("+");
			break;
		case 4:
			move(tempDoor + 23, 56);
			printw("+");
			break;
	}
}

