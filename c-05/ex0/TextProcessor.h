//
// Created by robot on 3/12/26.
//

#pragma once
#include "DataProcessor.h"

typedef struct TextProcessor TextProcessor;

struct TextProcessor
{
    DataProcessor super;
    char* (*process)(DataProcessor* this, void* data);
    bool (*validate)(DataProcessor* this, void* data);
    char* (*format_output)(DataProcessor* this, char* result);
};

static char* process(DataProcessor* this, void* data);
static bool validate(DataProcessor* this, void* data);
static char* format_output(DataProcessor* this, char* result);

/*
class TextProcessor : public DataProcessor
{
public:
    std::string process(const std::any &data) override;
    bool validate(const std::any &data) override;
    std::string format_output(const std::string &result) override;
};
*/

