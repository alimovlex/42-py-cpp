//
// Created by alalimov on 3/16/26.
//

#include "Plant.h"

void Plant_ctor(Plant *this, char *name, int height, int days)
{
    this->name = strdup(name);
    this->height = height;
    this->days = days;
}

void Plant_dtor(Plant* this)
{
    free(this->name);
}