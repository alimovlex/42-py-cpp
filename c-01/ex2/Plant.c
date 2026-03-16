//
// Created by robot on 3/12/26.
//

#include "Plant.h"

void Plant_ctor(Plant *this, char *name, int height, int days)
{
    this->name = strdup(name);
    this->height = height;
    this->days = days;

    printf("%s: %dcm, %d days old\n", this->name, this->height, this->days);
}

void Plant_dtor(Plant* this)
{
    free(this->name);
}

void Plant_grow(Plant* this, int cm)
{
    this->height += cm;
}

void Plant_age(Plant* this, int duration)
{
    this->days+=duration;
}

void Plant_get_info(Plant* this)
{
    printf("%s: %dcm, %d days old\n", this->name, this->height, this->days);
}