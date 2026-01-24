#!/usr/bin/env python3


def check_temperature(temp_str) -> int:
    print(f"Testing temperature: {temp_str}")

    try:
        temp = int(temp_str)
        if temp > 40:
            print(f"Error: {temp}°C is too hot for plants (max 40°C)")
            return 0
        elif temp < 0:
            print(f"Error: {temp}°C is too cold for plants (min 0°C)")
            return 0
        print(f"Temperature {temp}°C is perfect for plants!")
        return temp
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")
        return 0


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    arr = ["25", "abc", "100", "-50"]
    for i in arr:
        check_temperature(i)
    print("All tests completed - program didn't crash!")
