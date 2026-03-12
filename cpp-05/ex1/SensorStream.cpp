//
// Created by robot on 3/12/26.
//

#include "SensorStream.hpp"

SensorStream::SensorStream(std::string stream_id)
{
    this->stream_id = stream_id;
}

std::string SensorStream::process_batch(const std::vector<std::any> &databatch)
{
    //if (str.find("ERROR") != std::string::npos)
    this->databatch = databatch;
    std::string text = "Stream ID: ", str_err = "ERROR: unknown data", data_str;
    text.append(this->stream_id);
    text.insert(0, "Type: Environmental Data\n");
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

std::vector<std::any>
SensorStream::filter_data(const std::vector<std::any> &databatch, const std::optional<std::string> &criteria)
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

    for (const auto &data : databatch)
    {
        if (auto str = std::any_cast<std::string>(&data))
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
            filtered_results.push_back(data);
    }

    // If the entire batch finished and we never saw a special marker,
    // the results are invalid per your original logic.
    if (has_special_marker == false)
        return {};

    return filtered_results;
}

std::map<std::string, std::variant<std::string, int, double>> SensorStream::get_stats()
{
    std::map<std::string, std::variant<std::string, int, double>> stats;
    std::map<std::string, std::string> found_values;
    std::string data_str;
    int read_pairs = 0;

    try
    {
        for (const auto &data : databatch)
        {
            if (auto str = std::any_cast<std::string>(&data))
                data_str = *str;
            else if (!str)
                continue;

            // Environmental check (The markers)
            if (data_str == "temp:22.5"
                || data_str == "humidity:65"
                || data_str == "pressure:1013")
            {
                read_pairs++;
                // Manual split of "key:value"
                size_t pos = data_str.find(':');
                if (pos != std::string::npos)
                {
                    std::string key = data_str.substr(0, pos);
                    std::string value = data_str.substr(pos + 1);
                    found_values[key] = value;
                }
            }
        }

        // We use .at() because it throws if the key is missing.
        // This triggers the catch block if the markers weren't found,
        // matching your Python logic perfectly.
        stats["operations"] = read_pairs;
        stats["temp"]       = found_values.at("temp");
        stats["humidity"]   = found_values.at("humidity");
        stats["pressure"]   = found_values.at("pressure");

        // Using stod to utilize the 'double' in your variant for the average
        stats["avg_temp"]   = std::stod(found_values.at("temp"));

        return stats;
    }
    catch (const std::exception& e)
    {
        std::cout << "Provide only environmental data: " << e.what() << std::endl;
        std::map<std::string, std::variant<std::string, int, double>> error_stats;
        error_stats["operations"] = 0;
        error_stats["avg_temp"]   = 0.0;
        return error_stats;
    }
}