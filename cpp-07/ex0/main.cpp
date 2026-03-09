#include <iostream>
#include <iomanip>
#include <variant>
#include "CreatureCard.hpp"

void print_dict(const std::map<std::string, std::variant<std::string, int>> &dict)
{
    std::cout << "{";
    bool first = true;
    for (auto const&[key, val]: dict)
    {
        if (!first)
            std::cout << ", ";
        else
            std::cout << "'" << key << "': ";

        if (std::holds_alternative<std::string>(val))
            std::cout << "'" << std::get<std::string>(val) << "'";
        else
            std::cout << std::get<int>(val);

        first = false;
    }
    std::cout << "}" << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "=== DataDeck Card Foundation ===" << std::endl;
    std::cout << "Testing Abstract Base Class Design:" << std::endl;

    CreatureCard dragon("Fire Dragon", 5, "Legendary", 7, 5);

    std::cout << "CreatureCard Info:" << std::endl;
    print_dict(dragon.get_card_info());

    std::cout << "Playing Fire Dragon with 6 mana available:" << std::endl;
    int mana = 6;
    std::cout << "Playable: ";
    if (dragon.is_playable(mana))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    std::map<std::string, std::variant<std::string, int>> game_state;
    std::map<std::string, std::variant<std::string, int>> play_result = dragon.play(game_state);
    std::cout << "Play result: ";
    print_dict(play_result);

    std::cout << "Fire Dragon attacks Goblin Warrior:" << std::endl;
    std::map<std::string, std::variant<std::string, int>> attack_result = dragon.attack_target("Goblin Warrior");
    std::cout << "Attack result: ";
    print_dict(attack_result);

    std::cout << "Testing insufficient mana (3 available):" << std::endl;
    mana = 3;
    std::cout << "Playable: ";
    if (dragon.is_playable(mana))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    std::cout << "Abstract pattern successfully demonstrated!" << std::endl;

    return 0;
}
