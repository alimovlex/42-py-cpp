//
// Created by alalimov on 2/21/26.
//

#include <iostream>
#include "Deck.hpp"

int main()
{
    std::vector<std::map<std::string, std::string>> cards = {
            {
            {"type", "spell"},
            {"name", "Lightning Bolt"},
            {"cost", std::to_string(3)},
            {"rarity", "Common"},
            {"effect_type", "damage"}
            },
            {
            {"type", "artifact"},
            {"name", "Mana Crystal"},
            {"cost", std::to_string(2)},
            {"rarity", "Common"},
            {"durability", std::to_string(5)},
            {"effect_type", "Permanent: +1 mana per turn"}
            },
            {
            {"type", "creature"},
            {"name", "Fire Dragon"},
            {"cost", std::to_string(5)},
            {"rarity", "Legendary"},
            {"attack", std::to_string(7)},
            {"health", std::to_string(5)},
            {"effect_type", "Creature summoned to battlefield"}
            }
    };
    std::cout << "=== DataDeck Deck Builder ===\n" << std::endl;
    //Deck deck = Deck();
    return 0;
}