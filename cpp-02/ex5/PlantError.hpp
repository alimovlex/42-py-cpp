//
// Created by robot on 3/13/26.
//
#pragma once
#include "GardenError.hpp"

class PlantError: public GardenError
{
private:
    std::string message;
public:
    PlantError(const std::string& msg): GardenError(msg), message(msg) { }
    const char* what() const noexcept
    {
        return message.c_str();
    }
};

