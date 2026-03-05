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

FantasyCardFactory::FantasyCardFactory()
{
    std::map<std::string, std::map<std::string, std::string>> creature_types = {
            {"dragon",{{"cost", "5"}, {"rarity", "Rare"}}
             },
            {"goblin", {{"cost", "2"}, {"rarity", "Common"}}
            }
    };

    std::map<std::string, std::map<std::string, std::string>> spell_types = {
            {"fireball",{{"cost", "3"}, {"effect_type", "damage"}, {"rarity", "Common"}}
            }
    };

    std::map<std::string, std::map<std::string, std::string>> artifact_types = {
            {"mana_ring",{{"cost", "2"}, {"durability", "5"}, {"effect", "+1 mana"}, {"rarity", "Uncommon"}}
            }
    };

}