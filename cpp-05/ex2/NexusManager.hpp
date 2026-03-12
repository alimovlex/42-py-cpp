//
// Created by robot on 3/12/26.
//
#pragma once
#include "ProcessingPipeline.hpp"

class NexusManager
{
    std::vector<std::shared_ptr<ProcessingPipeline>> pipelines;

public:
    void add_pipeline(std::shared_ptr<ProcessingPipeline> pipeline);
    void process_data(std::any data);
    void demonstrate_chaining();
    void demonstrate_error_recovery();
};
