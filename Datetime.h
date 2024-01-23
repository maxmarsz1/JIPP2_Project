#pragma once
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include "Exceptions.h"

using namespace std;


template<class T = time_t>
class Datetime: public Date, public Time{
public:
    Datetime(){
        setDefault();
    }
    Datetime(int hour, int minute, int day, int month, int year): Date(day, month, year),Time(hour, minute){};
    Datetime(T epoch){
        setDatetime(epoch);
    }

    void setDatetime(T epoch){
        tm *dt = gmtime(&epoch);
        hour = dt->tm_hour;
        minute = dt->tm_min;
        day = dt->tm_mday;
        month = dt->tm_mon + 1;
        year = dt->tm_year + 1900;
        // tm dt;
        // localtime_s(&dt, &epoch);
        // hour = dt.tm_hour;
        // minute = dt.tm_min;
        // day = dt.tm_mday;
        // month = dt.tm_mon + 1;
        // year = dt.tm_year + 1900;
        // delete dt;
    }

    void setDefault(){
        Time::setDefault();
        Date::setDefault();
    }

    time_t getEpoch(){
        struct tm dt = tm();
        dt.tm_hour = hour;
        dt.tm_min = minute;
        dt.tm_mday = day;
        dt.tm_mon = month - 1;
        dt.tm_year = year - 1900;
        return mktime(&dt);
    }

    void print(){
        Time::print();
        cout << " ";
        Date::print();
    }

    bool isPast(){
        return getEpoch() < time(0);
    }
};
