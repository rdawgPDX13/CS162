/***************************************************************************** Author: Ryan Osborne
** Date: 09252015
** Description: Used to test class Die
***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.hpp"
#include "loadDie.hpp"
int main()
{
   int  nmSides,
        numRolls,
	sum,
	sumLoad,
        rollValue,
	loadRll;
   float average,
	 averageLoad;
    unsigned seed = time(0);
    srand(seed);

    // Prompt user to enter an amount of die sides
    std::cout << "Please enter the number of sides on the die.\n";
    std::cin >> nmSides;

    // Prompt user to enter an amount of rolls requested
    std::cout << "Please the number of die rolls requested.\n";
    std::cin >> numRolls;
    
    // Pass by value the number of user inputted sides
    Die roller(nmSides);
    LoadedDie hiRoller(nmSides);

    // Header for table of results
    std::cout << "Fair Die\t" << "Loaded Die\t" << "Total Rolls\n";

    // Loop through to simulate rolls of die and cout results
    for(int roll = 1; roll <= numRolls; roll++)
    {
	rollValue = roller.regRoll();
        loadRll = hiRoller.hiRoll();
        std::cout << rollValue << "\t\t" << loadRll << "\t\t" << roll 
                  << std::endl;
        sum += rollValue;
        sumLoad += loadRll;
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
    return 0;
}
