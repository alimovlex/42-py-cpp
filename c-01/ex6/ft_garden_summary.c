#include <stdio.h>

void ft_garden_summary()
{
 char name[100];
 int plants_num = 0;
 printf("Enter garden name: ");
 scanf("%99[^\n]s", name);
 printf("Enter number of plants: ");
 scanf("%d", &plants_num);
 printf("Garden: %s\n", name);
 printf("Plants: %d\n", plants_num);
 printf("Status: Growing well!\n");
}

int main(void)
{
    ft_garden_summary();
    return 0;
}
