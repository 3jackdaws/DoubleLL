//
//  main.cpp
//  DoubleLL
//
//  Created by Ian Murphy on 1/6/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    LinkedList<int> * list = new LinkedList<int>;
    
    list->Prepend(100);
    list->Append(70);
    list->Append(80);
    
    list->PrintForwards();
    delete list;
    
    return 0;
}
