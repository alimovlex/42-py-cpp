#include <iostream>
#include <variant>
#include <map>
#include <memory>
#include "Deck.hpp"
#include "../ex0/CreatureCard.hpp"
#include "SpellCard.hpp"
#include "ArtifactCard.hpp"

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
    std::cout << "=== DataDeck Deck Builder ===" << std::endl;
    std::cout << "Building deck with different card types..." << std::endl;

    Deck deck;
    deck.add_card(std::make_unique<CreatureCard>("Fire Dragon", 5, "Legendary", 7, 5));
    deck.add_card(std::make_unique<SpellCard>("Lightning Bolt", 3, "Rare", "damage"));
    deck.add_card(std::make_unique<ArtifactCard>("Mana Crystal", 2, "Common", 5, "Permanent: +1 mana per turn"));

    auto stats = deck.get_deck_stats();
    std::cout << "Deck stats: ";
    print_dict(stats);

    std::cout << "Drawing and playing cards:" << std::endl;
    
    // In C++, the order might be different from the Python example due to deck handling,
    // but the polymorphism is the key.
    for (int i = 0; i < 3; ++i) {
        auto card = deck.draw_card();
        if (card) {
            std::string type = "Unknown";
            if (dynamic_cast<CreatureCard*>(card.get())) type = "Creature";
            else if (dynamic_cast<SpellCard*>(card.get())) type = "Spell";
            else if (dynamic_cast<ArtifactCard*>(card.get())) type = "Artifact";

            std::cout << "Drew: " << card->getName() << " (" << type << ")" << std::endl;
            
            std::map<std::string, std::variant<std::string, int>> game_state;
            auto result = card->play(game_state);
            std::cout << "Play result: ";
            print_dict(result);
        }
    }

    std::cout << "Polymorphism in action: Same interface, different card behaviors!" << std::endl;

    return 0;
}
