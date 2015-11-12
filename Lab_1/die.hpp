/***************************************************************************** Author: Ryan Osborne
** Date: 09242015
** Description: die.hpp is the die class specification file
***************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

// Die class declaration
class Die
{
    private:
	int numDieSides;
    public:
	Die(int);	// Default constructor  
	int regRoll();  
};
#endif
