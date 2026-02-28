//
// Created by robot on 2/28/26.
//

#pragma once
#include <map>
#include <any>
#include <string>
#include <vector>

class Magical {
public:
    virtual std::map<std::string, std::string> cast_spell(std::string& spell_name,
                                                          std::vector<std::string>& targets) = 0;
    virtual std::map<std::string, std::string> channel_mana(int amount) = 0;
    virtual std::map<std::string, std::string> get_magic_stats() = 0;
    virtual ~Magical() = default;
};
