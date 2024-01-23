#pragma once
#include <ctime>
#include <string>

class Date{
protected:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int day, int month, int year);
    void setDate(int day, int month, int year);
    void setDate(std::string date);
    void setDefault();
    void print();
};
