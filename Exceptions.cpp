#include "Exceptions.h"
#include <exception>
#include <iostream>

using namespace std;

const char* InvalidDateFormat::what(){
    return "Provided date is invalid";
}

const char* InvalidTimeFormat::what(){
    return "Provided time is invalid";
}