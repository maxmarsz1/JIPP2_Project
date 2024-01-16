#pragma once
#include "TaskList.h"


class Menu{
    TaskList taskList; 
    int selectedTaskId = -1;
public:
    Menu();
    void menu();
    void menuTask();

    enum Option {
        Display = 1,
        Add,
        Save,
        Load,
        Exit = 0
    };

    enum OptionTask {
        Toggle = 1,
        Edit,
        Remove, 
        Back
    };

};
