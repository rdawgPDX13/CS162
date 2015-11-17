/***************************************************************************** Author: Ryan Osborne
** Date: 09292015
** Description: generationOne.cpp is a GOL class function implementation
	        file
***************************************************************************/
#include "generationOne.hpp"
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

/**************************************************************************
*			GOL::GOL
* This is a default constructor that intializes the various variables passed
* into the function.
*
**************************************************************************/
GOL::GOL(int rw, int cl, int pRw, int pCl, int strt)
{   
    // Board rows including the fringe
    bdRows = rw;
    bdCols = cl;
    // Printed board rows visible to user
    pRows = pRw;
    pCols = pCl;
    // Position where pattern starts based on user selection
    position = strt;
    // Assigning of characters to the alive and dead variables
    alive = 'O';
    dead = '.';
    // Dynamically allocate array to store game board pattern
    golMap = new char*[bdRows];
    for(int num = 0; num < bdRows; ++num)
    {
	golMap[num] = new char[bdCols];
    }
    /*  // Just a little pattern I wanted to see interact
        golMap[0][1] = alive;
        golMap[1][2] = alive;
        golMap[2][0] = alive;
        golMap[2][1] = alive;
        golMap[2][2] = alive;

        // edit +2
	golMap[3][3] = alive;
	golMap[3][4] = alive;
	golMap[4][3] = alive;
	golMap[4][4] = alive;
	golMap[5][5] = alive;
	golMap[5][6] = alive;
	golMap[6][5] = alive;
	golMap[6][6] = alive;
     */   
}


/**************************************************************************
*			GOL::nextGen
* This function accounts for all the rules that dictate the game. Also 
* creates a temporary array to store values for each changing generation. 
* Assigns array proper alive and dead cells based on pattern selected
*
**************************************************************************/
void GOL::nextGen()
{ 
    
     
    int neighbors = 0;
    // Initialize a temporary holding array
    char golArray[bdRows][bdCols];  
   
    // Rules for the game of life neighbor interactions
    for(int r = 0; r < bdRows; r++)
    {
	for(int c = 0; c < bdCols; c++)
	{
	    if((r+1) < bdRows && golMap[r+1][c] == alive)
	    {
		neighbors++;
            } 
	    if((r-1) >= 0 && golMap[r-1][c] == alive)
	    {	
		neighbors++;
	    } 
            if((c+1) < bdCols && golMap[r][c+1] == alive)
 	    {
		neighbors++;
	    } 
	    if((c-1) >= 0 && golMap[r][c-1] == alive)
	    {
		neighbors++;
	    }
	    if((r+1) < bdRows && (c+1) < bdCols && golMap[r+1][c+1] == alive)
	    {
		neighbors++;
	    }
	    if((r+1) < bdRows && (c-1) >=0 && golMap[r+1][c-1] == alive)
	    {
		neighbors++;
	    }
 	    if((r-1) >=0 && (c+1) < bdCols && golMap[r-1][c+1] == alive)
	    {
		neighbors++;
	    }
	    if((r-1) >=0 && (c-1) >=0 && golMap[r-1][c-1] == alive)
  	    {
 		neighbors++;
	    } 
 	    
	    // Assigning the char to array
	    // Rule 1 and 2       
            if(neighbors < 2 || neighbors > 3)
	    {
		golArray[r][c] = dead;
	    } 
	    else if( neighbors == 2) 
	    {
		golArray[r][c] = golMap[r][c];
	    } 
	    // Rule 3
	    if(neighbors == 3)
	    {
		golArray[r][c] = alive;
	    } 
	    neighbors = 0; // reset value for next generation

	}
    }
    // Set dynamically allocated array to values passed by temp array
    for(int r =0; r < bdRows; r++)
    {
	for(int c = 0; c < bdCols; c++)
	{
	    golMap[r][c] = golArray[r][c];
	}
    } 

} 
/**************************************************************************
*			GOL::printBoard()     
* This function is involved with printing the array as specified by the 
* rules above.
**************************************************************************/
void GOL::printBoard()
{
    for(int r = 0; r < pRows; r++)
    {
	for(int c = 0; c < pCols; c++)
	{
	    if(golMap[r][c] == alive)
	    {
		cout << 'O';
	    } 
	    else
	    {
		cout << '.';
	    }
	    if((c+1) >= pCols)
	    {
		cout << endl;
	    } 
	}
    }
}


