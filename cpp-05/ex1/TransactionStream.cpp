//
// Created by robot on 3/12/26.
//

#include "TransactionStream.hpp"

TransactionStream::TransactionStream(std::string stream_id)
{
    this->stream_id = stream_id;
}

std::string TransactionStream::process_batch(const std::vector<std::any> &databatch)
{
    this->databatch = databatch;
    std::string text = "Stream ID: ", str_err = "ERROR: unknown data", data_str;
    text.append(this->stream_id);
    text.insert(0, "Type: Financial Data\n");
    try
    {
        for (const auto& data : databatch)
        {
            if (auto str = std::any_cast<std::string>(&data))
            {
                data_str = *str;
                if (data_str == "buy:100"
                    ||data_str == "sell:150"
                    ||data_str == "buy:75")
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
TransactionStream::filter_data(const std::vector<std::any> &databatch, const std::optional<std::string> &criteria)
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
            if (data_str == "buy:100"
                || data_str == "sell:150"
                || data_str == "buy:75")
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

std::map<std::string, std::variant<std::string, int, double>> TransactionStream::get_stats()
{
    // 1. Initialize local accumulators (matching Python: stats = {"buy": 0, "sell": 0})
    std::map<std::string, int> totals = {{"buy", 0}, {"sell", 0}};
    int read_pairs = 0;
    std::string data_str;
    try
    {
        for (const auto &data : databatch)
        {
            if (auto str = std::any_cast<std::string>(&data))
                data_str = *str;
            else if (!str)
                continue;

            // Financial check
            if (data_str == "buy:100"
                || data_str == "sell:150"
                || data_str == "buy:75")
            {
                read_pairs++;
                size_t pos = data_str.find(':');
                if (pos != std::string::npos)
                {
                    std::string key = data_str.substr(0, pos);
                    int value = std::stoi(data_str.substr(pos + 1));
                    // Accumulate (stats[key] = stats[key] + value)
                    totals[key] += value;
                }
            }
        }
        // 2. Calculate net_flow after the loop
        int net_flow = totals["buy"] - totals["sell"];
        // 3. Prepare the final variant map
        std::map<std::string, std::variant<std::string, int, double>> results;
        results["operations"] = read_pairs;
        results["buy"]        = totals["buy"];
        results["sell"]       = totals["sell"];
        results["net_flow"]   = net_flow;
        return results;
    }
    catch (const std::exception& e)
    {
        std::cout << "Provide only financial data" << std::endl;
        // Match the Python fallback return: {"operations": 0, "net_flow": 0}
        std::map<std::string, std::variant<std::string, int, double>> error_stats;
        error_stats["operations"] = 0;
        error_stats["net_flow"]   = 0;
        return error_stats;
    }
}