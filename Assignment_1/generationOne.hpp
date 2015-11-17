/***************************************************************************** Author: Ryan Osborne
** Date: 09292015
** Description: generationOne.hpp is the GenOne class specification file
***************************************************************************/
#ifndef GENERATIONONE_HPP
#define GENERATIONONE_HPP

// GenOne class declaration
class GOL
{
    private:
	int bdRows,
	    bdCols,
            pRows,
	    pCols,
            position,
	    lfPat;
        char dead,
	     alive;
        char** golMap;
    public:
	GOL(int, int, int, int, int);
        ~GOL();
        void nextGen();
        void printBoard();
        void setGlider(int);
        void setOscillator(int);
        void setBigGuns(int);
	void showOptions();
	int getOption(); 
};
#endif
