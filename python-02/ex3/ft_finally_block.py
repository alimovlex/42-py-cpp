#!/usr/bin/env python3


def water_plants(plant_list: list[str]):
    print("Opening watering system")
    try:
        for plant in plant_list:
            print(f"Watering {plant}")
    except TypeError:
        print(f"Error: can't water {plant} - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")
        print("Watering completed successfully!\n")


def test_watering_system():
    print("Testing normal watering...")
    plant_list = ["tomato", "lettuce", "carrots"]
    water_plants(plant_list)

    print("Testing with error...")
    plant_list[1] = None
    water_plants(plant_list)


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    test_watering_system()
    print("Cleanup always happens, even with errors!")
