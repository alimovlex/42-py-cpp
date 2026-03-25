//
// Created by robot on 3/12/26.
//

#pragma once
#include "DataProcessor.h"

typedef struct NumericProcessor NumericProcessor;

struct NumericProcessor
{
    DataProcessor super;
    char* (*process)(DataProcessor* this, void* data);
    bool (*validate)(DataProcessor* this, void* data);
    char* (*format_output)(DataProcessor* this, char* result);
    void (*init)(NumericProcessor* this);
};

static char* process(DataProcessor* this, void* data);
static bool validate(DataProcessor* this, void* data);
static char* format_output(DataProcessor* this, char* result);
void NumericProcessor_ctor(NumericProcessor* this);

/*
class NumericProcessor : public DataProcessor
{
public:
    std::string process(const std::any &data) override;
    bool validate(const std::any &data) override;
    std::string format_output(const std::string &result) override;
};
*/