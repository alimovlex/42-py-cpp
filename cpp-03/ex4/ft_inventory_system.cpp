#include <iostream>
#include <map>
#include <set>

class ItemInfo {
    public:
    int quantity;
    std::string type;
    std::string rarity;
    int value;
};

void total_value(std::map<std::string, ItemInfo>& inventory)
{

}

void total_items(std::map<std::string, ItemInfo>& inventory)
{

}

void get_categories(std::map<std::string, ItemInfo>& inventory)
{

}


int main(void)
{
    std::cout << "=== Player Inventory System ===" << std::endl;
    std::map<std::string, ItemInfo> alice = {
        {"sword",  {1, "weapon",      "rare",      500}},
        {"potion", {5, "consumable", "common",    50}},
        {"shield", {1, "armor",      "uncommon",  200}}
    };

    std::map<std::string, ItemInfo> bob = {
        {"potion", {0, "consumable", "common", 50}}
    };

    std::cout << "=== Alice's Inventory ===" << std::endl;
    for (const auto& key: alice)
        std::cout << " - " << key.first << " (" << key.second.type << ", "
        << key.second.rarity << "): " << key.second.quantity << "x "
        << "@ " << key.second.value << " gold each = "
        << key.second.quantity * key.second.value << " gold" << std::endl;

    /*   Iteration over basic dictionary
    for (const auto& [key, value] : alice)
    {
        std::cout << key << " -> " << value << std::endl;
    }
    */
    //std::set<std::string> keys_list = alice.Keys;

    return 0;
}
