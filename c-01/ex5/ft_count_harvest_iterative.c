#include <stdio.h>

void ft_count_harvest_iterative()
{
    int days = 0;
    printf("Days until harvest: ");
    scanf("%d", &days);
    int i = 1;
    while(i <= days)
    {
        printf("Day %d\n", i);
        i++;
    }
    printf("Harvest time!\n");
}

int main(void)
{
    ft_count_harvest_iterative();
    return 0;
}
