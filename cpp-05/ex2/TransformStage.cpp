//
// Created by robot on 3/12/26.
//

#include "TransformStage.hpp"

std::any TransformStage::process(std::any data)
{
    std::cout << "Stage 2: Data transformation and enrichment" << std::endl;
    if (data.type() != typeid(std::map<std::string, std::any>))
        std::cout << "Invalid data!" << std::endl;
    return data;
}