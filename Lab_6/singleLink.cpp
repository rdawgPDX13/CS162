//
//  singleLink.cpp
//  Linked_List
//
//  Created by Ryan Osborne on 11/4/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#include "singleLink.hpp"
#include <iostream>
/*************************************************************************
*			StackNode::StackNode()
* This is a default constructor to instantiate the top pointer
**************************************************************************/

StackNode::StackNode(){
    top = NULL;
}

/*************************************************************************
*			StackNode::add(double)
* This is a function that inserts a node into in the front of the linked 
* list
**************************************************************************/
void StackNode::add(double nodeVal){
    StackNode* temp = new StackNode;
    temp->value = nodeVal;
    std::cout << "Value entered by user: " << temp->value << std::endl;
    temp->lower = top;
    top = temp;
}

/*************************************************************************
*			StackNode::remove()
* This is a function that removes a value from the top of the linked list
**************************************************************************/
double StackNode::remove(){
    StackNode* temp;
    if(!top){
        std::cout << "The list has no values to remove!(-100)\n";
        return -100;
    }
    // Need to access node value then delete
    temp = top;
    top = top->lower;
    // Need to return node value as a double
    std::cout << "I am removing this value: ";
    return temp->value;
}

/*************************************************************************
*			StackNode::printLinkLlist()
* This is function print the node values within the linked list
**************************************************************************/
void StackNode::printLinkList(){
    StackNode* temp = top;
    if(!top){
        std::cout << "The list has no values to remove!\n";
    }
    else{
    std::cout << "These are the values within my linked list:\n";
    while(temp){
        std::cout << temp->value << " ";
        temp = temp->lower;
    }
    }
    std::cout << std::endl;
}

/*************************************************************************
*			StackNode::~StackNode()
* This is a deconstructor that frees the memory created by the new pointer
**************************************************************************/
StackNode::~StackNode(){
    StackNode* temp = top;
    while(temp !=NULL){
        StackNode* deleter = temp;
        deleter = deleter->lower;
        delete deleter;
    }
}
