#include <stdio.h>

void ft_plant_age()
{
    int days = 0;
    printf("Enter plant age in days: ");
    scanf("%d", &days);
    if (days > 60)
        printf("Plant is ready to harvest!\n");
    else
     printf("Plant needs more time to grow.\n");
}

int main(void)
{
    ft_plant_age();
    return 0;
}
