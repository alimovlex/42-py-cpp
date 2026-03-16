//
// Created by robot on 3/12/26.
//

#include "Plant.h"

void Plant_ctor(Plant *this, char *name, int height, int age)
{
    this->name = strdup(name);
    this->height = height;
    this->age = age;

    printf("%s: %dcm, %d days old\n", this->name, this->height, this->age);
}

void Plant_dtor(Plant* this)
{
    free(this->name);
}