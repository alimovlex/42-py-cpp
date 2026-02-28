//
// Created by alalimov on 2/21/26.
//

#include <iostream>
#include <array>
#include "EliteCard.hpp"

int main()
{
    std::vector<std::map<std::string, std::string>> cards = {
            {
                    {"name", "Fireball"},
                    {"cost", std::to_string(4)},
                    {"rarity", "Uncommon"},
                    {"effect_type", "damage"}
            },
            {
                    {"caster", "Arcane Warrior"},
                    {"cost", std::to_string(8)},
                    {"rarity", "Common"},
                    {"effect_type", "damage"}
            }
    };

    std::array<std::string, 2> target = {"Enemy1", "Enemy2"};
    std::cout << "=== DataDeck Ability System ===\n" << std::endl;
    //EliteCard eliteCard = EliteCard();

    std::cout << "EliteCard capabilities: " << std::endl;
    std::cout << "- Card: ['play', 'get_card_info', 'is_playable']" << std::endl;
    std::cout << "- Combatable: ['attack', 'defend', 'get_combat_stats']" << std::endl;
    std::cout << "- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']" << std::endl;

    std::cout << "Playing Arcane Warrior (Elite Card): " << std::endl;
    std::cout << "Combat phase: " << std::endl;
    std::cout << "Attack result: " << std::endl;
    std::cout << "Defense result: " << std::endl;
    std::cout << "Magic phase: " << std::endl;
    std::cout << "Spell cast: " << std::endl;
    std::cout << "Mana channel: " << std::endl;
    std::cout << "Multiple interface implementation successful" << std::endl;

    return 0;
}