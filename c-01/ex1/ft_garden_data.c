#include <stdio.h>
#include "Plant.h"

int main(int argc, char** argv)
{
    printf("=== Garden Plant Registry ===\n");
    Plant rose = {.init = Plant_ctor, .deinit = Plant_dtor};
    Plant sunflower = {.init = Plant_ctor, .deinit = Plant_dtor};
    Plant cactus = {.init = Plant_ctor, .deinit = Plant_dtor};

    rose.init(&rose ,"Rose", 25, 30);
    sunflower.init(&sunflower,"Sunflower", 80, 45);
    cactus.init(&cactus,"Cactus", 15, 120);

    rose.deinit(&rose);
    sunflower.deinit(&sunflower);
    cactus.deinit(&cactus);
    return 0;
}
