//
//  main.cpp
//  Linked_List
//
//  Created by Ryan Osborne on 11/4/15.
//  Copyright © 2015 Ryan Osborne. All rights reserved.
//

#include <iostream>
#include "singleLink.hpp"

int main() {
    StackNode* creator = new StackNode;
    
    // Test 1
    /*
    creator->add(5);
    creator->add(90);
    creator->printLinkList();
    std::cout << std::endl;
    std::cout << creator->remove() << std::endl;
    std::cout << creator->remove() << std::endl;
    std::cout << "This is the second time I am printing my linked list\n";
    creator->printLinkList();
    std::cout << std::endl;
    */
    
    // Test 2
    creator->add(5);
    creator->add(90);
    creator->add(45.3);
    creator->printLinkList();
    std::cout << std::endl;
    std::cout << creator->remove() << std::endl;
    std::cout << creator->remove() << std::endl;
    creator->add(63.2);
    creator->add(78.9);
    std::cout << "This is the second time I am printing my linked list.\n" << std::endl;
    creator->printLinkList();
    std::cout << std::endl;    std::cout << creator->remove() << std::endl;
    std::cout << creator->remove() << std::endl;
    std::cout << creator->remove() << std::endl;
    creator->add(105.4);
    creator->add(23.2);
    std::cout << "This is the third time I am printing my linked list.\n" << std::endl;
    creator->printLinkList();
    std::cout << std::endl;

    return 0;
}
