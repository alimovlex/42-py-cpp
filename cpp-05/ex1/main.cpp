//
// Created by robot on 3/12/26.
//
#include "DataStream.hpp"
#include "test_data_stream.hpp"
#include "SensorStream.hpp"
#include "TransactionStream.hpp"
#include "EventStream.hpp"
#include "StreamProcessor.hpp"

int main(int argc, char** argv)
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
            std::string{"logout"}
    };
    test = std::make_unique<EventStream>("EVENT_001");
    //EventStream event("EVENT_001");
    test_data_stream(test, "Event", lst_event, "nbr_event", "nbr_error");

    StreamProcessor processor;
    processor.add_stream(std::make_unique<SensorStream>("SENSOR_001"));
    processor.add_stream(std::make_unique<TransactionStream>("TRANS_001"));
    processor.add_stream(std::make_unique<EventStream>("EVENT_001"));

    std::vector<std::vector<std::any>> data_batches = {lst_data, lst_transac, lst_event};

    processor.process_unified(data_batches, "High-priorty data only");

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
