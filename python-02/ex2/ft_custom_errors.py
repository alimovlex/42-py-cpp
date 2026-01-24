#!/usr/bin/env python3


class GardenError(Exception):
    pass


class PlantError(GardenError):
    def __str__(self):
        return "The tomato plant is wilting!"


class WaterError(GardenError):
    def __str__(self):
        return "Not enough water in the tank!"


def test_moisture(moisture):
    if moisture < 1:
        raise PlantError("The tomato plant is wilting!")
    else:
        print("Plant OK!")


def test_water(water):
    if water < 1:
        raise WaterError("Not enough water in the tank!")
    else:
        print("Water OK!")


def test_errors():
    try:
        print("Testing PlantError...")
        test_moisture(0)
    except PlantError as e:
        print(f"Caught PlantError: ' {e}")

    try:
        print("Testing WaterError...")
        test_water(0)
    except WaterError as e:
        print(f"Caught WaterError: ' {e}")

    exceptions = []
    print("Testing all garden errors...")

    try:
        test_moisture(0)
    except PlantError as e:
        exceptions.append(e)

    try:
        test_water(0)
    except WaterError as e:
        exceptions.append(e)

    for i in exceptions:
        print(f"Caught a garden error: {i}")
    print("All custom error types work correctly!")


if __name__ == "__main__":
    test_errors()
