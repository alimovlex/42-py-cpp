//
// Created by robot on 3/11/26.
//

#include "FantasyCardFactory.hpp"

std::unique_ptr<Card>
FantasyCardFactory::create_creature(std::variant<std::monostate, std::string, int> name_or_power)
{
    if (std::holds_alternative<std::string>(name_or_power))
    {
        std::string name = std::get<std::string>(name_or_power);
        if (name == "dragon")
            return std::make_unique<CreatureCard>("Fire Dragon", 5, "Legendary", 7, 5);
        if (name == "goblin")
            return std::make_unique<CreatureCard>("Goblin Warrior", 2, "Common", 2, 1);
    }
    return std::make_unique<CreatureCard>("Generic Fantasy Creature", 1, "Common", 1, 1);

}

std::unique_ptr<Card> FantasyCardFactory::create_spell(std::variant<std::monostate, std::string, int> name_or_power)
{
    return std::make_unique<SpellCard>("Fireball", 3, "Rare", "damage");
}

std::unique_ptr<Card>
FantasyCardFactory::create_artifact(std::variant<std::monostate, std::string, int> name_or_power)
{
    return std::make_unique<ArtifactCard>("Mana Ring", 2, "Uncommon", 3, "Add 1 mana");
}

std::map<std::string, std::variant<std::string, int>> FantasyCardFactory::create_themed_deck(int size)
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"deck_theme", std::string("Fantasy")},
            {"deck_size", size}
    };
    return dict;
}

std::map<std::string, std::variant<std::string, int>> FantasyCardFactory::get_supported_types() const
{
    std::map<std::string, std::variant<std::string, int>> dict = {
            {"creatures", std::string("dragon, goblin")},
            {"spells", std::string("fireball")},
            {"artifacts", std::string("mana_ring")}
    };
    return dict;
}