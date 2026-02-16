#include <exception>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <variant>
#include <any>
#include <vector>
#include <memory>

void print_any_vector(const std::vector<std::any>& databatch)
{
    for (const auto& element : databatch)
    {
        // adjust type as needed
        const auto& str = std::any_cast<const std::string&>(element);
        std::cout << str << std::endl;
    }
}

class DataStream
{
    public:
    std::vector<std::any> databatch;
    std::optional<std::string> criteria;
    std::string stream_id;

    virtual std::string process_batch(const std::vector<std::any>& databatch) = 0;
    virtual std::vector<std::any> filter_data(const std::vector<std::any>& databatch,
                                  const std::optional<std::string>& criteria)
    {
        this->databatch = databatch;
        this->criteria = criteria;
        return databatch;
    }
    virtual std::map<std::string, std::variant<std::string, int, double>> get_stats() = 0;

    virtual ~DataStream() = default;
};

class SensorStream : public DataStream
{
    public:
    SensorStream(std::string stream_id) { this->stream_id = stream_id; }

    std::string process_batch(const std::vector<std::any> &databatch) override
    {
        //if (str.find("ERROR") != std::string::npos)
        this->databatch = databatch;
        std::string text = "Stream ID: ", str_err = "ERROR: unknown data", data_str;
        text.insert(0, this->stream_id);
        text.insert(0, ", Type: Environmental Data");
        try
        {
            for (const auto& data : databatch)
            {
                if (auto str = std::any_cast<std::string>(&data))
                {
                    data_str = *str;
                    if (data_str == "temp:22.5"||data_str == "humidity:65"
                        ||data_str == "pressure:1013")
                        return text;
                }
                else if (!str)
                        continue;

            }
            return str_err;
        }
        catch (const std::bad_any_cast&)
        {
            return str_err;
        }
    }

    std::vector<std::any> filter_data(const std::vector<std::any> &databatch,
    const std::optional<std::string> &criteria) override
    {
        std::vector<std::any> filtered_results;
        bool has_special_marker = false;
        std::string data_str;
        this->databatch = databatch;
        this->criteria = criteria;
        // Extract the search string once outside the loop to avoid repeated .value() calls
        const std::string* search_crit = nullptr;
        if (criteria.has_value())
            search_crit = &criteria.value();

        for (const auto &item : databatch)
        {
            if (auto str = std::any_cast<std::string>(&item))
                data_str = *str;
            else if (!str)
                continue;

            // 1. Marker Detection (The Gatekeeper)
            // We only need to find it once per batch
            if (has_special_marker == false)
                if (data_str == "temp:22.5"
                    || data_str == "humidity:65"
                    || data_str == "pressure:1013")
                        has_special_marker = true;

            bool matches = true;
            if (search_crit != nullptr)
                if (data_str.find(*search_crit) == std::string::npos)
                    matches = false;
            if (matches)
                filtered_results.push_back(item);
        }

            // If the entire batch finished and we never saw a special marker,
            // the results are invalid per your original logic.
            if (has_special_marker == false)
                return {};

            return filtered_results;
    }

    std::map<std::string, std::variant<std::string, int, double>> get_stats() override
    {
        std::map<std::string, std::variant<std::string, int, double>> dict;
        return dict;
    }

};

class TransactionStream : public DataStream
{
    public:
    TransactionStream(std::string stream_id) { this->stream_id = stream_id; }

    std::string process_batch(const std::vector<std::any> &databatch) override
    {
        return "";
    }

    std::vector<std::any> filter_data(const std::vector<std::any> &databatch,
    const std::optional<std::string> &criteria) override
    {
        return databatch;
    }

    std::map<std::string, std::variant<std::string, int, double>> get_stats() override
    {
        std::map<std::string, std::variant<std::string, int, double>> dict;
        return dict;
    }
};

class EventStream : public DataStream
{
    public:
    EventStream(std::string stream_id) { this->stream_id = stream_id; }

    std::string process_batch(const std::vector<std::any> &databatch) override
    {
        return "";
    }

    std::vector<std::any> filter_data(const std::vector<std::any> &databatch,
    const std::optional<std::string> &criteria) override
    {
        return databatch;
    }

