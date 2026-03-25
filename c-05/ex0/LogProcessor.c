//
// Created by robot on 3/12/26.
//

#include "LogProcessor.h"

static const DataProcessorVTable LogProcessorVTable = {
        .process = process,
        .validate = validate,
        .format_output = format_output
};
//TODO: FINISH THIS METHOD!!!
static char* process(DataProcessor* this, void* data)
{
    return "";
}
//TODO: FINISH THIS METHOD!!!
static bool validate(DataProcessor* this, void* data)
{
    return true;
}
//TODO: FINISH THIS METHOD!!!
static char* format_output(DataProcessor* this, char* result)
{
    return "";
}

void LogProcessor_ctor(LogProcessor* this)
{
    this->super.vtable = &LogProcessorVTable;
}

/*
std::string LogProcessor::process(const std::any &data)
{
    this->data = data;
    std::string str;
    try
    {
        if (auto text_data = std::any_cast<std::string>(&data))
        {
            str = *text_data;
            if (str.find("ERROR") != std::string::npos)
                throw std::runtime_error("Connection timeout");
        }
    }
    catch (const std::exception& e)
    {
        return e.what();
    }
    return str.insert(0, "Processing data: ");
}

bool LogProcessor::validate(const std::any &data)
{
    this->data = data;
    bool checker = (data.type() == typeid(std::string));
    if (checker)
        std::cout << "Validation: Log entry verified" << std::endl;
    return checker;
}

std::string LogProcessor::format_output(const std::string &result)
{
    this->result = result;
    std::string str, str_err = "Output: [ALERT] ERROR level detected: Connection timeout";
    if (auto text_data = std::any_cast<std::string>(&this->data))
    {
        str = *text_data;
        if (str.find("ERROR") != std::string::npos)
            return str_err;
        else
            return str.insert(0, "Output: [INFO] INFO level detected: ");
        return str;
    }
    else
        return "";
}
 */
