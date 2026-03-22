//
// Created by robot on 3/12/26.
//

#pragma once
#include "DataProcessor.h"

typedef struct TextProcessor TextProcessor;

struct TextProcessor
{
    DataProcessor super;
    char (*process)(TextProcessor* this, void* data);
    bool (*validate)(TextProcessor* this, void* data);
    char (*format_output)(TextProcessor* this, char* result);
};

char* TextProcessor_process(TextProcessor* this, void* data);
bool TextProcessor_validate(TextProcessor* this, void* data);
char* TextProcessor_format_output(TextProcessor* this, char* result);


/*
class TextProcessor : public DataProcessor
{
public:
    std::string process(const std::any &data) override;
    bool validate(const std::any &data) override;
    std::string format_output(const std::string &result) override;
};
*/

