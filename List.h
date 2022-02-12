

// show all tasks
// remove all tasks
// exit program/to do list

#pragma once
#define LIST_H

template <typename T>
class List{
    T item;
    List<T>* next;

public:
    List();
    void setItem(const T& anItem);
    void setNext(List<T>* nextPtr);

    bool isEmpty() const; 
    int getLength() const; 
    bool insert(int newPosition, const T& newEntry); // add new task
    bool remove(int position); // delete task
    void clear(); 
    T getEntry(int position) const;
    T replace(int position, const T& newEntry); 
    ~ListInterface() { } 

    
}

#include "List.cpp"