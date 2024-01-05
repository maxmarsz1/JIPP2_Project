#include "Task.h"
#include <string>

using namespace std;

const string Task::getText(){
    return text;
}

void Task::setText(string newText){
    text = newText;
}

bool Task::isDone(){
    return done;
}

void Task::setDone(bool done){
    this->done = done;
}