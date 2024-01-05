#pragma once
#include "TaskList.h"


class Menu{
    TaskList taskList; 
public:
    Menu();
    void print();

    enum Option: unsigned int {
        Display = 1,
        Add,
        Remove,
        Exit
    };

};