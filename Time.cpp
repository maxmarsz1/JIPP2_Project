#include "Time.h"
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

void Time::setTime(int hour, int minute){
    this->hour = hour < 0 || hour > 24 ? 12 : hour;
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

// string Time::text(){
//     string text;
//     sprintf(text, "{:02}:{:02}", hour, minute);
// }