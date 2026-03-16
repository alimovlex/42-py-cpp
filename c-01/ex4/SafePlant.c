//
// Created by robot on 3/12/26.
//

#include "SafePlant.h"

void SafePlant_ctor(SafePlant *this, char *name, int height, int age)
{
    this->name = strdup(name);
    this->height = height;
    this->age = age;
    printf("Plant Created: %s\n", this->name);
}

void SafePlant_set_height(SafePlant *this, int new_height)
{
    if (new_height < 0)
    {
        printf("Invalid operation attempted: %d cm [REJECTED]\n", new_height);
        printf("Security: Negative height rejected\n");
    }
    else
    {
        this->height = new_height;
        printf("Height updated: %d cm [OK]\n", this->height);
    }
}

void SafePlant_set_age(SafePlant *this, int new_age)
{
    if (new_age < 0)
    {
        printf("Invalid operation attempted: %d days [REJECTED]\n", new_age);
        printf("Security: Negative age rejected\n");
    }
    else
    {
        this->age = new_age;
        printf("Age updated: %d days [OK]\n", this->age);
    }
}

int SafePlant_get_height(SafePlant *this)
{
    return this->height;
}

int SafePlant_get_age(SafePlant *this)
{
    return this->age;
}

void SafePlant_get_info(SafePlant *this)
{
    printf("%s: %dcm, %d days\n", this->name, this->height, this->age);
}

void SafePlant_dtor(SafePlant* this)
{
    free(this->name);
}
