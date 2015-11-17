/*********************************************************************
 ** Program Filename: LoadedDie.hpp
 ** Date: October 1, 2015
 ** Description: A die whose number of sides can be set, which generates
 ** rolls that are higher than a fair die.
 *********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <cstdlib>
#include <ctime>
#include <cmath>
#include "die.hpp"
class LoadedDie: public Die
{
    // Since it inherited the protected function from Die no other member
    // variables were required.
public:
    LoadedDie(int); // Default Constructor
    int roll();
};

#endif
