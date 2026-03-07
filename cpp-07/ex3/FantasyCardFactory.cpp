//
// Created by robot on 2/28/26.
//

#include "FantasyCardFactory.hpp"

void FantasyCardFactory::display_name()
{
    std::string class_name;
    class_name = typeid(*this).name();
    class_name.erase(class_name.begin());
    std::cout << typeid(*this).name() << std::endl;
}

std::vector<std::string> get_keys(std::map<std::string, std::map<std::string, std::string>>& dict)
{
    std::vector<std::string> keys;
    keys.reserve(dict.size());
    for (const auto& key: dict)
        keys.push_back(key.first);
    return keys;
}

std::map<std::string, std::vector<std::string>> FantasyCardFactory::get_supported_types()
{
    std::vector<std::string> creature_keys = get_keys(creature_types);
    std::vector<std::string> spell_keys = get_keys(spell_types);
    std::vector<std::string> artifacts_keys = get_keys(artifact_types);
    std::map<std::string, std::vector<std::string>> dict = {
            {"creatures", creature_keys},
            {"spells", spell_keys},
            {"artifacts", artifacts_keys}
    };
    return dict;
}

Card FantasyCardFactory::create_creature(std::string &name_or_power)
{

}

Card FantasyCardFactory::create_spell(std::string &name_or_power)
{

}

Card FantasyCardFactory::create_artifact(std::string &name_or_power)
{

}

std::map<std::string, std::string> FantasyCardFactory::create_themed_deck(int size)
{
    std::unique_ptr<Card> deck;
    std::map<std::string, std::string> dict;

    /*
    for (int i = 0; i <= size; ++i)
        if (i % 3 == 0)
           deck = std::make_unique<CreatureCard>(create_creature());
        else if (i % 3 == 1)
            deck = std::make_unique<SpellCard>(create_spell());
        else
            deck = std::make_unique<ArtifactCard>(create_artifact());
    */
   dict = {
           {"deck", deck->name},
           {"size", std::to_string(deck->cost)},
           {"theme", "Fantasy"},
           {"factory", "FantasyCardFactory"}
        };

    return dict;

}

FantasyCardFactory::FantasyCardFactory():
        creature_types (
        {
            {"dragon",{{"cost", "5"}, {"rarity", "Rare"}}
            },
            {"goblin", {{"cost", "2"}, {"rarity", "Common"}}
            }
        }),
        spell_types({
            {"fireball",{{"cost", "3"},
                         {"effect_type", "damage"},
                         {"rarity", "Common"}}
            }
        }),
        artifact_types ({
            {"mana_ring",{{"cost", "2"},
                          {"durability", "5"},
                          {"effect", "+1 mana"},
                          {"rarity", "Uncommon"}}
            }
        })
{}