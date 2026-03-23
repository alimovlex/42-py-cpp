//
// Created by robot on 3/12/26.
//

#include "NumericProcessor.h"

static const DataProcessorVTable NumericProcessorVTable = {
        .process = process,
        .validate = validate,
        .format_output = format_output
};
//TODO: FINISH THIS METHOD!!!
static char* process(DataProcessor* this, void* data)
{
    this->data = data;
    bool checker;
    char* str = NULL;
    char* output = NULL;
    iterate_any(data, &checker, output);
    strcat(output, "Processing data: ");
    strcat(output, str);
    return output;
}
//TODO: FINISH THIS METHOD!!!
static bool validate(DataProcessor* this, void* data)
{
    this->data = data;
    bool checker;
    char* str = NULL;
    iterate_any(data, &checker, str);
    if (checker)
        printf("Validation: Numeric data verified\n");
    return checker;
}
//TODO: FINISH THIS METHOD!!!
static char* format_output(DataProcessor* this, char* result)
{
    return "";
}

/*
std::string NumericProcessor::process(const std::any &data)
{
    this->data = data;
    std::string str;
    bool checker;
    try
    {
        iterate_any<std::vector<int>>(data, str, checker);
    }
    catch (const std::bad_any_cast& e)
    {
        return e.what();
    }
    catch (const std::invalid_argument& e)
    {
        return e.what();
    }
    catch (const std::exception& e)
    {
        return e.what();
    }

    return str.insert(0, "Processing data: ");
}

bool NumericProcessor::validate(const std::any &data)
{
    this->data = data;
    bool checker = true;
    std::string str;
    iterate_any<std::vector<int>>(data, str, checker);
    if (checker)
        std::cout << "Validation: Numeric data verified" << std::endl;
    return checker;
}

std::string NumericProcessor::format_output(const std::string &result)
{
    try
    {
        this->result = result;
        int length_data = get_size(data);
        int sum_data = accumulate_any<std::vector<int>>(data);
        int average = sum_data / length_data;
        std::string str = "Output: Processed ";
        str += std::to_string(length_data);
        str += " numeric values, sum= ";
        str += std::to_string(sum_data);
        str += ", avg=";
        str += std::to_string(average);
        return str;
    }
    catch (const std::invalid_argument& e)
    {
        return e.what();
    }
}
 */
