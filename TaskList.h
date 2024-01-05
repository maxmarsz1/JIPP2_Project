#pragma once
#include <vector>
#include "Task.h"
#include <map>

using namespace std;

class TaskList{
    map<int, Task> *tasks = new map<int, Task>;
    int lastId = 0;

public:
    void addTask(string text);
    void removeTask(int id);
    Task* getTask(int id);
    map<int, Task>* getTasks();
};