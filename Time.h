#pragma once
#include <string>

using namespace std;

class Time{
protected:
    int hour;
    int minute;

public:
    Time();
    Time(int hour, int minute);
    void setTime(string time);
    void setTime(int hour, int minute);
    void setDefault();
    void print();
};

