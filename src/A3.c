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

void inputParse(FILE * input) {
	room * roomOneStruct;
	room * roomTwoStruct;
	room * roomThreeStruct;
	room * roomFourStruct;
	room * roomFiveStruct;
	room * roomSixStruct;
	char token[150];
	char roomOne[150];
	char roomTwo[150];
	char roomThree[150];
	char roomFour[150];
	char roomFive[150];
	char roomSix[150];

	fgets(token, 150, input);
	strcpy(roomOne, token);
	fgets(token, 150, input);
	strcpy(roomTwo, token);
	fgets(token, 150, input);
	strcpy(roomThree, token);
	fgets(token, 150, input);
	strcpy(roomFour, token);
	fgets(token, 150, input);
	strcpy(roomFive, token);
	fgets(token, 150, input);
	strcpy(roomSix, token);

	roomOneStruct = makeRoomStruct(roomOne);
	roomTwoStruct = makeRoomStruct(roomTwo);
	roomThreeStruct = makeRoomStruct(roomThree);
	roomFourStruct = makeRoomStruct(roomFour);
	roomFiveStruct = makeRoomStruct(roomFive);
	roomSixStruct = makeRoomStruct(roomSix);
	drawLevel(roomOneStruct, roomTwoStruct, roomThreeStruct, roomFourStruct, roomFiveStruct, roomSixStruct);
	drawDoors(roomOneStruct, roomTwoStruct, roomThreeStruct, roomFourStruct, roomFiveStruct, roomSixStruct);
}

room * makeRoomStruct(char * roomString) {
	char * token;
	room * tempRoom;
	int tempNum;
	door * tempDoor;

	tempRoom = malloc(sizeof(room));
	tempDoor = malloc(sizeof(door));

	token = strtok(roomString, "X");
	tempNum = atol(token);
	tempRoom->rows = tempNum;
	
	token = strtok(NULL, " ");
	tempNum = atol(token);
	tempRoom->col = tempNum;

	token = strtok(NULL, " ");
	if (token[0] == 'd') {
		switch(token[1]) {
			case 'n':
				tempDoor->wall = 1;
				break;
			case 'e':
				tempDoor->wall = 2;
				break;
			case 's':
				tempDoor->wall = 3;
				break;
			case 'w':
				tempDoor->wall = 4;
				break;
		}
		tempNum = token[2] - '0';
		tempDoor->dist = tempNum;
		tempRoom->doorOne = tempDoor;
	}

	return tempRoom;
}

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

void moveHero(char direction) {
	int y = 0;
	int x = 0;
	switch (direction) {
		getyx(stdscr, y, x);
		case 'w':
			printw(".");
			y--;
			move (y,x);
			printw("@");
			break;
		case 'a':
			printw(".");
			x--;
			move (y,x);
			printw("@");
			break;
		case 's':
			printw(".");
			y++;
			move (y,x);
			printw("@");
			break;
		case 'd':
			printw(".");
			x++;
			move (y,x);
			printw("@");
			break;
	}
	move(y,x);
}