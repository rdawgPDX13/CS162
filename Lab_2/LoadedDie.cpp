/*********************************************************************
 ** Program Filename: LoadedDie.cpp
 ** Date: October 1, 2015 / Modified: 10 14 2015
 ** Description: A die whose number of sides can be set, which generates
 ** rolls that are higher than a fair die.
 *********************************************************************/
#include "LoadedDie.hpp"
#include "die.hpp"
/*********************************************************************
 ** Function: LoadedDie(int x)
 ** Description: Constructs a LoadedDie with the given number of sides,
 ** and sets the random seed with the current time.
 ** Parameters: x - the number of sides
 *********************************************************************/ 
LoadedDie::LoadedDie(int numDieSides): Die(6)
{
    this->numDieSides = numDieSides;
} 

/*********************************************************************
 ** Function: roll()
 ** Description: Returns the result of rolling the die.
 ** Pre-Conditions: The random seed is set with srand().
 *********************************************************************/ 
int LoadedDie::roll()
{
    return int(std::sqrt(rand() % (numDieSides * numDieSides))) + 1;

}
