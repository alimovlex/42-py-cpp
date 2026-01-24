#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>

class finally
{
public:
    explicit finally(std::function<void()> f) : func_(std::move(f)) { }
    ~finally() { func_(); }
private:
    std::function<void()> func_;
};

class GardenError: public std::exception {
    private:
        std::string message;
    public:
        GardenError(const std::string& msg): message(msg) { }
        const char* what() const noexcept
        {
            return message.c_str();
        }
        //GardenError();
};

class PlantError: public GardenError
{
    private:
        std::string message;
    public:
        PlantError(const std::string& msg): GardenError(msg), message(msg) { }
        const char* what() const noexcept
        {
            return message.c_str();
        }
};

class WaterError: public GardenError
{
    private:
        std::string message;
    public:
    WaterError(const std::string& msg): GardenError(msg), message(msg) { }
    const char* what() const noexcept
    {
        return message.c_str();
    }
};

class Plant
{
    public:
    std::string name;
    int water;
    int sun;

    Plant(std::string name, int water, int sun):
    name(name), water(water), sun(sun) { }

    void add_water(int amount) { water += amount; }
    void info() { std::cout << name << ": healthy (water: " << water << " " << sun << std::endl; }
};

class GardenManager
{
    public:
    std::vector<Plant> plants;
    int tanksize;
    int water;
    GardenManager(int tanksize): tanksize(tanksize) { }

    void add_plants(std::vector<Plant>& plants)
    {
        std::cout << "Adding plants to garden..." << std::endl;
        try
        {
            for (auto& plant: plants)
            {
                if (plant.name.empty())
                    throw std::invalid_argument("Plant name cannot be empty!");
                else
                    std::cout << "Added " << plant.name << " successfully" << std::endl;
                this->plants.push_back(plant);
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: adding plant: " << e.what() << std::endl;
        }
    }

    void water_plants(int amount)
    {
        std::cout << "Watering plants..." << std::endl;
        std::cout << "Opening watering system" << std::endl;

        try
        {
            if (plants.empty())
                throw GardenError("no plants to water");
            int consumption = plants.size() * amount;

            if (consumption == 0)
                throw WaterError("0 water used");
            else if (consumption > water)
                throw WaterError("not enough water in tank");
            else
                water -= consumption;

            for (auto& plant: plants)
            {
                plant.add_water(amount);
                std::cout << "Watering " << plant.name << " - success" << std::endl;
            }
        }
        catch (const GardenError& e)
        {
            std::cout << "Error watering plants: " << e.what() << std::endl;
        }
        finally cleanup([]{
            std::cout << "Closing watering system (cleanup)" << std::endl;
            std::cout << std::endl;
        });
    }

    static void check_plant_health(Plant& plant)
    {
        if (plant.water > 10)
            throw PlantError("water level is too high (max 10");
        else if (plant.water < 1)
            throw PlantError("water level is too low (min 1)");
        else if (plant.sun > 12)
            throw PlantError("sunlight hours are too high (max 12)");
        else if (plant.sun < 2)
            throw PlantError("sunlight hours are too low (min 2)");
        else
            plant.info();
    }

    void check_plants()
    {
        std::cout << "Checking plant health..." << std::endl;
        for (auto& plant: plants)
        {
            try
            {
                this->check_plant_health(plant);
            }
            catch (const PlantError& e)
            {
                std::cout << "Error checking " << plant.name << ": " << e.what() << std::endl;
            }
        }
    }

    void recover()
    {
        std::cout << "Testing error recovery..." << std::endl;
        try
        {
            if (water < tanksize)
                throw WaterError("not enough water in tank");
            else
                std::cout << "Water tank OK!" << std::endl;
        }
        catch (const WaterError& e)
        {
            std::cout << "Caught: " << e.what() << std::endl;
            water = tanksize;
            std::cout << "System recovered and continuing" << std::endl;
        }
    }
};


int main()
{
    std::cout << "=== Garden Management System ===" << std::endl;
    GardenManager manager(30);
    Plant tomato("tomato", 2, 8);
    Plant lettuce("lettuce", 12, 8);
    Plant carrot("", 0, 8);

    std::vector<Plant> plants = {tomato, lettuce, carrot};
    manager.add_plants(plants);
    manager.water_plants(0);
    manager.check_plants();
    manager.recover();

    std::cout << "Garden Management system test complete!" << std::endl;

    return 0;
}
