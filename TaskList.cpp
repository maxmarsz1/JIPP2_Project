#include "TaskList.h"
#include "Task.h"
#include <stdexcept>
#include <string>
#include <map>
#include <iostream>

using namespace std;

void TaskList::addTask(string text){
    tasks->insert({++lastId, Task(text)});
}

Task* TaskList::getTask(int id){
    try {
        Task* t = &tasks->at(id);
        return t;
    } catch (out_of_range) {
        cout << "Podany adres nie istnieje" << endl;
        return nullptr;
    }
}

map<int, Task>* TaskList::getTasks(){
    return tasks;
}