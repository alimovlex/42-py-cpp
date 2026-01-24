#include <iostream>

void ft_plot_area()
{
    int length, width, area;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter width: ";
    std::cin >> width;
    area = width * length;
    std::cout << "Plot area: " << area;
    std::cout << std::endl;
}

int main(void)
{
    ft_plot_area();
    return 0;
}
