#!/usr/bin/env python3


class Plant:
    def __init__(self, name, height, days):
        self.name = name
        self.height = height
        self.days = days

    def grow(self, cm):
        self.height += cm

    def age(self, duration):
        self.days += duration

    def get_info(self):
        print(f"{self.name}: {self.height}cm, {self.days} days old")


if __name__ == "__main__":
    rose = Plant("Rose", 25, 30)
    print("=== Day 1 ===")
    rose.get_info()
    first_day_height = rose.height
    print("=== Day 7 ===")
    rose.grow(6)
    rose.age(6)
    rose.get_info()
    print(f"Growth this week: +{rose.height - first_day_height}cm")
