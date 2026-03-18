#include "Plant.h"

int main(int argc, char** argv)
{
    Plant rose = {.init = Plant_ctor, .deinit = Plant_dtor,
                  .grow = Plant_grow, .age = Plant_age, .get_info = Plant_get_info };
    rose.init(&rose,"Rose", 25, 30);
    printf("=== Day 1 ===\n");
    rose.get_info(&rose);
    int first_day_height = rose.height;
    printf("=== Day 7 ===\n");
    rose.grow(&rose, 6);
    rose.age(&rose, 6);
    rose.get_info(&rose);
    printf("Growth this week: +%d cm\n", rose.height - first_day_height);
    rose.deinit(&rose);
    return 0;
}
