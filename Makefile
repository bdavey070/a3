all:
	gcc -Wall -std=c99 src/main.c src/drawing.c src/movement.c src/files.c -Iinclude -o bin/runMe -lncurses
run1:
	./bin/runMe "assets/room1.txt"
run2:
	./bin/runMe "assets/room2.txt"
run3:
	./bin/runMe "assets/room3.txt"
run4:
	./bin/runMe "assets/room4.txt"