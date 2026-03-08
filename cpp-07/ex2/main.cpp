#include <iostream>
#include <variant>
#include <map>
#include <vector>
#include "EliteCard.hpp"

void print_dict(const std::map<std::string, std::variant<std::string, int>>& dict) {
    std::cout << "{";
    bool first = true;
    for (auto const& [key, val] : dict) {
        if (!first) std::cout << ", ";
        std::cout << "'" << key << "': ";
        if (std::holds_alternative<std::string>(val)) {
            std::cout << "'" << std::get<std::string>(val) << "'";
        } else {
            std::cout << std::get<int>(val);
        }
        first = false;
    }
    std::cout << "}" << std::endl;
}

int main() {
    std::cout << "=== DataDeck Ability System ===" << std::endl;
    std::cout << "EliteCard capabilities:" << std::endl;
    std::cout << "- Card: ['play', 'get_card_info', 'is_playable']" << std::endl;
    std::cout << "- Combatable: ['attack', 'defend', 'get_combat_stats']" << std::endl;
    std::cout << "- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']" << std::endl;

    EliteCard warrior("Arcane Warrior", 6, "Epic", 5, 10, 4);
    
    std::cout << "Playing Arcane Warrior (Elite Card):" << std::endl;
    std::map<std::string, std::variant<std::string, int>> game_state;
    print_dict(warrior.play(game_state));

    std::cout << "Combat phase:" << std::endl;
    auto attack_res = warrior.attack("Enemy");
    std::cout << "Attack result: ";
    print_dict(attack_res);

    auto defend_res = warrior.defend(5);
    std::cout << "Defense result: ";
    print_dict(defend_res);

    std::cout << "Magic phase:" << std::endl;
    auto spell_res = warrior.cast_spell("Fireball", {"Enemy1", "Enemy2"});
    std::cout << "Spell cast: ";
    print_dict(spell_res);

    auto channel_res = warrior.channel_mana(3);
    std::cout << "Mana channel: ";
    print_dict(channel_res);

    std::cout << "Multiple interface implementation successful!" << std::endl;

    return 0;
}
