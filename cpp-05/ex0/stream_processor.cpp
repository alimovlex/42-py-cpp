#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <any>

class DataProcessor
{
    public:
    std::any data;
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
        try
        {

        }
        catch (const std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
        }
        /*
        catch (const std::exception& e)
        {
            //std::cout << e.what() << std::endl;
        }
        */
        return "";
    }

    bool validate(const std::any &data) override
    {

    }
};

class TextProcessor : public DataProcessor
{
    public:
    std::string process(const std::any &data) override
    {

    }

    bool validate(const std::any &data) override
    {

    }

    std::string format_output(const std::string &result) override
    {

    }
};

class LogProcessor : public DataProcessor
{
    public:
    std::string process(const std::any &data) override
    {

    }

    bool validate(const std::any &data) override
    {

    }

    std::string format_output(const std::string &result) override
    {

    }
};

int test_data_processor(std::unique_ptr<DataProcessor>& test, const std::any& data)
{
    std::cout << test->process(data) << std::endl;
    std::cout << test->validate(data) << std::endl;
    std::cout << test->format_output("hello") << std::endl;
    return 0;
}

int main()
{
    std::unique_ptr<DataProcessor> test;
    std::vector<int> list_data = {1, 2, 3, 4, 5};
    std::string str_data = "Hello Nexus World";
    std::string data_log = "INFO: System ready, ERROR";

    std::cout << "=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n" << std::endl;
    std::cout << "Initializing Numeric Processor..." << std::endl;
    test = std::make_unique<NumericProcessor>();
    test_data_processor(test, list_data);

    std::cout << "Initializing Text Processor..." << std::endl;
    test = std::make_unique<TextProcessor>();
    test_data_processor(test, str_data);

    std::cout << "Initializing Log Processor..." << std::endl;
    test = std::make_unique<TextProcessor>();
    test_data_processor(test, data_log);
    std::cout << std::endl;

    std::cout << "=== Polymorphic Processing Demo ===\n" << std::endl;
    std::cout << "Processing multiple data types through same interface..." << std::endl;

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
*/
