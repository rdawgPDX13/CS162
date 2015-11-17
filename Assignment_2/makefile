# This is a makefile for assignment 2

main: main.o Items.o List.o
	g++ main.o Items.o List.o

main.o : main.cpp
	g++ -c main.cpp

Items.o: Items.cpp
	g++ -c Items.cpp

List.o: List.cpp
	g++ -c List.cpp

clean:
	rm -rf *o main
