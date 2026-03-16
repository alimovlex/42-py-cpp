//
// Created by robot on 3/12/26.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct
{
    char* name;
    int height, age;
}Plant;
static int instance_count;
void Plant_ctor(Plant *this, char *name, int height, int age);
void Plant_dtor(Plant* this);
size_t Plant_get_objects_count();
