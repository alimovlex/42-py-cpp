//
// Created by robot on 3/12/26.
//

#pragma once
#include "DataProcessor.h"

typedef struct NumericProcessor NumericProcessor;

struct NumericProcessor
{
    DataProcessor super;
    char* (*process)(NumericProcessor* this, void* data);
    bool (*validate)(NumericProcessor* this, void* data);
    char* (*format_output)(NumericProcessor* this, char* result);
};

char* NumericProcessor_process(NumericProcessor* this, void* data);
bool NumericProcessor_validate(NumericProcessor* this, void* data);
char* NumericProcessor_format_output(NumericProcessor* this, char* result);

/*
class NumericProcessor : public DataProcessor
{
public:
    std::string process(const std::any &data) override;
    bool validate(const std::any &data) override;
    std::string format_output(const std::string &result) override;
};
*/