#include "Plant.h"

int main(int argc, char** argv)
{
    printf("=== Plant Factory Output ===\n");
    Plant rose = {.init = Plant_ctor, .deinit = Plant_dtor, .get_objects_count = Plant_get_objects_count };
    Plant oak = {.init = Plant_ctor, .deinit = Plant_dtor, .get_objects_count = Plant_get_objects_count };
    Plant cactus = {.init = Plant_ctor, .deinit = Plant_dtor, .get_objects_count = Plant_get_objects_count };
    Plant sunflower = {.init = Plant_ctor, .deinit = Plant_dtor, .get_objects_count = Plant_get_objects_count };
    Plant fern = {.init = Plant_ctor, .deinit = Plant_dtor, .get_objects_count = Plant_get_objects_count };
    rose.init(&rose,"Rose", 25, 30);
    oak.init(&oak ,"Oak", 200, 365);
    cactus.init(&cactus ,"Cactus", 5, 90);
    sunflower.init(&sunflower ,"Sunflower", 80, 45);
    fern.init(&fern ,"Fern", 15, 120);

    size_t total_plant = Plant_get_objects_count();
    printf("Total plants created: %zu\n", total_plant);

    rose.deinit(&rose);
    oak.deinit(&oak);
    cactus.deinit(&cactus);
    sunflower.deinit(&sunflower);
    fern.deinit(&fern);
    return 0;
}
