#ifndef COMBATABLE_HPP
#define COMBATABLE_HPP

#include <map>
#include <string>
#include <variant>

class Combatable {
public:
    virtual ~Combatable() = default;
    virtual std::map<std::string, std::variant<std::string, int>> attack(const std::string& target) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> defend(int incoming_damage) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> get_combat_stats() const = 0;
};

#endif
