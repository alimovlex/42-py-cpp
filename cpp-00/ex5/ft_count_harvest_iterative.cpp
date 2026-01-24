#include <iostream>

void ft_count_harvest_iterative()
{
    int days = 0;
    std::cout << "Days until harvest: ";
    std::cin >> days;
    int i = 1;
    while(i <= days)
    {
        std::cout << "Day " << i;
        std::cout << std::endl;
        i++;
    }
    std::cout << "Harvest time!";
    std::cout << std::endl;
}

int main(void)
{
    ft_count_harvest_iterative();
    return 0;
}
