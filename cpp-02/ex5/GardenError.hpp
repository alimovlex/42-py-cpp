//
// Created by robot on 3/13/26.
//
#pragma once
#include <iostream>

class GardenError: public std::exception {
private:
    std::string message;
public:
    GardenError(const std::string& msg): message(msg) { }
    const char* what() const noexcept
    {
        return message.c_str();
    }
    //GardenError();
};

