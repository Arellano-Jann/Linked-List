#include "../headers/List.h"
#include "../headers/Node.h"
#include <iostream>
#include <string>

int main(){
    bool exit = false;
    while(!exit){

        int selection = 0;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Complete Task" << std::endl;
        std::cout << "3. Display List" << std::endl;
        std::cout << "4. Complete List" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> selection;

        List<std::string> toDoList;

        int paramOne;
        std::string paramTwo;
        switch (selection){
            case 1: // add task - insert node. Priority level (position), string object of task
                std::cout << "Task priority?" << std::endl;
                std::cin >> paramOne;
                std::cout << "Task name?" << std::endl;
                std::cin >> paramTwo;
                if (toDoList.insert(paramOne, paramTwo)){
                    std::cout << "shit";
                }
                break;
            case 2: // complete task - remove node at position.
                break;
            case 3: // display list - iterate through list and getEntry()
                for (int i = 0; i < toDoList.getLength(); i++){
                    std::cout << toDoList.getEntry(i) << std::endl;
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

