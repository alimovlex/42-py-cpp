#include <stdio.h>

void ft_count_harvest_recursive()
{
    static int day   = 1;
    static int limit = -1;

    if (limit == -1)
    {
        printf("Days until harvest: ");
        scanf("%d", &limit);
    }

    if (day > limit)
    {
        printf("Harvest time!\n");
        day   = 1;
        limit = -1;
        return;
    }

    printf("Day %d\n", day);
    day++;
    ft_count_harvest_recursive();
}

int main(void)
{
    ft_count_harvest_recursive();
    return 0;
}
