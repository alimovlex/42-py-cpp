#include <iostream>

void ft_count_harvest_recursive() {
    static int day   = 1;
    static int limit = -1;

    if (limit == -1) {
        std::cout << "Days until harvest: ";
        std::cin >> limit;
    }

    if (day > limit) {
        std::cout << "Harvest time!" << std::endl;
        day   = 1;
        limit = -1;
        return;
    }

    std::cout << "Day " << day << std::endl;
    day++;
    ft_count_harvest_recursive();
}

int main(void)
{
    ft_count_harvest_recursive();
    return 0;
}
