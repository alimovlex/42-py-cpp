//
// Created by robot on 3/12/26.
//

#include "TextProcessor.hpp"

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