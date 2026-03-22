//
// Created by robot on 3/12/26.
//
#pragma once
#include "DataStream.hpp"

class EventStream : public DataStream
{
public:
    EventStream(std::string stream_id);
    std::string process_batch(const std::vector<std::any> &databatch) override;
    std::vector<std::any> filter_data(const std::vector<std::any> &databatch,
                                      const std::optional<std::string> &criteria) override;
    std::map<std::string, std::variant<std::string, int, double>> get_stats() override;
};


