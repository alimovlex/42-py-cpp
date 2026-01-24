#include <iostream>

void ft_plant_age()
{
    int days = 0;
    std::cout << "Enter plant age in days: ";
    std::cin >> days;
    if (days > 60)
        std::cout << "Plant is ready to harvest!";
    else
     std::cout << "Plant needs more time to grow.";
    std::cout << std::endl;
}

int main(void)
{
    ft_plant_age();
    return 0;
}
