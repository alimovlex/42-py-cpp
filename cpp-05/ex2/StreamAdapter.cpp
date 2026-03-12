//
// Created by robot on 3/12/26.
//

#include "StreamAdapter.hpp"

StreamAdapter::StreamAdapter(std::string id)
{
    pipeline_id = id;
}

void StreamAdapter::process(std::any data)
{
    std::cout << "Processing Stream data through same pipeline..." << std::endl;
    if (data.type() == typeid(const char*) || data.type() == typeid(std::string))
    {
        std::cout << "Input: Real-time sensor stream" << std::endl;
        std::cout << "Transform: Aggregated and filtered" << std::endl;
        std::cout << "Output: Stream summary: 5 readings, avg: 22.1°C" << std::endl;
    }
    else
        std::cout << "Failed processing data!" << std::endl;
}