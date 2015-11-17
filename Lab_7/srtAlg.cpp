/***************************************************************************** Author: Ryan Osborne
** Date: 11 12 2015
** Description: This program sorts the values in my 4 txt list and compares
***************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes
void selectionSort(int [], int);
void printArray(const int [], int);

int main(){
    const int SIZE = 20;
    string fileName;
    string newFileName;
    ifstream inFile;
    ofstream outFile;
    int value = 0;
    int srtArray[SIZE]; 
    int i = 0;
    int xer = -5;
    // File must be formatted with spaces between integers
    // User enters file selection
    cout << "What file would you like to sort.\n";
    cin >> fileName;

    // Open file
    inFile.open(fileName.c_str(), ios::in);
    if(!inFile){
	cout << "The file was not found\n";
	return 1;
    }

    // Read and print every value already in the file
    while(inFile >> srtArray[i]){
	    i++; 
    }

    // Display values of array
    cout << "The unsorted values are:\n";
    printArray(srtArray, SIZE);

    // Sort the array
    selectionSort(srtArray, SIZE);

    
    // Display values of array
    cout << "The sorted values are:\n";
    printArray(srtArray, SIZE);
    
    // Allow user to name file to write the newly sorted values to
    cout << "Please enter new file name for sorted values.\n";
    cin >> newFileName;

    // Open file to allow for modification
    outFile.open(newFileName.c_str(), ios::out);
    //if(newFileName.fail()){
    //	cout << "Cannot open output file: " << newFileName << endl;
    //	return 2;
   // }
    // Copy values into array
       for(int z = 0; z < SIZE; z++){
       outFile << srtArray[z] << " ";
      }
    
    // Close files
    inFile.close();
    outFile.close();
    return 0;
}
/*************************************************************************
*   selectionSort
*
**************************************************************************/
void selectionSort(int array[], int size){
    int startScan,
	minIndex, 
	minValue;

    for(startScan = 0; startScan < (size-1); startScan++){
	minIndex = startScan;
	minValue = array[startScan];
	for(int index = startScan +1; index<size; index++){
	    if(array[index] < minValue){
		minValue = array[index];
		minIndex = index;
	    }
        }
	array[minIndex] = array[startScan];
	array[startScan] = minValue;
     }
}

/*************************************************************************
* printArray
*
 **************************************************************************/
void printArray(const int array[] , int size){
    for(int i = 0; i < size; i++){
	cout << array[i] << " ";
    }
    cout << endl;
}
