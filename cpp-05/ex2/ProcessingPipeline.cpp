//
// Created by robot on 3/12/26.
//

#include "ProcessingPipeline.hpp"

void ProcessingPipeline::add_stage(std::unique_ptr<ProcessingStage> stage)
{
    stages.push_back(std::move(stage));
}