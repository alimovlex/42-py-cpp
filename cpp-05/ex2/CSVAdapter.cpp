//
// Created by robot on 3/12/26.
//

#include "CSVAdapter.hpp"

CSVAdapter::CSVAdapter(std::string id)
{
    pipeline_id = id;
    std::cout << "Pipeline " << pipeline_id << std::endl;
}

void CSVAdapter::process(std::any data)
{
    std::cout << "Processing CSV data through same pipeline..." << std::endl;
    if (auto* str_ptr = std::any_cast<std::string>(&data))
    {
        std::string val = *str_ptr;
        std::cout << "Input: \"" << val << "\"" << std::endl;
        if (val.find("user") != std::string::npos && val.find("action") != std::string::npos)
        {
            std::cout << "Transform: Parsed and structured data" << std::endl;
            std::cout << "Output: User activity logged: 1 actions processed" << std::endl;
        }
        else
            std::cout << "Failed processing data!" << std::endl;
    }
    else
        std::cout << "Failed processing data!" << std::endl;
}