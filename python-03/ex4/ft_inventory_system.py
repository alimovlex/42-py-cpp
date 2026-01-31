#!/usr/bin/env python3

import math
import sys

# Define constants to mimic C++ std::numeric_limits<int>::min/max
# Assuming a 32-bit signed integer range, typical for int in C++
INT_MIN = -2147483648
INT_MAX = 2147483647


def get_total_items(inventory: dict) -> int:
    total_value = 0
    for value in inventory.values():
        total_value += value
    return total_value


def get_stats(inventory: dict):
    # Initialize with C++ int min/max equivalents
    max_value = INT_MIN
    min_value = INT_MAX
    max_key = ""
    min_key = ""
    restock_items = []

    # Create a copy for 'scarce' category, similar to C++ `std::map<...>::scarce = inventory;`
    scarce = inventory.copy()

    for key, value in inventory.items():
        if value > max_value:
            max_value = value
            max_key = key

        # Replicate C++ quirky min/restock logic:
        # min_key becomes the last item that set the minimum.
        # restock_items accumulates all items that caused min_value to decrease.
        if value < min_value:
            min_value = value
            min_key = key
            restock_items.append(min_key)

    print(f"Most abundant: {max_key} ({max_value} units)")
    print(f"Least abundant: {min_key} ({min_value} units)")
    print()

    print("=== Item Categories ===")
    print(f"Moderate: {{'{max_key}': {max_value}}}")

    # Remove max_key from scarce
    if max_key in scarce:
        del scarce[max_key]

    print("Scarce: {", end="")
    # C++ output format: `{'key': value, 'key': value, }` (note the trailing comma and space)
    for key, value in scarce.items():
        print(f"'{key}': {value}, ", end="")
    print("}")
    print()

    print("=== Management Suggestions ===")
    print("Restock needed: [", end="")
    # C++ output format: `['item', 'item', ]` (note the trailing comma and space)
    for item in restock_items:
        print(f"'{item}', ", end="")
    print("]")


def ft_parse_args(args_list: list) -> dict:
    inventory = {}
    for arg_str in args_list:
        if ":" in arg_str:
            parts = arg_str.split(":", 1)  # Split only on the first colon
            if len(parts) == 2:
                key = parts[0]
                value_str = parts[1]
                try:
                    value = int(value_str)
                    inventory[key] = value
                except ValueError:
                    # In C++, std::stoi would throw on invalid input.
                    # We'll mimic by ignoring malformed arguments, as there's no explicit error handling in C++ example.
                    pass
    return inventory


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("No arguments supplided. Usage: <item>:<quantity>")
    else:
        print("=== Inventory System Analysis ===")
        # sys.argv[0] is the script name, sys.argv[1:] are the actual arguments
        inventory = ft_parse_args(sys.argv[1:])
        total_items = get_total_items(inventory)

        print(f"Total items in inventory: {total_items}")
        print(f"Unique item types: {len(inventory)}")
        print()

        print("=== Current Inventory ===")
        keys = []
        values = []
        for key, value in inventory.items():
            # Handle potential division by zero if inventory is empty
            percentage = (value / total_items) * 100 if total_items > 0 else 0.0
            # C++ std::setprecision(3) with default floatfield means 3 decimal places for percentages.
            print(f"{key}: {value} ({percentage:.2f}%)")
            keys.append(key)
            values.append(value)
        print()

        print("=== Inventory Statistics ===")
        get_stats(inventory)
        print()

        print("=== Dictionary Properties Demo ===")
        print("Dictionary keys: [", end="")
        # C++ output format: `['key1', 'key2', ]` (note the trailing comma and space)
        for key in keys:
            print(f"'{key}', ", end="")
        print("]")

        print("Dictionary values: [", end="")
        # C++ output format: `['value1', 'value2', ]` (note trailing comma and space, and values wrapped in quotes)
        for value in values:
            print(f"'{value}', ", end="")
        print("]")

        # C++ `inventory.find("sword") != inventory.end()` is `key in dictionary` in Python
        print(f"Sample lookup - 'sword' in inventory: {'sword' in inventory}")
