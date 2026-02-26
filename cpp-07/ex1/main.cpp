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
    Deck deck;
    std::shared_ptr<Card> card;
    deck.add_card(card);
    //std::cout << "Deck stats: " << deck.get_deck_stats(); //PRINTING DICTIONARY!!!
    std::cout << "Drawing and playing cards: " << std::endl;
    //std::cout << "Play result: " << deck.draw_card(); //PRINTING DICTIONARY!!!
    //deck.remove_card("Mana Crystal");
    //std::cout << "Play result: " << deck.draw_card(); //PRINTING DICTIONARY!!!
    //std::cout << "Deck stats: " << deck.get_deck_stats(); //PRINTING DICTIONARY!!!
    std::cout << "Polymorphism in action: Same interface, different card behaviors!" << std::endl;
    return 0;
}

/*
     * deck = Deck()
     * deck.add_card(cards)
     * print(f"Deck stats: {deck.get_deck_stats()}")
     * print()
     * print("Drawing and playing cards:")
     * print()
     * print(f"Play result: {deck.draw_card()}")
     * deck.remove_card("Lightning Bolt")
     * print()
     * print(f"Play result: {deck.draw_card()}")
     * deck.remove_card("Mana Crystal")
     * print()
     * print(f"Play result: {deck.draw_card()}")
     * print()
    # print(f"Deck stats: {deck.get_deck_stats()}")
    print("Polymorphism in action: Same interface, different card behaviors!")
     */