    std::map<std::string, std::variant<std::string, int, double>> get_stats() override
    {
        std::map<std::string, std::variant<std::string, int, double>> dict;
        return dict;
    }
};

class StreamProcessor
{
    public:
    std::vector<std::unique_ptr<DataStream>> streams;
    std::vector<std::string> results;
};

int test_data_stream(std::unique_ptr<DataStream>& test, const std::string& stream_name,
    const std::vector<std::any>& data, const std::string& key_one, const std::string& key_two)
{
    std::cout << test->process_batch(data) << std::endl;
    test->filter_data(data, std::nullopt);
    print_any_vector(data);
    std::map<std::string, std::variant<std::string, int, double>> dict = test->get_stats();
    std::cout << stream_name << " analysis: " << std::endl;
    std::visit([](auto&& x){ std::cout << x; }, dict[key_one]);
    std::cout << key_one << ", " << key_two << ": ";
    std::visit([](auto&& x){ std::cout << x; }, dict[key_two]);
    std::cout << std::endl;
    return 0;
}

int main()
{
    std::cout << "=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n" << std::endl;
    std::cout << "Initializing Sensor Stream..." << std::endl;
    std::unique_ptr<DataStream> test;
    std::map<std::string, std::variant<std::string, int, double>> dict;
    std::vector<std::any> lst_data = {
        std::string{"temp:22.5"},
        std::string{"humidity:65"},
        std::string{"pressure:1013"}
    };
    test = std::make_unique<SensorStream>("SENSOR_001");
    //SensorStream sensor("SENSOR_001");
    test_data_stream(test, "Sensor", lst_data, "operations", "avg_temp");

    std::cout << "Initializing Transaction Stream..." << std::endl;
    std::vector<std::any> lst_transac = {
        std::string{"buy:100"},
        std::string{"sell:150"},
        std::string{"buy:75"}
    };
    test = std::make_unique<TransactionStream>("TRANS_001");
    //TransactionStream transaction("TRANS_001");
    test_data_stream(test, "Transaction", lst_transac, "operations", "net_flow");

    std::cout << "Initializing Event Stream..." << std::endl;
    std::vector<std::any> lst_event = {
        std::string{"login"},
        std::string{"error"},
        std::string{"logout"},
        std::string{"error"}
    };
    test = std::make_unique<EventStream>("EVENT_001");
    //EventStream event("EVENT_001");
    test_data_stream(test, "Event", lst_event, "nbr_event", "nbr_error");

    StreamProcessor processor;

    return 0;
}

/*
 * std::cout << sensor.process_batch(lst_data) << std::endl;
 sensor.filter_data(lst_data, std::nullopt);
 print_any_vector(lst_data);
 std::map<std::string, std::variant<std::string, int, double>> dict = sensor.get_stats();

 std::cout << "Sensor analysis: ";
 std::visit([](auto&& x){ std::cout << x; }, dict["operations"]);
 std::cout << " reading processed, avg temp: ";
 std::visit([](auto&& x){ std::cout << x; }, dict["avg_temp"]);
 std::cout << "°C\n" << std::endl;

 std::cout << transaction.process_batch(lst_transac);
 transaction.filter_data(lst_transac, std::nullopt);
 print_any_vector(lst_transac);
 dict = transaction.get_stats();

 std::cout << "Transaction analysis: ";
 std::visit([](auto&& x){ std::cout << x; }, dict["operations"]);
 std::cout << " operations, net flow: ";
 std::visit([](auto&& x){ std::cout << x; }, dict["net_flow"]);
 std::cout << " units\n" << std::endl;

 std::cout << event.process_batch(lst_event);
 event.filter_data(lst_event, std::nullopt);
 print_any_vector(lst_event);
 dict = event.get_stats();
 std::cout << "Event analysis: ";
 std::visit([](auto&& x){ std::cout << x; }, dict["nbr_event"]);
 std::cout << " events, error: ";
 std::visit([](auto&& x){ std::cout << x; }, dict["nbr_error"]);
 std::cout << " detected\n" << std::endl;
 */
