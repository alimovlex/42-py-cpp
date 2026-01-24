#!/usr/bin/env python3


class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


class Plant:
    def __init__(self, name, water, sun):
        self.name = name
        self.water = water
        self.sun = sun

    def add_water(self, amount):
        self.water += amount

    def info(self):
        print(f"{self.name}: healthy (water: {self.water} {self.sun}")


class GardenManager:
    def __init__(self, tanksize):
        self.tanksize = tanksize
        self.plants: list[Plant] = []
        self.water = tanksize

    def add_plants(self, plants: list[Plant]):
        print("Adding plants to garden...")
        try:
            for plant in plants:
                if not plant.name:
                    raise ValueError("Plant name cannot be empty!")
                else:
                    print(f"Added {plant.name} successfully")
                self.plants.append(plant)
        except ValueError as e:
            print(f"Error: adding plant: {e}")

    def water_plants(self, amount):
        print("Watering plants...")
        print("Opening watering system")

        try:
            if not self.plants:
                raise GardenError("no plants to water")
            consumption = len(self.plants) * amount
            if consumption == 0:
                raise WaterError("0 water used")
            elif consumption > self.water:
                raise WaterError("not enough water in tank")
            else:
                self.water -= consumption

            for plant in self.plants:
                plant.add_water(amount)
                print(f"Watering {plant.name} - success")
        except GardenError as e:
            print(f"Error watering plants: {e}")
        finally:
            print("Closing watering system (cleanup)")

    @staticmethod
    def check_plant_health(plant):
        if plant.water > 10:
            raise PlantError("water level is too high (max 10")
        elif plant.water < 1:
            raise PlantError("water level is too low (min 1)")
        elif plant.sun > 12:
            raise PlantError("sunlight hours are too high (max 12)")
        elif plant.sun < 2:
            raise PlantError("sunlight hours are too low (min 2)")
        else:
            plant.info()

    def check_plants(self):
        print("Checking plant health...")
        for plant in self.plants:
            try:
                self.check_plant_health(plant)
            except PlantError as e:
                print(f"Error checking {plant.name}: {e}")

    def recover(self):
        print("Testing error recovery...")
        try:
            if self.water < self.tanksize:
                raise WaterError("not enough water in tank")
            else:
                print("Water tank OK!")
        except WaterError as e:
            print(f"Caught: {e}")
            self.water = self.tanksize
            print("System recovered and continuing")


if __name__ == "__main__":
    print("=== Garden Management System ===")
    manager = GardenManager(30)

    tomato = Plant("tomato", 2, 8)
    lettuce = Plant("lettuce", 12, 8)
    carrot = Plant("", 0, 8)

    plants_to_add = [tomato, lettuce, carrot]
    manager.add_plants(plants_to_add)
    manager.water_plants(0)
    manager.check_plants()
    manager.recover()

    print("Garden Management system test complete!")
