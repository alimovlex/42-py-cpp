//
// Created by robot on 3/12/26.
//

#include "JSONAdapter.hpp"

JSONAdapter::JSONAdapter(std::string id)
{
    pipeline_id = id;
    std::cout << "Pipeline " << pipeline_id << std::endl;
}

void JSONAdapter::process(std::any data)
{
    std::cout << "Processing JSON data through pipeline..." << std::endl;
    try
    {
        auto* data_map = std::any_cast<std::map<std::string, std::any>>(&data);
        if (data_map)
        {
            // Simplified print for demo
            std::cout << "Input: {sensor: " << std::any_cast<const char*>(data_map->at("sensor"))
                      << ", ...}" << std::endl;
            if (data_map->count("sensor") && data_map->count("value") && data_map->count("unit"))
            {
                double val = std::any_cast<double>(data_map->at("value"));
                std::string temp_cal = "";
                std::cout << "Transform: Enriched with metadata and validation" << std::endl;

                if (val > 23 && val < 30)
                    temp_cal = "Normal range";
                else if (val > 15 && val < 23)
                    temp_cal = "avg";

                std::cout << "Output: Processed temperature reading: " << val << "°C ("
                          << temp_cal << ")" << std::endl;
            }
        }
        else
            throw std::runtime_error("Type mismatch");
    }
    catch (...)
    {
        std::cout << "Failed processing data!" << std::endl;
    }
}