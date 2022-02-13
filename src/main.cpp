#include "../headers/List.h"
#include "../headers/Node.h"
#include <iostream>
#include <string>

int main(){
    bool exit = false;
    List<std::string>* toDoList = new List<std::string>;
    while(!exit){

        int selection = 0;
        std::cout << std::endl << "Youkoso!" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Complete Task" << std::endl;
        std::cout << "3. Display List" << std::endl;
        std::cout << "4. Complete List" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> selection;

        
        int paramOne = 0;
        std::string paramTwo = "";
        
        switch (selection){
            case 1: { // add task - insert node. Priority level (position), string object of task
                std::cout << "Task priority?" << std::endl;
                std::cin >> paramOne;
                std::cout << "Task name?" << std::endl;
                paramTwo = "";
                std::cin >> paramTwo;
                if (toDoList->insert(paramOne, paramTwo)){
                    // std::cout << "in the insert. (1)" << std::endl;
                }
                break;
            }
            case 2:{ // complete task - remove node at position.
                std::cout << "Which task to remove?" << std::endl;
                std::cin >> paramOne;
                if (toDoList->remove(paramOne)){
                    // std::cout << "in the remove. (2)" << std::endl;
                }
                break;
            }
            case 3:{ // display list - iterate through list and getEntry()
                // std::cout << "in the 3" << std::endl;
                int listLength = toDoList->getLength();
                if (listLength == 0){
                    std::cout << "You completed all your tasks! So productive." << std::endl;
                    break;
                }
                for (int i = 0; i < listLength; i++){
                    std::cout << i+1 << ". " << toDoList->getEntry(i+1) << std::endl;
                }
                break;
            }
            case 4:{ // complete list - clear list
                toDoList->clear();
                std::cout << "You finished all your tasks! So productive." << std::endl;
                break;
            }
            case 5:{ // exit - clear list. use the destructor
                std::cout << "Yay you made it out!" << std::endl;
                exit = true;
                break;
            }
        }
    }
    return 0;
}

