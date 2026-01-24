#!/usr/bin/env python3


class Plant:
    instance_count = 0

    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age
        Plant.instance_count += 1
        print(f"Created: {self.name} ({self.height}cm, {self.age} days)")

    @classmethod
    def get_objects_count(cls):
        return cls.instance_count


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 25, 30)
    oak = Plant("Oak", 200, 365)
    cactus = Plant("Cactus", 5, 90)
    sunflower = Plant("Sunflower", 80, 45)
    fern = Plant("Fern", 15, 120)
    print()
    print(f"Total plants created: {Plant.get_objects_count()}")
