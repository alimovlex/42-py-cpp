//
// Created by robot on 3/12/26.
//

#pragma once
#include "DataProcessor.h"

typedef struct LogProcessor LogProcessor;

struct LogProcessor
{
    DataProcessor super;
    char (*process)(LogProcessor* this, void* data);
    bool (*validate)(LogProcessor* this, void* data);
    char (*format_output)(LogProcessor* this, char* result);
};

char* LogProcessor_process(LogProcessor* this, void* data);
bool LogProcessor_validate(LogProcessor* this, void* data);
char* LogProcessor_format_output(LogProcessor* this, char* result);


