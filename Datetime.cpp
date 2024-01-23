#include "Datetime.h"
#include "Date.h"
#include "Time.h"
#include <ctime>
#include <iostream>
#include "Exceptions.h"

using namespace std;

Datetime::Datetime(): Time(), Date(){
    Datetime::setDefault();
}

Datetime::Datetime(int hour, int minute, int day, int month, int year): Time(hour, minute), Date(day, month, year){};

Datetime::Datetime(time_t epoch){
    setDatetime(epoch);
}

void Datetime::setDatetime(time_t epoch){
    if(epoch < time(0)){
        throw PastDate();
    }

    struct tm dt;
    localtime_s(&dt, &epoch);
    hour = dt.tm_hour;
    minute = dt.tm_min;
    day = dt.tm_mday;
    month = dt.tm_mon;
    year = dt.tm_year;
}

void Datetime::setDefault(){
    Time::setDefault();
    Date::setDefault();
}

void Datetime::print(){
    Time::print();
    Date::print();
}