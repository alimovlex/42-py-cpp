//
// Created by robot on 3/12/26.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char* name;
    int height, days;
}Plant;

void Plant_ctor(Plant *this, char *name, int height, int age);
void Plant_dtor(Plant *this);
void Plant_grow(Plant *this, int cm);
void Plant_age(Plant *this, int duration);
void Plant_get_info(Plant *this);
