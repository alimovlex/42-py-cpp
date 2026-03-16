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
    int height, age;
}Plant;

void Plant_ctor(Plant *this, char *name, int height, int age);
void Plant_dtor(Plant *this);