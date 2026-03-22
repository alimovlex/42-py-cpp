//
// Created by robot on 3/12/26.
//
#pragma once
#include "DataStream.hpp"

int test_data_stream(std::unique_ptr<DataStream>& test, const std::string& stream_name,
                     const std::vector<std::any>& data, const std::string& key_one, const std::string& key_two);