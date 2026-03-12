//
// Created by robot on 3/12/26.
//
#pragma once
#include "ProcessingPipeline.hpp"

class JSONAdapter : public ProcessingPipeline
{
public:
    JSONAdapter(std::string id);
    void process(std::any data) override;
};

