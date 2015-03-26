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

Compilation

To compile this program, point your terminal at the directory containing the src, include, assets, docs and bin folders and Makefile.
Type make into the command line and the program will compile.

Running

After compiling, stay in the same directory and type ./bin/runMe and the path to the file containing the information for the level in quotes ("") into the terminal.
You can also choose to type 'make run1','make run2','make run3' or 'make run4' into the terminal to run the program with the levels used during developement of the program.

Operation

When the program is run, the hero (represented by the @ symbol) starts in the first room (upper left).  The player can move around the level using the wasd keys.
The doors are represented by the + symbol.  When a player walks through the door, they are moved to the next room (room 1 to 2, 2 to 3 ... 6 to 1).
To quit the game, press 'q', all other key presses are invalid.

Known limitations

The program cannot print any special characters (monsters, stairs, gold potions etc...).  As a result, the program cannot keep track of items collected by the player.
The program also cannot take in hero starting location from file, the hero therefore starts in position (1,1).
The program also can only take in one door per room from file, this means only one door will be printed per room.
The program has no teleportation from room to room built in so the hero is allowed to free roam between rooms, entering and exiting other rooms through the doors.

Extras

None
