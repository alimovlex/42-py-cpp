//
// Created by robot on 3/12/26.
//
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SafePlant SafePlant;

struct SafePlant
{
    char* name;
    int height, age;

    void (*init)(SafePlant *this, char *name, int height, int age);
    void (*deinit)(SafePlant *this);
    void (*set_height)(SafePlant* self, int new_height);
    void (*set_age)(SafePlant* self, int new_age);
    int (*get_height)(SafePlant* self);
    int (*get_age)(SafePlant* self);
    void (*get_info)(SafePlant* self);
};

void SafePlant_ctor(SafePlant* self, char* name, int height, int age);
void SafePlant_dtor(SafePlant* this);
void SafePlant_set_height(SafePlant* self, int new_height);
void SafePlant_set_age(SafePlant* self, int new_age);
int SafePlant_get_height(SafePlant* self);
int SafePlant_get_age(SafePlant* self);
void SafePlant_get_info(SafePlant* self);