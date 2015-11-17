/***************************************************************************** Author: Ryan Osborne
** Date: 11 12 2015
** Description: This program searches for target value in data files
***************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
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

    // User enters value selection
    cout << "Enter a file name: \n";
    cin >> fileName;

    // Open file
    inOutFile.open(fileName.c_str(), ios::in);
    if(inOutFile.fail()){
	cout << inOutFile <<  " file was not found\n";
	return 1;
    }

    // Read and print every value already in the file
    while(inOutFile >> srchArray[i]){
	    i++; 
    }

    cout << "Enter a number you wish to search for: ";
    cin >> value;

    result = searchList(srchArray, SIZE, value);

    /// If searchList returns -1, 0 not found
    if(result == -1)
	cout << "You did not find the magic value: " << value << ".\n";
    else{
	cout << "Value: " << value << " was found in element "
             << result <<  " of the text file.\n";
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
    int first = 0;
    int last =size -1;
    int middle;
    int position = -1;
    bool found = false;

    while(!found && first <=last){
	middle = (first + last)/2;
	if( list[middle] == val){
	    found = true;
	    position = middle;
	}
	else if(list[middle] > val)
	    last = middle -1;
 	else
	    first = middle +1;
    }
    return position;
}

