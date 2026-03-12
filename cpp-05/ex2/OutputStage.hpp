//
// Created by robot on 3/12/26.
//
#pragma once
#include "ProcessingStage.hpp"

class OutputStage : public ProcessingStage
{
public:
    std::any process(std::any data) override;
};


