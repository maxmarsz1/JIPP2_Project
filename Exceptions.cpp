#include "Exceptions.h"
#include <exception>
#include <iostream>

using namespace std;

const char* PastDate::what(){
    return "Provided date is past";
}