//
// Created by robot on 3/12/26.
//
#pragma once
#include "ProcessingPipeline.hpp"

class CSVAdapter : public ProcessingPipeline
{
public:
    CSVAdapter(std::string id);
    void process(std::any data) override;
};
