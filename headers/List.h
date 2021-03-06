#pragma once
#define LIST_H

#include "ListInterface.h"
#include "Node.h"
#include <iostream>

template <typename T>
class List : public ListInterface<T>{
    int itemCount = 0;
    Node<T>* headPtr;
    Node<T>* getNodePtr(int position) const;
    bool checkValidity(int position) const;

public:
    List();

    bool isEmpty() const override;
    int getLength() const override;
    bool insert(int newPosition, const T& newEntry) override; // inserts newEntry at newPosition
    bool remove(int position) override; // removes entry at position
    void clear() override; // calls remove "getLength" times
    T getEntry(int position) const override;
    T replace(int position, const T& newEntry) override; // replaces position with newEntry
    ~List();
    
};


// add new task
// delete task
// show all tasks
// remove all tasks
// exit program/to do list
#include "../src/List.cpp"