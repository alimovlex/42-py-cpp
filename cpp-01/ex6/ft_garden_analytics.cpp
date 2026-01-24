#include <iostream>
#include <vector>
#include <memory>
#include <string>

// -------------------------------------------------
// Plant hierarchy
// -------------------------------------------------
class Plant {
public:
    std::string name;
    int height;
    int growth{0};

    Plant(std::string n, int h) : name(std::move(n)), height(h) {}
    virtual ~Plant() = default;

    virtual void grow() {
        ++growth;
        std::cout << name << " grew 1cm\n";
    }

    int get_height() const { return height + growth; }
    int get_growth() const { return growth; }
    virtual int get_points() const { return height + growth; }

    virtual void info() const {
        std::cout << "- " << name << ": " << get_height() << "cm";
    }
};

class FloweringPlant : public Plant {
public:
    std::string color;

    FloweringPlant(std::string n, int h, std::string c)
        : Plant(std::move(n), h), color(std::move(c)) {}

    int get_points() const override { return get_height() * 2; }

    void info() const override {
        Plant::info();
        std::cout << ", " << color << " flowers (blooming)";
    }
};

class PrizeFlower : public FloweringPlant {
public:
    int points;

    PrizeFlower(std::string n, int h, std::string c, int p)
        : FloweringPlant(std::move(n), h, std::move(c)), points(p) {}

    int get_points() const override {
        return (get_height() + points) * 3;
    }

    void info() const override {
        FloweringPlant::info();
        std::cout << ", prize points: " << points;
    }
};

// -------------------------------------------------
// Garden
// -------------------------------------------------
class Garden {
    std::string owner;
    std::vector<std::unique_ptr<Plant>> plants;

public:
    explicit Garden(std::string o) : owner(std::move(o)) {}

    const std::string& get_owner() const { return owner; }

    void add_plant(std::unique_ptr<Plant> p) {
        std::cout << "Added " << p->name << " to " << owner << "'s garden\n";
        plants.emplace_back(std::move(p));
    }

    void grow_plants() {
        std::cout << "\n" << owner << " is helping all plants grow...\n";
        size_t i = 0;
        while (i < plants.size()) {
            plants[i]->grow();
            ++i;
        }
        std::cout << "\n";
    }

    const std::vector<std::unique_ptr<Plant>>& get_plants() const { return plants; }
};

// -------------------------------------------------
// GardenManager
// -------------------------------------------------
class GardenManager {
    std::vector<std::unique_ptr<Garden>> gardens;

public:
    // factory
    static GardenManager create_garden_network(const std::vector<std::string>& gardeners) {
        GardenManager mgr;
        for (const auto& name : gardeners) {
            mgr.add_garden(name);
        }
        return mgr;
    }

    void add_garden(const std::string& name) {
        gardens.emplace_back(std::make_unique<Garden>(name));
    }

    Garden* find_garden(const std::string& name) const {
        size_t i = 0;
        while (i < gardens.size()) {
            if (gardens[i]->get_owner() == name) return gardens[i].get();
            ++i;
        }
        return nullptr;
    }

    void add_plant(const std::string& garden_name, std::unique_ptr<Plant> p) {
        Garden* g = find_garden(garden_name);
        if (g) g->add_plant(std::move(p));
    }

    void grow_plants(const std::string& garden_name) {
        Garden* g = find_garden(garden_name);
        if (g) g->grow_plants();
    }

    void get_scores() const {
        std::cout << "Garden scores - ";
        size_t i = 0;
        while (i < gardens.size()) {
            const Garden* g = gardens[i].get();
            int score = 0;
            const auto& vec = g->get_plants();
            size_t j = 0;
            while (j < vec.size()) {
                score += vec[j]->get_points();
                ++j;
            }
            std::cout << g->get_owner() << ": " << score << ", ";
            ++i;
        }
        std::cout << "\n";
    }

    void get_gardencount() const {
        std::cout << "Total gardens managed: " << gardens.size() << "\n";
    }

    // -------------------------------------------------
    // Nested stats helper
    // -------------------------------------------------
    struct GardenStats {
        static void report(const Garden& garden) {
            std::cout << "=== " << garden.get_owner() << "'s Garden Report ===\n";
            get_plants(garden);
            get_plant_stats(garden);
            get_plant_types(garden);
            validate_heights(garden);
            std::cout << "\n";
        }

        static void get_plants(const Garden& garden) {
            std::cout << "Plants in garden:\n";
            const auto& vec = garden.get_plants();
            size_t i = 0;
            while (i < vec.size()) {
                vec[i]->info();
                std::cout << "\n";
                ++i;
            }
            std::cout << "\n";
        }

        static void get_plant_stats(const Garden& garden) {
            int total_growth = 0;
            const auto& vec = garden.get_plants();
            size_t i = 0;
            while (i < vec.size()) {
                total_growth += vec[i]->get_growth();
                ++i;
            }
            std::cout << "Plants added: " << vec.size()
                      << ", total growth: " << total_growth << "cm\n";
        }

        static void get_plant_types(const Garden& garden) {
            int regular = 0, flowering = 0, prize = 0;
            const auto& vec = garden.get_plants();
            size_t i = 0;
            while (i < vec.size()) {
                const Plant* p = vec[i].get();
                if (dynamic_cast<const Plant*>(p) && !dynamic_cast<const FloweringPlant*>(p))
                    ++regular;
                if (dynamic_cast<const FloweringPlant*>(p) && !dynamic_cast<const PrizeFlower*>(p))
                    ++flowering;
                if (dynamic_cast<const PrizeFlower*>(p))
                    ++prize;
                ++i;
            }
            std::cout << "Plant types: " << regular << " regular, "
                      << flowering << " flowering, " << prize << " prize flowers\n";
        }

        static void validate_heights(const Garden& garden) {
            bool ok = true;
            const auto& vec = garden.get_plants();
            size_t i = 0;
            while (i < vec.size()) {
                if (vec[i]->get_height() < 0) { ok = false; break; }
                ++i;
            }
            std::cout << "Height validation test: " << (ok ? "true" : "false") << "\n";
        }
    };
};

// -------------------------------------------------
// Demo (mirrors the original Python __main__ block)
// -------------------------------------------------
int main() {
    std::cout << "=== Garden Management System Demo ===\n";

    GardenManager manager = GardenManager::create_garden_network({"Alice", "Bob"});

    manager.add_plant("Alice", std::make_unique<Plant>("Oak Tree", 100));
    manager.add_plant("Alice", std::make_unique<FloweringPlant>("Rose", 25, "red"));
    manager.add_plant("Alice", std::make_unique<PrizeFlower>("Sunflower", 50, "yellow", 10));

    manager.grow_plants("Alice");

    manager.add_plant("Bob", std::make_unique<FloweringPlant>("Rose", 25, "red"));

    Garden* aliceGarden = manager.find_garden("Alice");
    if (aliceGarden) GardenManager::GardenStats::report(*aliceGarden);

    manager.get_scores();
    manager.get_gardencount();

    return 0;
}
