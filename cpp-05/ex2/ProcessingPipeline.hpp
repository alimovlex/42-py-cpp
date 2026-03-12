//
// Created by robot on 3/12/26.
//
#pragma once

//
// Created by robot on 3/12/26.
//
#pragma once
#include <vector>
#include "ProcessingStage.hpp"

class ProcessingPipeline
{
public:
    std::string pipeline_id;
    std::vector<std::unique_ptr<ProcessingStage>> stages;

    virtual ~ProcessingPipeline() = default;

    void add_stage(std::unique_ptr<ProcessingStage> stage);

    virtual void process(std::any data) = 0; // Pure virtual
};
