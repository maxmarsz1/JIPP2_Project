#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int hours, int minutes){
    setTime(hours, minutes);
}

void Time::setTime(int hours, int minutes){
    this->hours = hours < 0 || hours > 24 ? 12 : hours;
    this->minutes = minutes < 0 || minutes > 59 ? 0 : minutes;
}

void Time::print(){
    cout << hours << ":" << minutes;
}
