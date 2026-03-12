//
// Created by robot on 3/12/26.
//

#include "InputStage.hpp"

std::any InputStage::process(std::any data)
{
    std::cout << "Stage 1: Input validation and parsing" << std::endl;
    if (data.type() != typeid(std::map<std::string, std::any>))
        std::cout << "Invalid data!" << std::endl;
    return data;
}