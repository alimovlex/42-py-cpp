#!/usr/bin/env python3


def check_plant_health(plant_name, water_level, sunlight_hours):
    if not plant_name:
        raise ValueError("Error: plant name can't be empty!")
    elif water_level > 10:
        raise ValueError("Error: water level is too high (max 10)")
    elif water_level < 1:
        raise ValueError("Error: water level is too low (min 10)")
    elif sunlight_hours > 12:
        raise ValueError("Error: sunlight hours is too high (max 12)")
    elif sunlight_hours < 2:
        raise ValueError("Error: sunlight hours is too low (min 2)")
    else:
        print(f"Plant {plant_name} is healthy!")


def test_plant_checks():
    try:
        print("Testing good values...")
        check_plant_health("tomato", 5, 6)
    except ValueError as e:
        print(e)

    try:
        print("Testing empty plant name...")
        check_plant_health("", 5, 6)
    except ValueError as e:
        print(e)

    try:
        print("Testing bad water level...")
        check_plant_health("tomato", 15, 6)
    except ValueError as e:
        print(e)

    try:
        print("Testing bad sunlight hours...")
        check_plant_health("tomato", 5, 0)
    except ValueError as e:
        print(e)


if __name__ == "__main__":
    print("=== Garden Plant Health Checker ===")
    test_plant_checks()
    print("All error raising tests completed!")
