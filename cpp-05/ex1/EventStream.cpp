//
// Created by robot on 3/12/26.
//

#include "EventStream.hpp"

EventStream::EventStream(std::string stream_id)
{
    this->stream_id = stream_id;
}

std::string EventStream::process_batch(const std::vector<std::any> &databatch)
{
    this->databatch = databatch;
    std::string text = "Stream ID: ", str_err = "ERROR: unknown data", data_str;
    text.append(this->stream_id);
    text.insert(0, "Type: System Events\n");
    try
    {
        for (const auto& data : databatch)
        {
            if (auto str = std::any_cast<std::string>(&data))
            {
                data_str = *str;
                if (data_str == "login"
                    ||data_str == "error"
                    ||data_str == "logout")
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
EventStream::filter_data(const std::vector<std::any> &databatch, const std::optional<std::string> &criteria)
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
            if (data_str == "login"
                || data_str == "error"
                || data_str == "logout")
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

std::map<std::string, std::variant<std::string, int, double>> EventStream::get_stats()
{
    int count = 0, err = 0;
    std::string data_str;
    try
    {
        for (const auto &data : databatch)
        {
            // Get string pointer (Equivalent to Python's isinstance(data, str))
            if (auto str = std::any_cast<std::string>(&data))
                data_str = *str;
            else if (!str)
                continue;

            if (data_str == "login"
                || data_str == "error"
                || data_str == "logout")
                count++;
            if (data_str == "error")
                err++;
        }

        // Prepare the result dictionary
        std::map<std::string, std::variant<std::string, int, double>> results;
        results["nbr_event"] = count;
        results["nbr_error"] = err;

        return results;
    }
    catch (const std::exception& e)
    {
        std::cout << "Provide Events data only" << std::endl;

        std::map<std::string, std::variant<std::string, int, double>> error_stats;
        error_stats["nbr_event"] = 0;
        error_stats["nbr_error"] = 0;

        return error_stats;
    }
}