//
// Created by alalimov on 3/5/26.
//

#include "AggressiveStrategy.hpp"

void AggressiveStrategy::display_name()
{
    std::string class_name;
    class_name = typeid(*this).name();
    class_name.erase(class_name.begin());
    std::cout << typeid(*this).name() << std::endl;
}