/**************************************************************************
*			GOL::~GOL
* Clears the dynamically allocated arrays memory with a destructor
*
**************************************************************************/
GOL::~GOL()
{
    for(int dlt = 0; dlt < bdRows; ++dlt)
    {
	delete [] golMap[dlt];
    }
    delete [] golMap;
}

/**************************************************************************
* 			GOL::glider()
* Creates a glider pattern that is then reflected on game board, accepts 
* starting position specified by user. 
*
***************************************************************************/
void GOL::setGlider(int strt)
{
    golMap[position + 0][position + 1] = alive;
    golMap[position + 1][position + 2] = alive;
    golMap[position + 2][position + 0] = alive;
    golMap[position + 2][position + 1] = alive;
    golMap[position + 2][position + 2] = alive;
}


/**************************************************************************
* 			GOL::setOscillators()
* Creates a oscillator pattern that is then reflected on game board
*
***************************************************************************/
void GOL::setOscillator(int strt)
{
    golMap[position + 1][position + 1] = alive;
    golMap[position + 1][position + 2] = alive;
    golMap[position + 2][position + 1] = alive;
    golMap[position + 2][position + 2] = alive;
    golMap[position + 3][position + 3] = alive;
    golMap[position + 3][position + 4] = alive;
    golMap[position + 4][position + 3] = alive;
    golMap[position + 4][position + 4] = alive;
}

/**************************************************************************
* 			GOL::setBigGuns()
* Creates a glider pattern that is then reflected on game board
*
************************************************************************* */
void GOL::setBigGuns(int strt)
{
// Square block left-side
    golMap[position + 5][position + 1] = alive;
    golMap[position + 6][position + 1] = alive;
    golMap[position + 5][position + 0] = alive;
    golMap[position + 6][position + 0] = alive;
// First figure
    golMap[position + 5][position + 10] = alive;
    golMap[position + 6][position + 10] = alive;
    golMap[position + 7][position + 10] = alive;
    golMap[position + 4][position + 11] = alive;
    golMap[position + 8][position + 11] = alive;
    golMap[position + 3][position + 12] = alive;
    golMap[position + 9][position + 12] = alive;
    golMap[position + 3][position + 13] = alive;
    golMap[position + 9][position + 13] = alive;
    golMap[position + 6][position + 14] = alive;
    golMap[position + 4][position + 15] = alive;
    golMap[position + 8][position + 15] = alive;
    golMap[position + 5][position + 16] = alive;
    golMap[position + 6][position + 16] = alive;
    golMap[position + 7][position + 16] = alive;
    golMap[position + 6][position + 17] = alive;
//Second Figure
    golMap[position + 3][position + 20] = alive;
    golMap[position + 4][position + 20] = alive;
    golMap[position + 5][position + 20] = alive;
    golMap[position + 3][position + 21] = alive;
    golMap[position + 4][position + 21] = alive;
    golMap[position + 5][position + 21] = alive;
    golMap[position + 2][position + 22] = alive;
    golMap[position + 6][position + 22] = alive;
    golMap[position + 1][position + 24] = alive;
    golMap[position + 2][position + 24] = alive;
    golMap[position + 6][position + 24] = alive;
    golMap[position + 7][position + 24] = alive;    
//Square block right-side
    golMap[position + 3][position + 34] = alive;
    golMap[position + 4][position + 34] = alive;
    golMap[position + 3][position + 35] = alive;
    golMap[position + 4][position + 35] = alive; 
}

/**************************************************************************
*				Pattern::showOptions
* This function displays the options for patterns that the user is allowed
* to choose to intialize the GOL. 				
*
***************************************************************************/
void GOL::showOptions()
{
    system("clear");  // clears screen
    cout << "Please select the pattern you intend to start GOL with\n";
    cout << "1) Glider configuration\n";
    cout << "2) Fixed Oscillator configuration\n";
    cout << "3) Glider Gun configuration\n";
    cout << "4) Suspend program activities\n"; 
}


/**************************************************************************
*				Pattern::getOption
* This function takes input and returns users selected option
*
*
***************************************************************************/
int GOL::getOption()
{
    int choice;
    cin >> choice;
    while(choice < 1 || choice >4)
    {
	cout << "Please re-enter a value between 1-4. ";
        cin >> choice; 
    }
    return choice;
}

