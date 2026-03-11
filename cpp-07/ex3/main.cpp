#include <iostream>
#include <variant>
#include <map>
#include <memory>
#include <vector>
#include "GameEngine.hpp"
#include "FantasyCardFactory.hpp"
#include "AggressiveStrategy.hpp"

void print_dict(const std::map<std::string, std::variant<std::string, int>>& dict)
{
    std::cout << "{";
    bool first = true;
    for (auto const& [key, val] : dict)
    {
        if (!first)
            std::cout << ", ";
        std::cout << "'" << key << "': ";
        if (std::holds_alternative<std::string>(val))
            std::cout << "'" << std::get<std::string>(val) << "'";
        else
            std::cout << std::get<int>(val);

        first = false;
    }
    std::cout << "}" << std::endl;
}

int main() {
    std::cout << "=== DataDeck Game Engine ===" << std::endl;
    
    GameEngine engine;
    auto factory = std::make_unique<FantasyCardFactory>();
    auto strategy = std::make_unique<AggressiveStrategy>();

    std::cout << "Configuring Fantasy Card Game..." << std::endl;
    std::cout << "Factory: FantasyCardFactory" << std::endl;
    std::cout << "Strategy: AggressiveStrategy" << std::endl;

    auto supported = factory->get_supported_types();
    std::cout << "Available types: ";
    print_dict(supported);

    engine.configure_engine(std::move(factory), std::move(strategy));

    std::cout << "Simulating aggressive turn..." << std::endl;
    std::cout << "Hand: [Fire Dragon (5), Goblin Warrior (2), Fireball (3)]" << std::endl;
    
    auto turn_result = engine.simulate_turn();
    std::cout << "Turn execution: ";
    print_dict(turn_result);

    std::cout << "Game Report:" << std::endl;
    auto status = engine.get_engine_status();
    print_dict(status);

    std::cout << "Abstract Factory + Strategy Pattern: Maximum flexibility achieved!" << std::endl;

    return 0;
}
