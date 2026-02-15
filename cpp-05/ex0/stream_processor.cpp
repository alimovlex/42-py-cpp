#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <any>

template<typename T>
void iterate_any(const std::any& data, std::string& str, bool& checker)
{
    if (auto container = std::any_cast<const T>(&data))
    {
        for (const auto& elem : *container)
        {
            if (auto num = std::any_cast<int>(elem))
            {
                str += std::to_string(num) + " ";
                checker = true;
            }
            else
            {
                throw std::invalid_argument("All elements have to be integers");
                checker = false;
            }
        }
    }
    else
        std::cout << "Type mismatch" << std::endl;
}

template<typename T>
auto accumulate_any(const std::any& data)
{
    if (auto container = std::any_cast<const T>(&data))
    {
        using ValueType = typename T::value_type;
        return std::accumulate(
            container->begin(),
            container->end(),
            ValueType{}
        );
    }

    throw std::bad_any_cast();
}

size_t get_size(const std::any& data)
{
    if (auto vec = std::any_cast<std::vector<int>>(&data))
        return vec->size();
    else if (auto str = std::any_cast<std::string>(&data))
        return str->size();
    else
        return 0;
}

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

class NumericProcessor : public DataProcessor
{
    public:
    std::string process(const std::any &data) override
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

    bool validate(const std::any &data) override
    {
        this->data = data;
        bool checker = true;
        std::string str;
        iterate_any<std::vector<int>>(data, str, checker);
        if (checker)
            std::cout << "Validation: Numeric data verified" << std::endl;
        return checker;
    }

    std::string format_output(const std::string &result) override
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
};

class TextProcessor : public DataProcessor
{
    public:
    std::string process(const std::any &data) override
    {
        this->data = data;
        if (auto str = std::any_cast<std::string>(&data))
            return "Processing data: " + *str;
        else
            return "Type error: expected std::string";
    }

    bool validate(const std::any &data) override
    {
        this->data = data;
        bool checker = (data.type() == typeid(std::string));
        if (checker)
            std::cout << "Validation: Text data verified" << std::endl;
        return checker;
    }

    std::string format_output(const std::string &result) override
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
};

class LogProcessor : public DataProcessor
{
    public:
    std::string process(const std::any &data) override
    {
        this->data = data;
        std::string str;
        try 
        {
        if (auto text_data = std::any_cast<std::string>(&this->data))
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

    bool validate(const std::any &data) override
    {
        this->data = data;
        bool checker = (data.type() == typeid(std::string));
        if (checker)
            std::cout << "Validation: Log entry verified" << std::endl;
        return checker;
    }

    std::string format_output(const std::string &result) override
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
};

int test_data_processor(std::unique_ptr<DataProcessor>& test, const std::any& data)
{
    bool value = test->validate(data);
    std::ostringstream oss;
    oss << std::boolalpha << value;
    std::string result = oss.str();
    std::cout << test->process(data) << std::endl;
    std::cout << result << std::endl;
    std::cout << test->format_output("hello") << std::endl;
    return 0;
}

int main()
{
    std::unique_ptr<DataProcessor> test;

    std::vector<int> list_data = {1, 2, 3, 4, 5};
    std::vector<int> new_list_data = {1, 2, 3};
    std::string str_data = "Hello Nexus World",
    data_log = "INFO: System ready, ERROR", new_str_data = "helloo Nexus",
    new_data_log = "System ready";
    std::vector<std::any> test_data = {new_list_data, new_str_data, new_data_log};

    std::cout << "=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n" << std::endl;
    std::cout << "Initializing Numeric Processor..." << std::endl;
    test = std::make_unique<NumericProcessor>();
    test_data_processor(test, list_data);

    std::cout << "Initializing Text Processor..." << std::endl;
    test = std::make_unique<TextProcessor>();
    test_data_processor(test, str_data);

    std::cout << "Initializing Log Processor..." << std::endl;
    test = std::make_unique<LogProcessor>();
    test_data_processor(test, data_log);
    std::cout << std::endl;

    std::cout << "=== Polymorphic Processing Demo ===\n" << std::endl;
    std::cout << "Processing multiple data types through same interface..." << std::endl;

    std::vector<std::unique_ptr<DataProcessor>> polymorf_all;
    std::vector<std::unique_ptr<DataProcessor>>::iterator i;

    polymorf_all.push_back(std::make_unique<NumericProcessor>());
    polymorf_all.push_back(std::make_unique<TextProcessor>());
    polymorf_all.push_back(std::make_unique<LogProcessor>());
    auto itr1 = polymorf_all.begin();
    auto itr2 = test_data.begin();

    for (; itr1 != polymorf_all.end() && itr2 != test_data.end(); ++itr1, ++itr2)
        test_data_processor(*itr1, *itr2);
    /*
    for (auto& processor: polymorf_all)
        for(auto& data: test_data)
            test_data_processor(processor, data);
    */

    std::cout << "Foundation system online. Nexus ready for advanced streams." << std::endl;

    return 0;
}

/*
std::unique_ptr<DataProcessor> test = std::make_unique<NumericProcessor>();
std::unique_ptr<NumericProcessor> test(new NumericProcessor); //old form of definition
DataProcessor* test = new NumericProcessor(); //old form of definition
test = new TextProcessor();
delete test;
test = new LogProcessor();
delete test;
test = nullptr;


if (auto str_ptr = std::any_cast<std::string>(&data)) {
    std::cout << *str_ptr << "\n"; // str_ptr is non-null if cast succeeds
} else {
    std::cout << "data is not a string\n";
}
*/
