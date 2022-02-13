#include "../headers/List.h"
#include "../headers/Node.h"
#include <iostream>
#include <string>

int main(){
    bool exit = false;
    while(!exit){
        int selection = 0;
        List<std::string> toDoList;
        switch (selection){
            case 1: // add task - insert node. Priority level (position), string object of task
                std::cout << 
                toDoList.insert(1, "task 1");
                break;
            case 2: // complete task - remove node at position.
                break;
            case 3: // display list - iterate through list and getEntry()
                break;
            case 4: // complete list - clear list
                break;
            case 5: // exit - clear list. use the destructor
                break;
        }
    }
    return 0;
}

