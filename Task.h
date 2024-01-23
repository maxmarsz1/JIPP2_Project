#pragma once
#include <string>
#include "Datetime.h"

using namespace std;

class Task{
    string text;
    bool done = false;

public:
    Datetime<time_t> datetime;

    Task();
    Task(string text): text(text){};
    ~Task();
    const string getText();
    void setText(string newText);
    bool isDone();
    void toggleDone();
    void print();
    void save(ofstream &out);
    friend ostream &operator<<(ostream& stream, const Task *rhs);
    friend ofstream &operator<<(ofstream& stream, Task *rhs);
};
