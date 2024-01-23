#pragma once

class Time{
    int hours = 12;
    int minutes = 0;

public:
    Time();
    Time(int hours, int minutes);
    void setTime(int hours, int minutes);
    void print();

};

