#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ft_seed_inventory(char* seed_type, int quantity, char* unit)
{
    char seed_name[64];
    strncpy(seed_name, seed_type, sizeof(seed_name) - 1);
    seed_name[sizeof(seed_name) - 1] = '\0';
    seed_name[0] = (char) toupper((unsigned char)seed_name[0]);
    if (!strcmp(unit, "packets"))
        printf("%s seeds: %d %s available\n", seed_name, quantity, unit);
    else if(!strcmp(unit, "grams"))
        printf("%s seeds: %d %s total\n", seed_name, quantity, unit);
    else if (!strcmp(unit, "area"))
    {
        unit = "square meters";
        printf("%s seeds: covers %d %s\n", seed_name, quantity, unit);
    }
    else
        printf("Unknown unit type\n");
}

int main(void)
{
    ft_seed_inventory("tomato", 15, "packets");
    ft_seed_inventory("carrot", 8, "grams");
    ft_seed_inventory("lettuce", 12,"area");
    return 0;
}
