#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <optional>

class finally
{
public:
    explicit finally(std::function<void()> f) : func_(std::move(f)) { }
    ~finally() { func_(); }
private:
    std::function<void()> func_;
};

void water_plants(std::vector<std::optional<std::string>>& plant_list)
{
    std::cout << "Opening watering system" << std::endl;
    try
    {
            for (auto& opt : plant_list)
            {
                if (!opt.has_value())
                    throw std::invalid_argument("null plant");
                else
                    std::cout << "Watering " << opt.value() << std::endl;
            }
    }
    catch (const std::invalid_argument&)
    {
        for (auto& plant : plant_list)
        {
            if (!plant.has_value())
            {
                std::cout << "Error: can't water <null> - invalid plant!" << std::endl;
                break;
            }
        }
    }
    finally cleanup([]{
        std::cout << "Closing watering system (cleanup)" << std::endl;
        std::cout << "Watering completed successfully!" << std::endl;
        std::cout << std::endl;
    });
}

void test_watering_system()
{
    std::cout << "Testing normal watering..." << std::endl;
        std::vector<std::optional<std::string>> plant_list =
        {
            std::make_optional<std::string>("tomato"),
            std::make_optional<std::string>("lettuce"),
            std::make_optional<std::string>("carrots")
        };
        water_plants(plant_list);
        std::cout << "Testing with error..." << std::endl;
        plant_list.at(1) = std::nullopt;
        water_plants(plant_list);
}

int main()
{
  std::cout << "=== Garden Watering System ===" << std::endl;
  test_watering_system();
  std::cout << "Cleanup always happens, even with errors!" << std::endl;
  return 0;
}
