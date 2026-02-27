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
    std::cout << "Building deck with different card types..." << std::endl;
    Deck deck;
    std::shared_ptr<Card> card;
    std::make_shared<Deck>();
    deck.add_card(card);
    std::cout << "Deck stats: " << std::endl;
    for (const auto &kv : deck.get_deck_stats())
        std::cout << kv.first << " -> " << kv.second << std::endl;

    std::cout << "Drawing and playing cards: " << std::endl;

    std::cout << "Play result: " << std::endl;
    for (const auto &kv : deck.draw_card())
        std::cout << kv.first << " -> " << kv.second << std::endl;
    deck.remove_card("Lightning Bolt");

    std::cout << "Play result: " << std::endl;
    for (const auto &kv : deck.draw_card())
        std::cout << kv.first << " -> " << kv.second << std::endl;

    deck.remove_card("Mana Crystal");

    std::cout << "Play result: " << std::endl;
    for (const auto &kv : deck.draw_card())
        std::cout << kv.first << " -> " << kv.second << std::endl;

    std::cout << "Polymorphism in action: Same interface, different card behaviors!" << std::endl;
    return 0;
}
