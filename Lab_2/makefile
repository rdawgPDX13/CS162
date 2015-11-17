# This makefile holds the files for Lab3 dice game

dice: die.o LoadedDie.o regDie.o Game.o
	g++ die.o LoadedDie.o regDie.o Game.o -o dice

die.o: die.cpp
	g++ -c die.cpp

LoadedDie.o: LoadedDie.cpp
	g++ -c LoadedDie.cpp

regDie.o: regDie.cpp
	g++ -c regDie.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

clean:
	rm -rf *o dice 
