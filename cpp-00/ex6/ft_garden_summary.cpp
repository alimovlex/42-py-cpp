#include <iostream>
#include <cstring>
#include <string>

void ft_garden_summary()
{
 std::string name;
 int plants_num = 0;
 std::cout << "Enter garden name: ";
 std::getline(std::cin, name);
 std::cout << "Enter number of plants: ";
 std::cin >> plants_num;
 std::cout << "Garden: " << name << std::endl;
 std::cout << "Plants: " << plants_num << std::endl;
 std::cout << "Status: Growing well!" << std::endl;
}

int main(void)
{
    ft_garden_summary();
    return 0;
}
