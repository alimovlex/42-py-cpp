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

std::map<std::string, std::string>
AggressiveStrategy::execute_turn(std::vector<std::string> &hand, std::vector<std::string> &battlefield)
{

}

std::string AggressiveStrategy::get_strategy_name()
{
    return name;
}

std::vector<std::string> AggressiveStrategy::prioritize_targets(std::vector<std::string> &list)
{

}