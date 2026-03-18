#include "SafePlant.h"

int main(int argc, char** argv)
{
    printf("=== Garden Security System ===\n");
    SafePlant rose = {.init = SafePlant_ctor, .deinit = SafePlant_dtor,
                      .set_height = SafePlant_set_height, .set_age = SafePlant_set_age,
                      .get_height = SafePlant_get_height, .get_age = SafePlant_get_age,
                      .get_info = SafePlant_get_info};
    rose.init(&rose ,"Rose", 25, 30);
    rose.set_height(&rose, 25);
    rose.set_age(&rose, 30);
    rose.set_height(&rose, -5);
    printf("Current plant: ");
    rose.get_info(&rose);
    rose.deinit(&rose);
    return 0;
}
