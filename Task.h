#pragma once
#include <string>

using namespace std;

class Task{
    string text;
    bool done = 0;

public:
    Task(string text): text(text){};
    const string getText();
    void setText(string newText);
    bool isDone();
    void setDone(bool done);
};