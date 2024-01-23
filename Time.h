#pragma once

class Time{
protected:
    int hour;
    int minute;

public:
    Time();
    Time(int hour, int minute);
    void setTime(int hour, int minute);
    void setDefault();
    void print();

};

