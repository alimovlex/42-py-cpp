//
// Created by robot on 3/12/26.
//

#include "Tree.h"

void Tree_ctor(Tree* this, char* name, int height, int days, int trunk_diameter)
{
    Plant_ctor(&this->super, name, height, days);
    this->name = strdup(name);
    this->height = height;
    this->days = days;
    this->trunk_diameter = trunk_diameter;
    printf("%s (Flower): %d cm, %d days, %d cm diameter\n", name, height, days, trunk_diameter);
}

void Tree_produce_shade(Tree* this)
{
    printf("%s provides %f square meters of shade\n", this->name, (pow(this->trunk_diameter, 2) * M_PI)/ 4);
}

void Tree_dtor(Tree* this)
{
    free(this->name);
}
