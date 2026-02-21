#include <iostream>
#include <sstream>
#include "CreatureCard.hpp"

int main()
{
    CreatureCard creatureCard("Fire Dragon", 5, "Legendary", 7, 5);
    std::map<std::string, std::string> dict = creatureCard.get_card_info();
    std::string name = dict["name"];
    int mana = 6;
    bool value = creatureCard.is_playable(mana);
    std::map<std::string, std::string> game_state;

    std::cout << "=== DataDeck Card Foundation ===\n" << std::endl;
    std::cout << "CreatureCard Info:" << std::endl;
    for (const auto &kv : dict)
        std::cout << kv.first << " -> " << kv.second << std::endl;
    std::cout << "Playing Fire Dragon with " << mana << " mana available:" << std::endl;

    std::ostringstream oss;
    oss << std::boolalpha << value;
    std::string result = oss.str();
    std::cout << "Playable: " << result << std::endl;

    dict = creatureCard.play(game_state);
    std::cout << "Play result: " << std::endl;
    for (const auto &kv : dict)
        std::cout << kv.first << " -> " << kv.second << std::endl;

    std::cout << name << " attacks Goblin Warrior:" << std::endl;
    mana -= 3;
    std::cout << "Testing insufficient mana (" << mana << " available)" << std::endl;
    value = creatureCard.is_valid();
    std::cout << "Playable: " << std::boolalpha << value << std::endl;

    return 0;
}
