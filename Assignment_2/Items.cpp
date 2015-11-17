//
//  Items.cpp is the Items class function implementation file
//  Assignment2
//
//  Created by Ryan Osborne on 10/23/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#include "Items.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::fixed;
using std::showpoint;
using std::setprecision;

/*************************************************************************
*		Items::Items
* Default constructor intializes the itemQty and itemCost
**************************************************************************/
Items::Items(){
    itemQty = 0;
    itemCost = 0;
}
/*************************************************************************
*		Items::Items
* Overload constructor intializes the member variables to those values
* passed to them
**************************************************************************/
Items::Items(string itm, string unt, int q, double cst, double pc){
    newItem = itm;
    itemUnit = unt;
    itemQty = q;
    itemCost = cst;
    itemPrce = pc;
}
/*************************************************************************
*			Items::setItem
* This function assigns the string variable for item entered by user
**************************************************************************/
void Items::setItem(string itm){
    newItem = itm;
}

/*************************************************************************
*			Items::getItem
* This function returns the string variable of item entered by user
**************************************************************************/
string Items::getItem(){
    return newItem;
}

/*************************************************************************
*			Items::setUnit
* This function assigns the string variable for unit entered by user
**************************************************************************/
void Items::setUnit(string unt){
    itemUnit = unt;
}

/*************************************************************************
*			Items::getUnit
* This function returns the string variable of unit entered by user
**************************************************************************/
string Items::getUnit(){
    return itemUnit;
}

/*************************************************************************
*			Items::setQty
* This function assigns the int variable for quantity entered by user
**************************************************************************/
void Items::setQty(int q){
    itemQty = q;
}

/*************************************************************************
*			Items::getQty
* This function returns the int variable of quantity entered by user
**************************************************************************/
int Items::getQty(){
    return itemQty;
}

/*************************************************************************
*			Items::setCost
* This function assigns the double variable for cost entered by user
**************************************************************************/
void Items::setCost(double cst){
    itemCost = cst;
}

/*************************************************************************
*			Items::getCost
* This function returns the double variable of cost entered by user
**************************************************************************/
double Items::getCost(){
    return itemCost;
}

/*************************************************************************
*			Items::setPrce
* This function assigns the double variable for price entered by user
**************************************************************************/
void Items::setPrce(double pc){
    itemPrce = pc;
}

/*************************************************************************
*			Items::getPrce
* This function returns the double variable of price entered by user
**************************************************************************/
double Items::getPrce(){
    return itemPrce;
}

/*************************************************************************
*
*
**************************************************************************/
bool operator==(Items a, Items b){
    return a.getItem() == b.getItem();
}

