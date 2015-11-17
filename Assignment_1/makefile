# This makefile holds the files for Ryan's Game of Life (GOL)

ryanSGOL: generationOne.o mainGOL.o 
	g++ generationOne.o mainGOL.o -o gol

generationOne.o: generationOne.cpp
	g++ -c generationOne.cpp

golMain.o: mainGOL.cpp
	g++ -c mainGOL.cpp

clean:
	rm -rf *o gol
