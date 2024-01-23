#include "Date.h"
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

Date::Date(){
    setDefault();
}

Date::Date(int day, int month, int year){
    setDate(day, month, year);
}

void Date::setDate(int day, int month, int year){
    tm* date = new tm;
    date->tm_mday = day;
    date->tm_mon = month - 1;
    date->tm_year = year - 1900;
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_isdst = 1;
    time_t convertedTime; 
    if((convertedTime = mktime(date)) == -1){
        perror("Blad");
        cout << "Nieprawidłowa data :(" << endl;
        setDefault();
        return;
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setDefault(){
    time_t t = time(0) + 24 * 60 * 60;
    tm* now;
    localtime_s(now, &t);
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}

void Date::print(){
	cout << setfill('0');
    cout << day << "." << setw(2) << month << "." << year << endl;
}
