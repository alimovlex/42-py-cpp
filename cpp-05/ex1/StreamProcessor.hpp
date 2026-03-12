//
// Created by robot on 3/12/26.
//
#pragma once
#include "DataStream.hpp"
#include "SensorStream.hpp"
#include "TransactionStream.hpp"
#include "EventStream.hpp"

class StreamProcessor
{
public:
    std::vector<std::unique_ptr<DataStream>> streams;
    std::vector<std::string> results;

    void add_stream(std::unique_ptr<DataStream> stream);
    void process_unified(const std::vector<std::vector<std::any>>& data_batches,
                         const std::optional<std::string> &filter_criteria);
};
