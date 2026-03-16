#include <stdio.h>

void ft_water_reminder()
{
    int days = 0;
    printf("Days since last watering: ");
    scanf("%d", &days);
    if (days > 2)
        printf("Water the plants!\n");
    else
        printf("Plants are fine\n");
}

int main(void)
{
    ft_water_reminder();
    return 0;
}
