//
//  List.hpp is a List class specification file
//  Assignment2
//
//  Created by Ryan Osborne on 10/23/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include "Items.hpp"
#include <vector>
#include <string>
using std::vector;
using std::string;
// #include <stdio.h> (see why this was added)
class List{
protected:
    // No additional items required 
public:
    void fillList(vector<Items>&);
    void printList(vector<Items>&);
    void removeItem(vector<Items>&);
    void printTotal(vector<Items>&);
};



#endif /* List_hpp */
