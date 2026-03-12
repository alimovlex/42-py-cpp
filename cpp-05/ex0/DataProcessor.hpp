//
// Created by robot on 3/12/26.
//

#pragma once
#include <any>
#include <string>
#include <iostream>
#include "template_functions.hpp"

class DataProcessor
{
public:
    std::any data;
    std::string result;
    virtual std::string process(const std::any& data) = 0;
    virtual bool        validate(const std::any& data) = 0;

    virtual std::string format_output(const std::string& result) { return result; }

    virtual ~DataProcessor() = default;
};
