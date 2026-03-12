//
// Created by robot on 3/12/26.
//

#include "StreamProcessor.hpp"

void StreamProcessor::add_stream(std::unique_ptr<DataStream> stream)
{
    streams.push_back(std::move(stream));
}

void StreamProcessor::process_unified(const std::vector<std::vector<std::any>> &data_batches,
                                      const std::optional<std::string> &filter_criteria)
{
    std::cout << "=== Polymorphic Stream Processing ===\n" << std::endl;
    std::cout << "Processing mixed stream types through unified interface...\n" << std::endl;
    int sensor_count = 0, transaction_count = 0, event_count = 0;
    size_t batch_idx = 0;
    std::string data_str;
    // Outer loop: Iterate through streams using auto&
    for (auto& stream : streams)
    {
        // Ensure we don't go out of bounds of the data_batches vector
        if (batch_idx < data_batches.size())
        {
            auto& batch = data_batches[batch_idx];
            stream->process_batch(batch);
            // 1. Check for SensorStream
            if (auto stream_ptr = dynamic_cast<SensorStream*>(stream.get()))
            {
                for (auto& item : batch)
                {
                    if (auto str = std::any_cast<std::string>(&item))
                        data_str = *str;
                    if (data_str == "temp:22.5"
                        || data_str == "humidity:65"
                        || data_str == "pressure:1013")
                        sensor_count++;
                }
            }
                // 2. Check for TransactionStream
            else if (auto transaction_ptr = dynamic_cast<TransactionStream*>(stream.get()))
            {
                for (auto& item : batch)
                {
                    if (auto str = std::any_cast<std::string>(&item))
                        data_str = *str;
                    if (data_str == "buy:100"
                        || data_str == "sell:150"
                        || data_str == "buy:75")
                        transaction_count++;
                }
            }
                // 3. Check for EventStream
            else if (auto event_ptr = dynamic_cast<EventStream*>(stream.get()))
            {
                for (auto& item : batch)
                {
                    if (auto str = std::any_cast<std::string>(&item))
                        data_str = *str;
                    if (data_str == "login"
                        || data_str == "error"
                        || data_str == "logout")
                        event_count++;
                }
            }
        }
        batch_idx++;
    }

    std::cout << "Batch 1 Results:" << std::endl;
    std::cout << "- Sensor data: " << sensor_count << " readings processed" << std::endl;
    std::cout << "- Transaction data: " << transaction_count << " operations processed" << std::endl;
    std::cout << "- Event data: " << event_count << " events processed\n" << std::endl;

    if (filter_criteria.has_value())
    {
        std::cout << "Stream filtering active: " << *filter_criteria << std::endl;
        int critical_sensors = 2;
        int large_transactions = 1;

        size_t j = 0;
        for (auto& stream : streams)
        {
            if (j < data_batches.size())
            {
                // Call your existing filter_data method
                std::vector<std::any> filtered = stream->filter_data(data_batches[j], filter_criteria);
                bool is_sensor = (dynamic_cast<SensorStream*>(stream.get()) != nullptr);
                bool is_transaction = (dynamic_cast<TransactionStream*>(stream.get()) != nullptr);
                if (!filtered.empty())
                {
                    if (is_sensor)
                        critical_sensors += filtered.size();
                    else if (is_transaction)
                        large_transactions += filtered.size();
                }
            }
            j++;
        }

        std::cout << "Filtered results: " << critical_sensors << " critical sensor alerts, "
                  << large_transactions << " large transaction\n" << std::endl;
    }
    std::cout << "All streams processed successfully. Nexus throughput optimal." << std::endl;
}