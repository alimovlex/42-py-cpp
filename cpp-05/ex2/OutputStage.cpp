//
// Created by robot on 3/12/26.
//

#include "OutputStage.hpp"

std::any OutputStage::process(std::any data)
{
    std::cout << "Stage 3: Output formatting and delivery" << std::endl;
    return std::string("Processed Data Object");
}