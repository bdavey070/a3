typedef struct rmStrings
{
	char * roomOne;
	char * roomTwo;
	char * roomThree;
	char * roomFour;
	char * roomFive;
	char * roomSix;
	
}rmStrings;

typedef struct door
{
	int wall;
	int dist;
}door;

typedef struct item
{
	int type;
	int rows;
	int cols;
}item;

typedef struct hero
{
	int rows;
	int columns;
}hero;

typedef struct room
{
	int rows;
	int col;
	door * doorOne;
	door * doorTwo;
	door * doorThree;
	door * doorFour;
	hero * player;
	item * itemArray;
}room;


typedef struct level
{
	room * roomOne;
	room * roomTwo;
	room * roomThree;
	room * roomFour;
	room * roomFive;
	room * roomSix;
}level;
/*drawing*/

/***************************************************************************************************
Function: drawLevel
Purpose: To draw the outline and floors of the room according to size from input file.
Pre: Takes in a pointer to each room struct containing the size of the room and location of doors.
Post: Prints the outline and floor of all six rooms to the screen.
***************************************************************************************************/
void drawLevel(room * roomOne, room * roomTwo, room * roomThree, room * roomFour, room * roomFive, room * roomSix);
/***************************************************************************************************
Function: drawDoors
Purpose: To draw the doors in each of the rooms.
Pre: Takes in a pointer to each room struct containing the size of the room and location of doors.
Post: Prints the doors in each room.
***************************************************************************************************/
void drawDoors(room * roomOne, room * roomTwo, room * roomThree, room * roomFour, room * roomFive, room * roomSix);

/*file*/

/***************************************************************************************************
Function: inputParse
Purpose: To read a file and parse it creating strings out of each line.
Pre: Takes in a pointer to the file to be parsed.
Post: Creates a string for each line in the file.
***************************************************************************************************/
void inputParse(FILE * input);
/***************************************************************************************************
Function: makeRoomStruct
Purpose: To parse strings by the space and create structs that represent rooms in the level.
Pre: Takes in a pointer to a single room string.
Post: Returns a room struct with size and door information.
***************************************************************************************************/
room * makeRoomStruct(char * roomString);


/*movement*/

/***************************************************************************************************
Function: moveHero
Purpose: To move the hero character around the screen while not changing the landscape.
Pre: Takes in a character that is provided by the user representing the direction to be moved.
Post: Moves the hero to the new location if that location is not a wall.
***************************************************************************************************/
void moveHero(char direction);
/***************************************************************************************************
Function: checkNext
Purpose: To check to see if where the hero is to be moved is occupied by a wall.
Pre: Takes in two integers representing the location to be moved to.
Post: Returns a 0 if the location is a valid move and a 1 if not.
***************************************************************************************************/
int checkNext(int y, int x);


/*items*/