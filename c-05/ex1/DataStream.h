//
// Created by robot on 3/12/26.
//
#pragma once
#include <vector>
#include <any>
#include <optional>
#include <map>
#include <variant>
#include <string>
#include <iostream>
#include <memory>

class DataStream
{
public:
    std::vector<std::any> databatch;
    std::optional<std::string> criteria;
    std::string stream_id;

    virtual std::string process_batch(const std::vector<std::any>& databatch) = 0;
    virtual std::vector<std::any> filter_data(const std::vector<std::any>& databatch,
                                              const std::optional<std::string>& criteria)
    {
        this->databatch = databatch;
        this->criteria = criteria;
        return databatch;
    }
    virtual std::map<std::string, std::variant<std::string, int, double>> get_stats() = 0;

    virtual ~DataStream() = default;
};

