#!/usr/bin/env python3


class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height
        self.growth = 0

    def grow(self):
        self.growth += 1
        print(self.name, "grew 1cm")

    def get_height(self) -> int:
        return self.height + self.growth

    def get_growth(self) -> int:
        return self.growth

    def get_points(self) -> int:
        return self.height + self.growth

    def info(self):
        print(f"- {self.name}: {self.height + self.growth}cm", end="")


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, color: str):
        super().__init__(name, height)
        self.color = color

    def get_points(self):
        return self.get_height() * 2

    def info(self):
        super().info()
        print(f", {self.color} flowers (blooming)", end="")


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, color: str, points: int):
        super().__init__(name, height, color)
        self.points = points

    def get_points(self):
        return (self.get_height() + self.points) * 3

    def info(self):
        super().info()
        print(f", prize points: {self.points}", end="")


class Garden:
    def __init__(self, owner: str):
        self.owner = owner
        self.plants: list[Plant] = []

    def get_owner(self):
        return self.owner

    def add_plant(self, plant: Plant):
        print(f"Added {plant.name} to {self.owner}'s garden")
        self.plants.append(plant)

    def grow_plants(self):
        print()
        print(self.owner, "is helping all plants grow...")
        for plant in self.plants:
            plant.grow()
        print()


class GardenManager:
    def __init__(self):
        self.gardens: list[Garden] = []

    @classmethod
    def create_garden_network(cls, gardeners: list[str]):
        gardenmanager = cls()
        for gardener in gardeners:
            gardenmanager.add_garden(gardener)
        return gardenmanager

    def add_garden(self, name: str):
        self.gardens.append(Garden(name))

    def find_garden(self, name: str) -> Garden:
        for garden in self.gardens:
            if garden.get_owner() == name:
                return garden

    def add_plant(self, name: str, plant: Plant):
        self.find_garden(name).add_plant(plant)

    def grow_plants(self, name: str):
        self.find_garden(name).grow_plants()

    def get_scores(self):
        print("Garden scores - ", end="")
        for garden in self.gardens:
            score = 0
            for plant in garden.plants:
                score += plant.get_points()
            print(f"{garden.get_owner()}: {score}, ", end="")
        print()

    def get_gardencount(self):
        print("Total gardens managed:", len(self.gardens))

    class GardenStats:
        @staticmethod
        def report(garden: Garden):
            print(f"=== {garden.get_owner()}'s Garden Report ===")
            GardenManager.GardenStats.get_plants(garden)
            GardenManager.GardenStats.get_plant_stats(garden)
            GardenManager.GardenStats.get_plant_types(garden)
            GardenManager.GardenStats.validate_heights(garden)
            print()

        @staticmethod
        def get_plants(garden: Garden):
            print("Plants in garden:")
            for plant in garden.plants:
                plant.info()
                print()
            print()

        @staticmethod
        def get_plant_stats(garden: Garden):
            total_growth = 0
            for plant in garden.plants:
                total_growth += plant.get_growth()
            print(f"Plants added: {len(garden.plants)}", end="")
            print(f", total growth: {total_growth}cm")

        @staticmethod
        def get_plant_types(garden: Garden):
            regular = 0
            flowering = 0
            prize = 0
            for plant in garden.plants:
                if type(plant) is Plant:
                    regular += 1
                if type(plant) is FloweringPlant:
                    flowering += 1
                if type(plant) is PrizeFlower:
                    prize += 1
            print(
                "Plant types:",
                f"{regular} regular,",
                f"{flowering} flowering,",
                f"{prize} prize flowers",
            )

        @staticmethod
        def validate_heights(garden: Garden):
            valid = True
            for plant in garden.plants:
                if plant.get_height() < 0:
                    valid = False
                    break
            print("Height validation test:", valid)


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
    manager = GardenManager.create_garden_network(["Alice", "Bob"])
    manager.add_plant("Alice", Plant("Oak Tree", 100))
    manager.add_plant("Alice", FloweringPlant("Rose", 25, "red"))
    manager.add_plant("Alice", PrizeFlower("Sunflower", 50, "yellow", 10))
    manager.grow_plants("Alice")
    manager.add_plant("Bob", FloweringPlant("Rose", 25, "red"))
    manager.GardenStats.report(manager.find_garden("Alice"))
    manager.get_scores()
    manager.get_gardencount()
