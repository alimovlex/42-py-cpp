//
// Created by alalimov on 2/19/26.
//

#pragma once
#include <string>
#include <map>
#include <any>

class Card
{
public:
    std::string name, rarity;
    int cost, available_mana = 0;
    Card(std::string& name, int cost, std::string& rarity): name(name), rarity(rarity), cost(cost) {}
    virtual std::map<std::string, int> play(
            const std::map<std::string, int>& game_state
    ){};

    std::map<std::string, std::string> get_card_info();

    bool is_playable(int mana);

    virtual ~Card() = default;
};

