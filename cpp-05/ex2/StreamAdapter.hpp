//
// Created by robot on 3/12/26.
//
#pragma once
#include "ProcessingPipeline.hpp"

class StreamAdapter : public ProcessingPipeline
{
public:
    StreamAdapter(std::string id);
    void process(std::any data) override;
};
