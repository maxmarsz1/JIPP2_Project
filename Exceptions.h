#pragma once
#include <exception>

class InvalidDateFormat: public std::exception{
public:
    virtual const char* what();
};

class InvalidTimeFormat: public std::exception{
public:
    virtual const char* what();
};