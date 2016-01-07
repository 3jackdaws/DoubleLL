//
//  DoubleLinkedList.hpp
//  DoubleLL
//
//  Created by Ian Murphy on 1/6/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//


#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <iostream>
#include "LLNode.hpp"

template <typename T>
class DoubleLinkedList
{
public:
    
    bool isEmpty();
    const T& First() const;
    const T& Last() const;
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
    
    DoubleLinkedList();
    ~DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList<T> &);
    DoubleLinkedList<T> & operator = (const DoubleLinkedList<T> &);
    
    //data members
    
    LLNode<T> * _head;
    LLNode<T> * _tail;
    
private:
    LLNode<T> & Find(T);
    
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : _head(nullptr), _tail(nullptr)
{
    
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Purge();
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> & cp)
{
    LLNode<T> * travel = _head;
    while(travel != nullptr)
    {
        Append(travel->_data);
        travel = travel->_next;
    }
}

template <typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> & rhs)
{
    Purge();
    LLNode<T> * travel = rhs._head;
    while(travel != nullptr)
    {
        Append(travel->_data);
        travel = travel->_next;
    }
    return *this;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
    if(_head == nullptr)
        return true;
    return false;
}

template <typename T>
const T & DoubleLinkedList<T>::First() const
{
    return _head->_data;
}

template <typename T>
const T & DoubleLinkedList<T>::Last() const
{
    return _tail->_data;
}

template <typename T>
void DoubleLinkedList<T>::Prepend(T data)
{
    LLNode<T> * old_head = _head;
    _head = new LLNode<T>(data);
    _head->_next = old_head;
    if(_tail == nullptr)
    {
        _tail = _head;
    }
}

template <typename T>
void DoubleLinkedList<T>::Append(T data)
{
    if(_tail != nullptr)
    {
        _tail->_next = new LLNode<T>(data);
        _tail->_next->_prev = _tail;
        _tail = _tail->_next;
    }
    else
    {
        Prepend(data);
    }
    
}

template <typename T>
void DoubleLinkedList<T>::Purge()
{
    LLNode<T> * travel = _head;
    if(_head != nullptr && _head->_next != nullptr)
    {
        travel = travel->_next;
        while(travel != nullptr)
        {
            delete travel->_prev;
            travel = travel->_next;
        }
        delete _tail;
        _head = nullptr;
        _tail = nullptr;
    }
    else
        delete _head;
}

template <typename T>
T DoubleLinkedList<T>::Extract(T data)
{
    
    LLNode<T> * travel = _head;
    while (travel != nullptr && travel->_data != data)
    {
        travel = travel->_next;
    }
    if(travel)
    {
        if(travel == _head)
            _head = travel->_next;
        else if(travel == _tail)
            _tail = travel->_prev;
        else{
            travel->_prev->_next = travel->_next;
            travel->_next->_prev = travel->_prev;
        }
        delete travel;
    }
    else
        throw "Data not found within list";
    return data;
}


template <typename T>
void DoubleLinkedList<T>::InsertAfter(T put, T find)
{
    LLNode<T> * travel = _head;
    while (travel != nullptr && travel->_data != find)
    {
        travel = travel->_next;
    }
    if(travel)
    {
        if(travel == _head)
            _head = travel->_next;
        else if(travel == _tail)
            _tail = travel->_prev;
        else{
            travel->_prev->_next = travel->_next;
            travel->_next->_prev = travel->_prev;
        }
        delete travel;
    }
    else
        throw "Data not found within list";
}

template <typename T>
void DoubleLinkedList<T>::PrintForwards()
{
    LLNode<T> * travel = _head;
    while (travel != nullptr) {
        std::cout<<travel->_data<<std::endl;
        travel = travel->_next;
    }
}



#endif /* DoubleLinkedList_hpp */
