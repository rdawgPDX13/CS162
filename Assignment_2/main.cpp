//
//  main.cpp
//  new_things
//
//  Created by Ryan Osborne on 10/26/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//




#include <iostream>
#include <iomanip>
#include <vector>
#include "Items.hpp"
#include "List.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::showpoint;
using std::setprecision;
using std::vector;



int main(){
    //Instantiate object so Items
    Items a;
    Items b;
    // Instantiate a vector of Items objects 
    vector<Items> myList;
    // Instantiatie an object of List
    List gList;
    // Fill List with vector of Items objects
    gList.fillList(myList);
    // Print intial objects
    gList.printList(myList);
    // Allow user to remove whichever items for the list
    gList.removeItem(myList);
    // Print the final list
    gList.printList(myList);
    // Print the total value of the grocery items list
    gList.printTotal(myList);

    // Test the (==) operator overloading
    if(a==b) cout << "You entered an item that was a duplicate!" << endl;
    else cout << "False all items are different!" << endl;
    return 0;
}


