#!/usr/bin/env python3


class Plant:
    def __init__(self, name, height, days):
        self.name = name
        self.height = height
        self.days = days


class Flower(Plant):
    def __init__(self, name, height, days, color):
        super().__init__(name, height, days)
        self.color = color
        print(f"{name} (Flower): {height}cm, {days}days, {color} color")

    def bloom(self):
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name, height, days, trunk_diameter):
        super().__init__(name, height, days)
        self.trunk_diameter = trunk_diameter
        print(f"{name} (Tree): {height}cm, {days}days, {trunk_diameter}cm diameter")

    def produce_shade(self):
        pi = 3.14159
        shade_area = (self.trunk_diameter * self.trunk_diameter * pi) / 4
        print(f"{self.name} provides {shade_area} square meters of shade")


class Vegetable(Plant):
    def __init__(self, name, height, days, harvest_season, nutritional_value):
        super().__init__(name, height, days)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
        print(f"{name} (Vegetable): {height}cm, {days}days, {harvest_season}")
        print(f"{name} is rich in {nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    rose = Flower("Rose", 25, 30, "red")
    tulip = Flower("Tulip", 50, 90, "yellow")
    rose.bloom()
    tulip.bloom()
    print()

    oak = Tree("Oak", 500, 1825, 50)
    oak.produce_shade()
    birch = Tree("birch", 700, 1500, 90)
    birch.produce_shade()
    print()
    tomato = Vegetable("Tomato", 80, 90, "summer harvest", "vitamin C")
    cucumber = Vegetable("Cucumber", 50, 120, "fall harvest", "vitamin D")
