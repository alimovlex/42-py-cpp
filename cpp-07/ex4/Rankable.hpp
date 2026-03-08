//
// Created by alalimov on 3/8/26.
//

#pragma once
#include <map>
#include <string>

class Rankable {
public:
    virtual int calculate_rating() = 0;
    virtual void update_wins(int wins) = 0;
    virtual void update_losses(int losses) = 0;
    virtual std::map<std::string, std::string> get_rank_info() = 0;

    virtual ~Rankable() = default;
};

