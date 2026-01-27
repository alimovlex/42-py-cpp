#include <iostream>
#include <map>

class ItemInfo {
    public:
    int qty;
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
    return 0;
}
