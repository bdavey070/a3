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

