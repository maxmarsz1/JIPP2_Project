#include "TaskList.h"
#include "Task.h"
#include <stdexcept>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

TaskList::~TaskList(){
    for(lastId; lastId>=0; lastId--){
        delete tasks[lastId];
        tasks.erase(lastId);
    }
}

void TaskList::addTask(string text){
    tasks[++lastId] = new Task(text);
}

Task* TaskList::getTask(int id){
    return tasks.at(id);
}

map<int, Task*> TaskList::getTasks(){
    return tasks;
}

void TaskList::removeTask(int id){
    Task* t = tasks.at(id);
    for(id;id<lastId;id++){
        tasks[id] = tasks[id+1];
    }
    tasks.erase(lastId);
    lastId--;
    delete t;
}

void TaskList::save(string filename){
    ofstream out(filename, ios_base::binary);
    if(!out.is_open()){
        cout << "Plik nie mógł zostać otworzony" << endl;
        return;
    }
    save(out);
}

void TaskList::save(ofstream &out){
    int i;
    char* temp;
    temp = reinterpret_cast<char*>(&lastId);
    out.write(temp, sizeof(int));
    for(i=1;i<=lastId;i++){
        Task* task = tasks[i];
        // task->save(out);
        out << task;
    }
}

void TaskList::load(string filename){
    ifstream in(filename, ios_base::binary);
    if(!in.is_open()){
        cout << "Plik nie mogl zostac otworzony" << endl;
        return;
    }
    load(in);
}

void TaskList::load(ifstream &in){
    int i, textSize;
    bool done;
    char buff[512];
    in.read(buff, sizeof(int));
    lastId = *reinterpret_cast<int*>(buff);

    for(i=1;i<=lastId;i++){
        in.read(buff, sizeof(int));
        textSize = *reinterpret_cast<int*>(buff);
        in.read(buff, textSize);
        string text(buff, textSize);
        tasks[i] = new Task(text);
        in.read(buff, sizeof(bool));
        done = *reinterpret_cast<bool*>(buff);
        if(done)
            tasks[i]->toggleDone();
    }
}
