//
// Created by robot on 3/12/26.
//

#include "template_functions.hpp"

size_t get_size(const std::any& data)
{
    if (auto vec = std::any_cast<std::vector<int>>(&data))
        return vec->size();
    else if (auto str = std::any_cast<std::string>(&data))
        return str->size();
    else
        return 0;
}
