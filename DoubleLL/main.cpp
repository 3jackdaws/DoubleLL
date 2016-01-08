//
//  main.cpp
//  DoubleLL
//
//  Created by Ian Murphy on 1/6/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    DoubleLinkedList<int> * list = new DoubleLinkedList<int>;
    
    list->Prepend(100);
    list->Append(70);
    list->Append(80);
    
    list->PrintForwards();
    list->PrintBackwards();
    //list->Extract(70);
    cout<<"\n\n\n";
    list->PrintForwards();
    list->PrintBackwards();
    list->InsertAfter(111, 100);
    list->PrintForwards();
    list->PrintBackwards();
    cout<<"\n";
    list->InsertAfter(112, 80);
    list->PrintForwards();
    list->PrintBackwards();
    cout<<"\n";
    list->InsertAfter(113, 80);
    list->PrintForwards();
    list->PrintBackwards();
    cout<<"\n\n\n";
    list->InsertBefore(1000, 100);
    list->InsertBefore(1000, 80);
    list->PrintForwards();
    list->PrintBackwards();
    
    *list = *list;

    list->PrintForwards();
    list->PrintBackwards();
    
    delete list;
    
    return 0;
}
