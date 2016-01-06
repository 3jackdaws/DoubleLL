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
#include "LLNode.hpp"

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
    void PrintForwards();
    void PrintBackwards();
    
    T& getHead();
    T& getTail();
    
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &);
    LinkedList<T> & operator = (const LinkedList<T> &);
    
    //data members
    
    LLNode<T> * _head;
    LLNode<T> * _tail;
    
};

template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr), _tail(nullptr)
{
    
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Purge();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & cp)
{
    LLNode<T> * travel = _head;
    while(travel != nullptr)
    {
        Append(travel->_data);
        travel = travel->_next;
    }
}

template <typename T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rhs)
{
    Purge();
    LLNode<T> * travel = rhs._head;
    while(travel != nullptr)
    {
        Append(travel->_data);
        travel = travel->_next;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    if(_head == nullptr)
        return true;
    return false;
}

template <typename T>
const T & LinkedList<T>::First()
{
    return _head->_data;
}

template <typename T>
const T & LinkedList<T>::Last()
{
    return _tail->_data;
}

template <typename T>
void LinkedList<T>::Prepend(T data)
{
    LLNode<T> * old_head = _head;
    _head = new LLNode<T>(data);
    _head->_next = old_head;
}

template <typename T>
void LinkedList<T>::Append(T data)
{
    _tail->_next = new LLNode<T>(data);
    _tail->_next->_prev = _tail;
    _tail = _tail->_next;
}

#endif /* LinkedList_hpp */