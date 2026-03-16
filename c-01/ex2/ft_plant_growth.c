#include "Plant.h"

int main(int argc, char** argv)
{
    Plant rose;
    Plant_ctor(&rose,"Rose", 25, 30);
    printf("=== Day 1 ===\n");
    Plant_get_info(&rose);
    int first_day_height = rose.height;
    printf("=== Day 7 ===\n");
    Plant_grow(&rose, 6);
    Plant_age(&rose, 6);
    Plant_get_info(&rose);
    printf("Growth this week: +%d cm\n", rose.height - first_day_height);
    Plant_dtor(&rose);
    return 0;
}
