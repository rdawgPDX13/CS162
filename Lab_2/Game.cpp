/***************************************************************************** Author: Ryan Osborne
** Date: 10 15 2015
** Description: Game.cpp is the Game class function implementation file
***************************************************************************/
#include "Game.hpp"

/*************************************************************************
*				Game::Game
* This is a default constructor that intializes the pointer to numRds
* and numDieSides.
**************************************************************************/
Game::Game(int numRds, int numDieSides): LoadedDie(6)
{
    this->numRds = numRds;
    this->numDieSides = numDieSides;
}
/*************************************************************************
* 				Game:getDie
* This function returns an inherited function that produces a regular die
* roll as opposed to a loaded die. It gains access to an overridden 
* member function.				
*
**************************************************************************/
int Game::getDie()
{
    return Die::roll();
}
