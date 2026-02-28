//
// Created by alalimov on 2/21/26.
//

#include "ArtifactCard.hpp"

int ArtifactCard::get_durability()
{
    return durability;
}

int ArtifactCard::get_current_durability()
{
    return current_durability;
}

std::string ArtifactCard::get_effect()
{
    return effect_type;
}

std::map<std::string, std::string> ArtifactCard::play(std::map<std::string, std::string> &game_state)
{
    std::map<std::string, std::string> result = {
            {"card_played", name},
            {"mana_used", std::to_string(cost)},
            {"effect", effect_type.insert(0, "Permanent: ")}
    };

    return result;
}

std::map<std::string, std::string> ArtifactCard::activate_ability()
{
    std::map<std::string, std::string> result;
    if (current_durability <= 0)
        result = {
            {"artifact_name", name},
            {"activated", "false"},
            {"message", "Artifact is destroyed (no durability remaining)"}
    };
    else
        result = {
                {"artifact_name", name},
                {"activated", "true"},
                {"effect", effect_type},
                {"durability_remaining", std::to_string(current_durability -= 1)},
                {"destroyed", std::to_string(current_durability <= 0)}
        };

    return result;
}

void ArtifactCard::repair(int amount)
{
    current_durability = std::min(current_durability + amount, durability);
}

std::string ArtifactCard::toString()
{
    return name + " (Artifact)";
}