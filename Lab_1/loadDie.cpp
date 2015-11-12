/***************************************************************************** Author: Ryan Osborne
** Date: 09262015
** Description: This is the implementation file for loaded die 
***************************************************************************/
#include "loadDie.hpp"
#include <cstdlib>

/**************************************************************************
*			LoadedDie:LoadedDoe
* This is a default constructor that passes a value of user determined size
* for the number of sides of a given die.			
*
***************************************************************************/
LoadedDie::LoadedDie(int sides)
{
    numLoadedDieSides = sides;
}

/**************************************************************************
*		      LoadedDie::hiRoll
* This function manipulates a random number to produce values larger than 
* its opponent the normal die. It does this by doubling the value if it 
* originally is smaller than or equal to have the value of number of sides
*
***************************************************************************/
int LoadedDie::hiRoll()
{
    
    int dieValue = rand() % numLoadedDieSides +1;
    if( dieValue <= (numLoadedDieSides/2))
    {
	return dieValue *2;
    }
    else
    {
	return dieValue;
    }
    //  return rand() % numLoadedDieSides + 1; to compare to regular die

}
