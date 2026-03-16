#include "Plant.h"

int main(int argc, char** argv)
{
    printf("=== Plant Factory Output ===\n");
    Plant rose, oak, cactus, sunflower, fern;
    Plant_ctor(&rose,"Rose", 25, 30);
    Plant_ctor(&oak ,"Oak", 200, 365);
    Plant_ctor(&cactus ,"Cactus", 5, 90);
    Plant_ctor(&sunflower ,"Sunflower", 80, 45);
    Plant_ctor(&fern ,"Fern", 15, 120);

    size_t total_plant = Plant_get_objects_count();
    printf("Total plants created: %zu\n", total_plant);

    Plant_dtor(&rose);
    Plant_dtor(&oak);
    Plant_dtor(&cactus);
    Plant_dtor(&sunflower);
    Plant_dtor(&fern);
    return 0;
}
