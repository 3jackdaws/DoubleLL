//
//  LinkedList.hpp
//  DoubleLL
//
//  Created by Ian Murphy on 1/6/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
template <typename T>
class LinkedList
{
public:
    bool isEmpty();
    const T& First();
    const T& Last();
    void Prepend(T);
    void Append(T);
    void Purge();
    T Extract(T);
    void InsertAfter(T put, T find);
    void InsertBefore(T put, T find);
    
    T& getHead();
    T& getTail();
    
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &);
    LinkedList<T> & operator = (const LinkedList<T> &);
    
};

template <typename T>
LinkedList<T>::LinkedList()
{
    
}

#endif /* LinkedList_hpp */
