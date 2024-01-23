#pragma once
#include "Date.h"
#include "Time.h"

class Datetime: Date, Time{
public:
    Datetime();
    Datetime(int hour, int minute, int day, int month, int year);
    Datetime(time_t epoch);
    void setDatetime(time_t epoch);
    void setDefault();
    void print();
};
