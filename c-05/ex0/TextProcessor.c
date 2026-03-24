//
// Created by robot on 3/12/26.
//

#include "TextProcessor.h"

static const DataProcessorVTable TextProcessorVTable = {
        .process = process,
        .validate = validate,
        .format_output = format_output
};

static char* process(DataProcessor* this, void* data)
{
    this->data = data;
    char *str = strcat("Processing data: ", (char*)data);
    if (!str)
        return "Type error: expected char*";
    else
        return str;
}

static bool validate(DataProcessor* this, void* data)
{
    this->data = data;
    char* str = (char*)data;
    if (!str)
        return false;
    else
    {
        printf("Validation: Text data verified\n");
        return true;
    }
}
//TODO: FINISH THIS METHOD!!!
static char* format_output(DataProcessor* this, char* result) {
    this->result = result;
    int len = 0, nbr_of_words = 0;
    char *text_data = (char *) this->data;
    char *str = "Output: Processed ";
    if (!text_data)
        return "It has to be a string!";
    else
    {
        while(*text_data)
        {
            if (*text_data == ' ')
                nbr_of_words++;
            len++;
            text_data++;
        }
        int i = nbr_of_words;
        while(i--)
            text_data--;
        if (len > 0)
            nbr_of_words++;
        sprintf(str,"%d", len);
        sprintf(str, "%s", " characters, ");
        sprintf(str,"%d", nbr_of_words);
        sprintf(str, "%s", " words");
        /*
        size_t length_text = text_data->length();
        size_t nbr_of_words = 0;
        std::string str = "Output: Processed ";

        for (char char_ : *text_data)
        {
            if (char_ == ' ')
                nbr_of_words++;
        }
        if (length_text > 0)
            nbr_of_words++;

        str += std::to_string(length_text);
        str += " characters, ";
        str += std::to_string(nbr_of_words);
        str += " words";
         */
        return str;
    }
}
/*
std::string TextProcessor::process(const std::any &data)
{
    this->data = data;
    if (auto str = std::any_cast<std::string>(&data))
        return "Processing data: " + *str;
    else
        return "Type error: expected std::string";
}

bool TextProcessor::validate(const std::any &data)
{
    this->data = data;
    bool checker = (data.type() == typeid(std::string));
    if (checker)
        std::cout << "Validation: Text data verified" << std::endl;
    return checker;
}

std::string TextProcessor::format_output(const std::string &result)
{
    this->result = result;

    if (auto text_data = std::any_cast<std::string>(&this->data))
    {
        size_t length_text = text_data->length();
        size_t nbr_of_words = 0;
        std::string str = "Output: Processed ";

        for (char char_ : *text_data)
        {
            if (char_ == ' ')
                nbr_of_words++;
        }
        if (length_text > 0)
            nbr_of_words++;

        str += std::to_string(length_text);
        str += " characters, ";
        str += std::to_string(nbr_of_words);
        str += " words";
        return str;
    }
    else
        return "It has to be a string!";
}
 */