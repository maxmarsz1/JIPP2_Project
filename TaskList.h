#pragma once
#include <vector>
#include "Task.h"
#include <map>

using namespace std;

class TaskList{
    map<int, Task*> tasks;

public:
    int lastId = 0;
    ~TaskList();
    void addTask(string text);
    void addTask(Task* task);
    void removeTask(int id);
    Task* getTask(int id);
    map<int, Task*> getTasks();
    void save(string filename);
    void save(ofstream &out);
    void load(string filename);
    void load(ifstream &in);
};
