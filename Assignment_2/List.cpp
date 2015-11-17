//
//  List.cpp is a List class function implementation file
//  Assignment2
//
//  Created by Ryan Osborne on 10/23/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <locale>
#include "Items.hpp"
#include "List.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::showpoint;
using std::setprecision;

/*************************************************************************
*			List::fillList
* This function takes a vector of Items passed by reference and assigns the 
* corresponding variables to the vector of Items object
**************************************************************************/
void List::fillList(vector<Items>& newList){
    char again;
    string item;
    string unit;
    int qty;
    double cost;
    double price;
    do
    {
        cout << "Create Grocery list items\n";
        cout << "Enter grocery item name:\n";
        getline(cin, item);
        cout << "Enter unit(can, box, pounds, ounces:\n";
        getline(cin, unit);
        cout << "Enter quantity of the item:\n";
        cin >> qty;
        cout << "Enter the cost per item:\n";
        cin >> cost;
        price = cost* qty;
        Items addItems(item, unit, qty, cost, price);
        newList.push_back(addItems);
        cout << endl;
        cout << "Do you want to play a game? (Y/N) " << endl;
        cin >> again;
        cin.ignore();
    }while(toupper(again) == 'Y');
    cout << endl;
    
}
/*************************************************************************
*			List::printList
* This function calls and prints out the Items object within the List
*
**************************************************************************/
void List::printList(vector<Items>& newList){
    for(int i =0; i < newList.size(); i++){
        cout << "Item name: " << newList[i].getItem();
        cout << " units: " << newList[i].getUnit();
        cout << " quantity: " << newList[i].getQty();
	cout << fixed << showpoint << setprecision(2);
        cout << " cost: $" << newList[i].getCost();
        cout << " price: $" << newList[i].getPrce() << endl;
    }
}

/*************************************************************************
*			List::removeItem
* This functions allows the user the ability to remove items from their 
* list by entering which item they woudl like to remove. 
*
**************************************************************************/ 
void List::removeItem(vector<Items>& newList){
    char again;
    int remover;
    do{
	cout << "Would you like to remove an item from your list?\n";
	cout << "If so which item number? Or enter letter to skip.\n";
	cin >> remover;
        newList.erase(newList.begin() + (remover -1));
	cout << "Do you want to erase another? (Y/N)\n";
        cin >> again;
    }while(toupper(again) == 'Y');
}

/*************************************************************************
*		List::printTotal
* This function provideds a totaled amount of for the grocery items on the
* list. 
*
**************************************************************************/
void List::printTotal(vector<Items>& newList){
    static double total= 0;
    for(int i = 0; i < newList.size(); i++){
	total += newList[i].getPrce();
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "Total price of groceries: $" << total << endl;
}
