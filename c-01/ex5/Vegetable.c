//
// Created by robot on 3/12/26.
//

#include "Vegetable.h"

void Vegetable_ctor(Vegetable* this, char* name, int height, int days, char* harvest_season, char* nutritional_value)
{
    Plant_ctor(&this->super, name, height, days);
    this->name = strdup(name);
    this->height = height;
    this->days = days;
    this->harvest_season = strdup(harvest_season);
    this->nutritional_value = strdup(nutritional_value);
    printf("%s (Vegetable): %d cm, %d days %s is reach in %s\n", name, height, days, harvest_season, nutritional_value);
}

void Vegetable_dtor(Vegetable* this)
{
    free(this->name);
    free(this->harvest_season);
    free(this->nutritional_value);
}