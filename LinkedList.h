// add new task
// delete task
// show all tasks
// remove all tasks
// exit program/to do list

#pragma once
#define LINKEDLIST_H

template <typename T>
class LinkedList{
    T item;
    LinkedList<T>* next;

public:
    LinkedList();
    void setItem(const T& anItem);
    void setNext(LinkedList<T>* nextPtr);

    
}