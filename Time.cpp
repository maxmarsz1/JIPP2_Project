#include "Time.h"
#include "Exceptions.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

Time::Time(){
    setDefault();
}

Time::Time(int hour, int minute){
    setTime(hour, minute);
}

//(hh:mm)
void Time::setTime(string time){
    int hour, minute;
    if(time.find(':') != 2 || time.size() != 5)
        throw InvalidTimeFormat();

    try{
        hour = stoi(time.substr(0,2));
        minute = stoi(time.substr(3,2));
    } catch (...){
        cout << "Nie mozna bylo ustawic godziny" << endl;
        return;
    }
    setTime(hour, minute);
}

void Time::setTime(int hour, int minute){
    this->hour = hour < 0 || hour >= 24 ? 12 : hour;
    this->minute = minute < 0 || minute > 59 ? 0 : minute;
}

void Time::print(){
	cout << setfill('0');
    cout << setw(2) << hour << ":" << setw(2) << minute;
}

void Time::setDefault(){
    hour = 12;
    minute = 0;
}
