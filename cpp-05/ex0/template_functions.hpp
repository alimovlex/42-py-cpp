//
// Created by robot on 3/12/26.
//

#pragma once
#include <any>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>

size_t get_size(const std::any& data);

template<typename T>
void iterate_any(const std::any& data, std::string& str, bool& checker)
{
    if (auto container = std::any_cast<const T>(&data))
    {
        for (const auto& elem : *container)
        {
            if (auto num = std::any_cast<int>(elem))
            {
                str += std::to_string(num) + " ";
                checker = true;
            }
            else
            {
                throw std::invalid_argument("All elements have to be integers");
                checker = false;
            }
        }
    }
    else
        std::cout << "Type mismatch" << std::endl;
}

template<typename T>
auto accumulate_any(const std::any& data)
{
    if (auto container = std::any_cast<const T>(&data))
    {
        using ValueType = typename T::value_type;
        return std::accumulate(
                container->begin(),
                container->end(),
                ValueType{}
        );
    }

    throw std::bad_any_cast();
}