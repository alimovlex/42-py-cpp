#pragma once
#include <map>
#include <string>
#include <variant>

class Rankable {
public:
    virtual ~Rankable() = default;
    virtual int calculate_rating() const = 0;
    virtual void update_wins(int wins) = 0;
    virtual void update_losses(int losses) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> get_rank_info() const = 0;
};

