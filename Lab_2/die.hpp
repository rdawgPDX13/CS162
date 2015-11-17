/***************************************************************************** Author: Ryan Osborne
** Date: 09242015
** Description: die.hpp is the die class specification file
***************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

// Die class declaration
class Die
{   // Modify the private access specification to protected inheritance
    protected:
	int numDieSides;
    public:
	Die(int);	// Default constructor  
	int roll();
};
#endif
