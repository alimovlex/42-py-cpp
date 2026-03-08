#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <map>
#include <variant>

class Card {
protected:
    std::string name;
    int cost;
    std::string rarity;

public:
    Card(std::string name, int cost, std::string rarity)
        : name(std::move(name)), cost(cost), rarity(std::move(rarity)) {}
    
    virtual ~Card() = default;

    virtual std::map<std::string, std::variant<std::string, int>> play(std::map<std::string, std::variant<std::string, int>> game_state) = 0;
    
    virtual std::map<std::string, std::variant<std::string, int>> get_card_info() const {
        return {
            {"name", name},
            {"cost", cost},
            {"rarity", rarity}
        };
    }

    bool is_playable(int available_mana) const {
        return available_mana >= cost;
    }

    std::string getName() const { return name; }
    int getCost() const { return cost; }
};

#endif
