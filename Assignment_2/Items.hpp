//
//  Items.hpp is the Items class specification file
//  Assignment2
//
//  Created by Ryan Osborne on 10/23/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#ifndef Items_hpp
#define Items_hpp
#include <stdio.h>
#include <iostream>

using std::string;

class Items{
protected:
    // Member Variables
    string newItem;
    string itemUnit;
    int itemQty;
    double itemCost;
    double itemPrce;

public:
    Items(); // Default Constructor
    Items(string, string, int, double, double); // Overloaded constructor
    void setItem(string);
    string getItem(); 
    void setUnit(string);
    string getUnit(); 
    void setQty(int);
    int getQty();
    void setCost(double);
    double getCost(); 
    void setPrce(double);
    double getPrce();
    friend bool operator==(Items, Items);
};


#endif /* Items_hpp */
