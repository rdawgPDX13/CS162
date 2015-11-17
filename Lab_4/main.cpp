//
//  main.cpp
//  mainRecursive
//
//  Created by Ryan Osborne on 10/22/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//Prototypes
string reverse(string);
int sumArray(int [], int);
int triangular(int);

int main() {
    // Variables
    int option,
        numElements,
        value = 0,
        numRows,
        triangleVal;
    string entered;
    do
    {
        // Display options
        cout << " Recursive Functions Menu" << endl;
        cout << "1) Reverse that string\n";
        cout << "2) Add that array\n";
        cout << "3) Tell me my triangular number\n";
        cout << "4) Select to quit program\n";
        cin >> option;
        
        // Check user input
        while((option <1) || (option > 4))
        {
            cout << "Error entering selection"
            << " please enter integer (1-4)" << endl;
            cin >> option;
        }
        if(option == 1){
            // Prompt user for a string
            cout << "Please enter a string, and I will"
            << " magically reverse it!\n";
            //getline(cin, entered);
            cin >> entered;
            cout << "Is this your string reversed? "
            << entered << endl;
            cout << "Well how about this one...\n";
            // Pass the string into the reverse function
            string printOut = "";
            printOut = reverse(entered);
            //reverse(entered);
            cout << "After function is called\n";
            cout << printOut << endl;
        }
        if(option == 2){
            cout << "Please enter an integer value for"
            << " the number of elements you"
            << " wish to include in your array.\n";
            cin >> numElements;
            while(numElements < 0){
                cout << "Error enter a positive integer\n";
                cin >> numElements;
            }
            int array[numElements];
            for(int i = 0; i< numElements; i++){
                cout << "Enter value " << (i+1)
                << " for array:\n";
                cin >> value;
                array[i] = value;
            }
            // Call Function
            int sumOfValues = 0;
            sumOfValues = sumArray(array, numElements);
            cout << "Sum of the array values: " << sumOfValues
            << endl;
         }
                    
        if(option == 3){
            cout << "Please enter number of rows and"
            << " we will calculate your"
            << " traingular number(number of pins)" << endl;
            cin >> numRows;
            // Call Function
            triangleVal = triangular(numRows);
            cout << "Number of rows: " << numRows
            << " corresponding triangle value: "
            << triangleVal << "." << endl;
        }
    } while(option !=4);
    return 0;
}

/*************************************************************************
*
*
**************************************************************************/
string reverse(string uEntered){
    string newline = "\n";
    string toBeReversed;
    int stringLength;
    
    //cout << "uEntered: " << uEntered << endl;
    // Add the newline value to the function
    toBeReversed = newline + uEntered;
    
    // To test basecase
    //toBeReversed = uEntered + newline;
    stringLength = toBeReversed.length();
    
    if(stringLength == 0)
	return newline;
    else{
        stringLength--;
	return reverse(uEntered) + toBeReversed.at(stringLength-1);
      
    }


    /*
    if(stringLength == 0){
        cout << "Done\n";
    }
    else{
        cout << toBeReversed[stringLength -1];
        stringLength--;
        return reverse(uEntered);
    } */
    }

/*************************************************************************
*
*
**************************************************************************/
int sumArray(int val[], int elements)
{
    if(elements == 0){
        return 0;
    }
    else{
        return sumArray(val, (elements -1)) + val[elements-1];
    }
}

/*************************************************************************
*
*
**************************************************************************/
int triangular(int rows){
    if(rows == 0){
        return 0;
    }
    else{
        return triangular(rows -1) + rows;
    }
}



