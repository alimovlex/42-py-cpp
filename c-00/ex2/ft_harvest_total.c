#include <stdio.h>

void ft_harvest_total()
{
    int day = 0, total = 0;
    printf("Day 1 harvest: ");
    scanf("%d", &day);
    total += day;
    printf("Day 2 harvest: ");
    scanf("%d", &day);
    total += day;
    printf("Day 3 harvest: ");
    scanf("%d", &day);
    total += day;
    printf("Total harvest: %d\n", total);
}

int main(void)
{
    ft_harvest_total();
    return 0;
}
