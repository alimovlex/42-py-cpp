//
// Created by robot on 3/12/26.
//

#include "Flower.h"

void Flower_ctor(Flower* this, char* name, int height, int days, char* color)
{
    Plant_ctor(&this->super, name, height, days);
    this->name = strdup(name);
    this->height = height;
    this->days = days;
    this->color = color;

    printf("%s (Flower): %d cm, %d days, %s color\n", name, height, days, color);
}

void Flower_bloom(Flower* this)
{
     printf("%s is blooming beautifully!\n", this->name);
}

void Flower_dtor(Flower* this)
{
    free(this->name);
}

