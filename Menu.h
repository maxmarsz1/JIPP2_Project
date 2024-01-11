#pragma once
#include "TaskList.h"


class Menu{
    TaskList taskList; 
public:
    Menu();
    void menu();
    void menuTasks();

    enum Option {
        Display = 1,
        Add,
        Exit = 0
    };

    enum OptionTask {
        Toggle = 1,
        Edit,
        Remove, 
        Back
    };

};