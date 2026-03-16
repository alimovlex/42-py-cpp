#include <stdio.h>

void ft_plot_area()
{
    int length, width, area;
    printf("Enter length: ");
    scanf("%d", &length);
    printf("Enter width: ");
    scanf("%d", &width);
    area = width * length;
    printf("Plot area: %d\n", area);
}

int main(void)
{
    ft_plot_area();
    return 0;
}
