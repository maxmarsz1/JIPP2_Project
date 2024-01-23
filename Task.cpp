#include "Task.h"
#include <corecrt.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


Task::~Task(){
    cout << "Usuwam task: " << text << endl;
}

const string Task::getText(){
    return text;
}

void Task::setText(string newText){
    text = newText;
}

bool Task::isDone(){
    return done;
}

void Task::toggleDone(){
    done = !done;
}

void Task::print(){
    cout << text << " | zrobiony: "<< (done ? "tak" : "nie") << endl;
}

void Task::save(ofstream &out){
    int textSize = text.size();
    time_t epoch = datetime.getEpoch();
    char* temp = reinterpret_cast<char*>(&textSize);
    out.write(temp, sizeof(textSize));
    out.write(text.data(), textSize);
    temp = reinterpret_cast<char*>(&epoch);
    out.write(temp, sizeof(time_t));
    out.write(reinterpret_cast<char*>(&done), sizeof(done));
}

ostream &operator<<(ostream &lhs, const Task *rhs){
    return lhs << rhs->text <<  " | zrobiony: "<< (rhs->done ? "tak" : "nie");
}

ofstream &operator<<(ofstream &out, Task *task){
    string text = task->getText();
    int textSize = text.size();
    bool done = task->isDone();
    time_t epoch = task->datetime.getEpoch();

    char* temp = reinterpret_cast<char*>(&textSize);
    out.write(temp, sizeof(textSize));
    out.write(text.data(), textSize);
    temp = reinterpret_cast<char*>(&epoch);
    out.write(temp, sizeof(time_t));
    out.write(reinterpret_cast<char*>(&done), sizeof(done));
    return out;
}
