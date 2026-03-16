//
// Created by robot on 3/12/26.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct
{
    char* name;
    int height, days;
}Plant;

void Plant_ctor(Plant* this, char* name, int height, int days);
void Plant_dtor(Plant* this);
