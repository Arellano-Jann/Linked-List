#include "../headers/List.h"
#include "../headers/Node.h"
#include <iostream>
#include <string>

int main(){
    bool exit = false;
    List<std::string>* toDoList = new List<std::string>;
    while(!exit){

        int selection = 0;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Complete Task" << std::endl;
        std::cout << "3. Display List" << std::endl;
        std::cout << "4. Complete List" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> selection;

        int paramOne;
        std::string paramTwo;
        switch (selection){
            case 1: // add task - insert node. Priority level (position), string object of task
                std::cout << "Task priority?" << std::endl;
                std::cin >> paramOne;
                std::cout << "Task name?" << std::endl;
                std::cin >> paramTwo;
                if (toDoList->insert(paramOne, paramTwo)){
                    std::cout << "in the insert. 1" << std::endl;
                }
                break;
            case 2: // complete task - remove node at position.
                break;
            case 3: // display list - iterate through list and getEntry()
                std::cout << "in the 3" << std::endl;
                for (int i = 0; i < toDoList->getLength(); i++){
                    std::cout << i+1 << '.' << toDoList->getEntry(i+1) << std::endl;
                }
                break;
            case 4: // complete list - clear list
                break;
            case 5: // exit - clear list. use the destructor
                std::cout << "Yay you made it out!" << std::endl;
                exit = true;
                break;
        }
    }
    return 0;
}

