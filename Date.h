#pragma once
#include <ctime>

class Date{
protected:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    void setDate(int day, int month, int year);
    void setDefault();
    void print();

};
