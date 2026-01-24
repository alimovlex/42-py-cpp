#include <iostream>

void ft_water_reminder()
{
    int days = 0;
    std::cout << "Days since last watering: ";
    std::cin >> days;
    if (days > 2)
        std::cout << "Water the plants!";
    else
     std::cout << "Plants are fine";
    std::cout << std::endl;
}

int main(void)
{
    ft_water_reminder();
    return 0;
}
