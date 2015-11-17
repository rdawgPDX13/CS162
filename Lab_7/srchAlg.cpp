/***************************************************************************** Author: Ryan Osborne
** Date: 11 12 2015
** Description: This program searches for target value in data files
***************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototype function
int searchList(const int [], int, int);

int main(){
    const int SIZE = 20;

    ifstream inOutFile;
    string fileName;
    int value;
    int srchArray[SIZE];
    int i =0;
    int result;

    // File must be formatted with spaces between integers
    // Get file name from user
    cout << "Please enter the file name for the file to be accessed.\n";
    cin >> fileName;


    // Open file
    inOutFile.open(fileName.c_str(), ios::in);
    if(!inOutFile){
	cout << fileName << " could not be found\n";
	return 1;
    }

    // Read and print every value already in the file
    while(inOutFile >> srchArray[i]){
	    i++; 
    }

    result = searchList(srchArray, SIZE, 0);

    /// If searchList returns -1, 0 not found
    if(result == -1)
	cout << "You did not find the magic value '0'.\n";
    else{
	cout << "You found '0' in my list! @ pos: " << (result +1) << ".\n";
    }

    // Clear end of file flag to allow additional file operations
    //inOutFile.clear();

    // Write a value to the file and close the file
    // inOutFile << 1000 << endl;
    inOutFile.close();

    return 0;
}

/*************************************************************************
*				searchList
* This function performs a linear search on an integer array.
* This list txt file. 
* If number is found. Otherwise, -1 returned.
**************************************************************************/
int searchList(const int list[], int size, int val){
    int index = 0;
    int position = -1;
    bool found = false;

    while(index <size && !found){
	if( list[index] == val){
	    found = true;
	    position = index;
	}
	index++;
    }
    return position;
}

