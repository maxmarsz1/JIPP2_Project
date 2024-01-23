#pragma once
#include <exception>

class PastDate: public std::exception{
public:
    virtual const char* what();
};