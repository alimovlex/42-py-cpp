#include <iostream>

void ft_harvest_total()
{
    int day = 0, total = 0;
    std::cout << "Day 1 harvest: ";
    std::cin >> day;
    total += day;
    std::cout << "Day 2 harvest: ";
    std::cin >> day;
    total += day;
    std::cout << "Day 3 harvest: ";
    std::cin >> day;
    total += day;
    std::cout << "Total harvest: " << total;
    std:: cout << std::endl;
}

int main(void)
{
    ft_harvest_total();
    return 0;
}
