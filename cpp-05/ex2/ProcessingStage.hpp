//
// Created by robot on 3/12/26.
//
#pragma once
#include <any>
#include <iostream>
#include <map>

class ProcessingStage
{
public:
    virtual ~ProcessingStage() = default;
    virtual std::any process(std::any data) = 0;
};

