#pragma once
#define LIST_H

#include "ListInterface.h"
#include "Node.h"

template <typename T>
class List : public ListInterface<T>{
    int itemCount;
    Node<T>* headPtr;
    Node<T>* getNodePtr(int position);

public:
    List();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const T& newEntry); // inserts newEntry at newPosition
    bool remove(int position); // removes entry at position
    void clear(); // calls remove "getLength" times
    T getEntry(int position) const;
    T replace(int position, const T& newEntry); // replaces position with newEntry
    ~ListInterface();
    
};


// add new task
// delete task
// show all tasks
// remove all tasks
// exit program/to do list
#include "List.cpp"