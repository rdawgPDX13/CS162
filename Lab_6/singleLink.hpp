//
//  singleLink.hpp
//  Linked_List
//
//  Created by Ryan Osborne on 11/4/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#ifndef SINGLELINK_HPP
#define SINGLELINK_HPP

#include <stdio.h>

class StackNode{
protected:
    double value;
    StackNode* lower;
    StackNode* top;
public:
    StackNode();
    //StackNode(double val, StackNode* nextNode = NULL);
    ~StackNode();
    void add(double);
    double remove();
    void printLinkList();
};




#endif /* singleLink_hpp */
