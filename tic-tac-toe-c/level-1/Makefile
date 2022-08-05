CC := gcc

.PHONY: all clean

all: tic-tac-toe

tic-tac-toe: main game board
	@echo 'Creating the Final Executable.'
	${CC} main.o game.o board.o -o tic-tac-toe

main: 
	@echo 'Creating the Main object.'
	${CC} main.c -c

game:
	@echo 'Creating the Game object.'
	${CC} game.c -c 

board:
	@echo 'Creating the Board object.'
	${CC} board.c -c

clean:
	@echo 'Cleaning up all.'
	rm -rf *.o
	rm tic-tac-toe