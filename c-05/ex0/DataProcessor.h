//
// Created by robot on 3/12/26.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "template_functions.h"

typedef struct DataProcessor DataProcessor;
typedef struct DataProcessorVTable DataProcessorVTable;

struct DataProcessor
{
    struct DataProcessorVTable const *vtable;
    void* data;
    char* result;
};

struct DataProcessorVTable
{
    char* (*process)(DataProcessor* this, void* data);
    bool (*validate)(DataProcessor* this, void* data);
    char* (*format_output)(DataProcessor* this, char* result);
};

static inline char* DataProcessor_process(DataProcessor* this, void* data)
{
    return this->vtable->process(this, data);
}

static inline bool DataProcessor_validate(DataProcessor* this, void* data)
{
    return this->vtable->validate(this, data);
}

static inline char* DataProcessor_format_output(DataProcessor* this, char* result)
{
    return this->vtable->format_output(this, result);
}

/*
class DataProcessor
{
public:
    std::any data;
    std::string result;
    virtual std::string process(const std::any& data) = 0;
    virtual bool        validate(const std::any& data) = 0;

    virtual std::string format_output(const std::string& result) { return result; }

    virtual ~DataProcessor() = default;
};
 */