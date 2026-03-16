#include <stdio.h>
#include "Plant.h"

int main(int argc, char** argv)
{
    printf("=== Garden Plant Registry ===\n");
    Plant rose, sunflower, cactus;

    Plant_ctor(&rose ,"Rose", 25, 30);
    Plant_ctor(&sunflower,"Sunflower", 80, 45);
    Plant_ctor(&cactus,"Cactus", 15, 120);

    Plant_dtor(&rose);
    Plant_dtor(&sunflower);
    Plant_dtor(&cactus);
    return 0;
}
