/***************************************************************************** Author: Ryan Osborne
** Date: 09252015
** Description: Die class function implementation file 
***************************************************************************/
#include "die.hpp"
#include <cstdlib>
/**************************************************************************
*			Die::Die
*	This is a default constructor that is passed a value to initializes
*	numDieSides to a user defined amount 
 *************************************************************************/
Die::Die(int sides)
{
    numDieSides = sides;
}

/**************************************************************************
*                      Die::regRoll
*        This function randomizes and returns a roll of a die              
**************************************************************************/
int Die::regRoll()
{
    // Now return the roll of a die
    return rand() % numDieSides + 1;
}





