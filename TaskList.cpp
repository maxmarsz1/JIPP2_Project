#include "TaskList.h"
#include "Task.h"
#include <stdexcept>
#include <string>
#include <map>
#include <iostream>

using namespace std;

void TaskList::addTask(string text){
    tasks[++lastId] = new Task(text);
}

Task* TaskList::getTask(int id){
    Task* t = tasks.at(id);
    return t;
}

map<int, Task*> TaskList::getTasks(){
    return tasks;
}