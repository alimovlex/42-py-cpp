//
// Created by robot on 3/12/26.
//

#pragma once
#include "DataProcessor.h"

typedef struct LogProcessor LogProcessor;

struct LogProcessor
{
    DataProcessor super;
    char* (*process)(DataProcessor* this, void* data);
    bool (*validate)(DataProcessor* this, void* data);
    char* (*format_output)(DataProcessor* this, char* result);
};

static char* process(DataProcessor* this, void* data);
static bool validate(DataProcessor* this, void* data);
static char* format_output(DataProcessor* this, char* result);


