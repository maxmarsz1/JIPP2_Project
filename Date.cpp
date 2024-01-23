#include "Date.h"
#include "Exceptions.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <string>

using namespace std;

Date::Date(){
    setDefault();
}

Date::Date(int day, int month, int year){
    setDate(day, month, year);
}

//(dd.mm.rrrr)
void Date::setDate(string date){
    int day, month, year;
    if(date.find('.') != 2 || date.find('.', 3) != 5 || date.size() != 10)
        throw InvalidDateFormat();

    try{
        day = stoi(date.substr(0,2));
        month = stoi(date.substr(3,2));
        year = stoi(date.substr(6,4));
    } catch (...){
        cout << "Nie mozna bylo ustawic daty" << endl;
        return;
    }
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

    this->day = date->tm_mday;
    this->month = date->tm_mon + 1;
    this->year = date->tm_year + 1900;
}

void Date::setDefault(){
    time_t t = time(0) + 24 * 60 * 60;
    tm* now = gmtime(&t);
    // tm now = tm();
    // localtime_s(now, &t);
    // day = now.tm_mday;
    // month = now.tm_mon + 1;
    // year = now.tm_year + 1900;
    day = now->tm_mday ;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}

void Date::print(){
	cout << setfill('0');
    cout << day << "." << setw(2) << month << "." << year;
}
