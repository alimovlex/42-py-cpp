#ifndef CARDFACTORY_HPP
#define CARDFACTORY_HPP

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <variant>
#include "../ex0/Card.hpp"

class CardFactory {
public:
    virtual ~CardFactory() = default;
    virtual std::unique_ptr<Card> create_creature(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) = 0;
    virtual std::unique_ptr<Card> create_spell(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) = 0;
    virtual std::unique_ptr<Card> create_artifact(std::variant<std::monostate, std::string, int> name_or_power = std::monostate{}) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> create_themed_deck(int size) = 0;
    virtual std::map<std::string, std::variant<std::string, int>> get_supported_types() const = 0;
};

#endif
