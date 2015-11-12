/***************************************************************************** Author: Ryan Osborne
** Date: 09252015	
** Description: loadDie.hpp is a Loaded die class speficication file
***************************************************************************/
#ifndef LOADDIE_HPP
#define LOADDIE_HPP

// Loaded Die class declaration
class LoadedDie
{
    private:
	int numLoadedDieSides;  // Keeps track of sides
    public:
	LoadedDie(int);  // Default constructor
	int hiRoll();
};
#endif
