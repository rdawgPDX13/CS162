/***************************************************************************** Author: Ryan Osborne
** Date:
** Description:
***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "generationOne.hpp"
#include "chsePat.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int rows,
	columns,
	pRows,
	pCols,
	position,
	option,
	numGens = 0;
    rows = 32;
    columns = 52;
    pRows = 20;
    pCols = 40;
    system("clear");
    // Post test loop inserted to allow only positive intergers 
    do
    {  
        cout << "Enter game of life pattern starting point"  
             << " (positive integer): " << endl; 
             cin >> position;
    } while (position < 0);
    
    // Declare the class object
    GOL board(rows, columns, pRows, pCols, position);
    system("clear");
    board.printBoard();
    board.showOptions();
    option = board.getOption();
    if(option == 1)
    {
	board.setGlider(position);
    }
    else if(option == 2)
    {
	board.setOscillator(position);
    }
    else if(option == 3)
    {
	board.setBigGuns(position);
    }
    else if (option >=4)
    {
	exit(0);
    } 
    cout << endl;
    cout << "Initial Game of Life Board:\n";
    board.printBoard();
    cout << endl;
    if(option !=4)
    {
        do
	{
            cout << "Enter number of generations: " << endl;
    	    cin >> numGens;
        } while (numGens <=0);
    } 
    for(int gen = 0; gen < numGens; gen++)
    {
	usleep(250000);
        board.nextGen();
	system("clear");
	board.printBoard();
	cout << endl;
    }
    cout << "Game board after " << numGens << " generations.\n";
    cout << endl;
    return 0;
}
