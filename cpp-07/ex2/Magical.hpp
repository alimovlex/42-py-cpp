#pragma once
#include <map>
#include <string>
#include <variant>
#include <vector>

class Magical {
public:
    virtual ~Magical() = default;
    virtual std::map<std::string, std::variant<std::string, int>> cast_spell(const std::string& spell_name, const std::vector<std::string>& targets) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> channel_mana(int amount) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> get_magic_stats() const = 0;
};

