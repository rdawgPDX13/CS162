/***************************************************************************** Author: Ryan Osborne
** Date: 09252015
** Description: Used to test class Die
***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"
using std::cout;
using std::cin;
using std::endl;
int main()
{
   int  nmSides,
        numRolls,
	sum = 0,
	sumLoad = 0,
        p1,
	p2,
	die4P1,
	die4P2,
	winP1=0,
	winP2=0,
	tie=0;
   float average,
	 averageLoad;
    unsigned seed = time(0);
    srand(seed);

    // Prompt user to enter an amount of die sides
    std::cout << "Please enter the number of sides on the die.\n";
    std::cin >> nmSides;
    // Input validation for number of sides
    while(nmSides < 2)
    {
	cout << "Please enter a die side value greater than 1!" << endl;
	cin >> nmSides;
    } 

    // Prompt user for what die for player 1 and 2
    cout << "If you would like regular die [Enter] '1'" << endl;
    cout << "If you would like to select LoadedDie [Enter] '2'" << endl;
    cout << "Select what die you would like for player 1 and player 2\n";
    cin >> die4P1 >> die4P2;
    
    // Input validation for player 1 
    while((die4P1 != 1) && (die4P1 !=2))
    {
	cout << "Error for Player 1: Enter [1] for regular die, " 
	     << "or enter [2] for loaded die: " << endl;
        cin >> die4P1;
    }

    // Input validation for player 2
    while((die4P2 != 1) && (die4P2 !=2))
    {
	cout << "Error for Player 2: Enter [1] for regular die, " 
	     << "or enter [2] for loaded die: " << endl;
        cin >> die4P2;
    }

    // Prompt user to enter an amount of rolls requested
    std::cout << "Please the number of die rounds requested.\n";
    std::cin >> numRolls;
    
    // Input validation
    while(numRolls < 1)
    {
	cout << "Please enter a number greater than one!" << endl;
	cin >> numRolls;
    } 
    // Pass by value the number of user inputted sides
    Die roller(nmSides);
    LoadedDie hiRoller(nmSides);
    Game player1(numRolls, nmSides);
    Game player2(numRolls, nmSides);
    
    // Header for table of results
    std::cout << "Fair Die\t" << "Loaded Die\t" << "Total Rolls\n";
    
    // Loop through to simulate rolls of die and cout results
    // If/else if to allow user to select die used
    for(int rll = 1; rll <= numRolls; rll++)
    {
        if(die4P1 == 1)
	{   // Regular Die
	    p1 = player1.getDie();
	}
        else if(die4P1 ==2)
	{   // Loaded Die
	    p1 = player1.roll();
	}

        if(die4P2 == 1)
	{   // Regular Die
	    p2 = player2.getDie();
	}
        else if(die4P2 == 2)
	{   // Loaded Die
	    p2 = player2.roll();
	}

        std::cout << p1 << "\t\t" << p2 << "\t\t" << rll 
                  << std::endl;
        sum += p1;
        sumLoad += p2;

	if(p1 > p2)
        {
	    winP1++;
	}
        else if(p1 < p2)
	{
	    winP2++;
	}
        else if(p1 == p2)
	{
	     tie++;
	}
    }

    // Repeated the header for ease in view of categories 
    std::cout << "Fair Die\t" << "Loaded Die\t" << "Total Rolls\n";

    // Calculate averages for die and loaded die
    average = static_cast<double>(sum) / numRolls;
    averageLoad = static_cast<double>(sumLoad) /numRolls;
   
    // Create a space between results
    std::cout << "" << std::endl;
   
    // Display averages for die and loaded die
    std::cout << "The average value rolled was: " << average << std::endl; 
    std::cout << "The loaded average value rolled was: "
              << averageLoad << std::endl; 

    // Win Tallys
    cout << "Wins for Player 1: " << winP1 << endl;
    cout << "Wins for Player 2: " << winP2 << endl;
    cout << "Ties between the two: " << tie << endl;
    return 0;
}
