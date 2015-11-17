/***************************************************************************** Author: Ryan Osborne
** Date: 10 15 2015
** Description: Game.hpp is a specification file for Game class
***************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "LoadedDie.hpp"
class Game : public LoadedDie
{
    private:
	int numRds;
    public:
        Game(int, int);
        int getDie(); 	
};

#endif
