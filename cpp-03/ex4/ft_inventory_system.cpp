#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>

int get_total_items(std::map<std::string, int> &inventory)
{
  int total_value = 0;
  for (const auto &key_value : inventory)
    total_value += key_value.second;

  return total_value;
}

void get_categories(std::map<std::string, int> &inventory)
{

}

std::map<std::string, int> ft_parse_args(char **argv)
{
  std::string key;
  int value = 0;
  int total_value = 0;
  std::map<std::string, int> inventory;
  while (*argv)
  {
    std::string str = *argv;
    size_t colon_pos = str.find(':');

    if (colon_pos != std::string::npos)
    {
      key = str.substr(0, colon_pos);
      value = std::stoi(str.substr(colon_pos + 1));
      inventory[key] = value;
    }
    argv++;
  }
  return inventory;
}

int main(int argc, char **argv)
{
  if (argc < 2)
    std::cout << "No arguments supplided. Usage: <item>:<quantity>"
              << std::endl;
  else
  {
    std::cout << "=== Inventory System Analysis ===" << std::endl;
    std::map<std::string, int> inventory;
    inventory = ft_parse_args(argv + 1);
    int total_items = get_total_items(inventory);
    std::cout << "Total items in inventory: " << total_items << std::endl;
    std::cout << "Unique item types: " << inventory.size() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Current Inventory ===" << std::endl;
    for (const auto &key_value : inventory)
      std::cout << key_value.first << ": " << key_value.second << std::setprecision(3) << " ("
       << (static_cast<double>(key_value.second) / static_cast<double>(total_items)) * 100
       << "%)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Inventory Statistics ===" << std::endl;
    //inventory.max
    //for (const auto &key_value : inventory)
      //std::cout << key_value;
  }
  return 0;
}

/*   Iteration over basic dictionary (C++ 17 style)
for (const auto& [key, value] : alice)
    std::cout << key << " -> " << value << std::endl;

//labda function usage over for loop in
// int get_total_items(std::map<std::string, int> &inventory)
// function
int total_value = std::accumulate(inventory.begin(), inventory.end(), 0,                                      // initial sum
[](int sum, const std::pair<const std::string,int>& key_value)
{
    return sum + key_value.second;
});

std::map<std::string, ItemInfo> alice = {
    {"sword", {1, "weapon", "rare", 500}},
    {"potion", {5, "consumable", "common", 50}},
    {"shield", {1, "armor", "uncommon", 200}}};

std::map<std::string, ItemInfo> bob = {
    {"potion", {0, "consumable", "common", 50}}};

std::cout << "=== Alice's Inventory ===" << std::endl;
for (const auto &key : alice)
  std::cout << " - " << key.first << " (" << key.second.type << ", "
            << key.second.rarity << "): " << key.second.quantity << "x "
            << "@ " << key.second.value
            << " gold each = " << key.second.quantity * key.second.value
            << " gold" << std::endl;

            //for (const auto &key_value : inventory)
             //   std::cout << key_value.first << " -> " << key_value.second << std::endl;

            C++ 17 style
            for (auto const &[item, count] : dict)
              std::cout << item << " -> " << count << std::endl;

*/
