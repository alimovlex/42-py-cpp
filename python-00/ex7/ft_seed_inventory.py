#!/usr/bin/env python3


def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed_type = seed_type[0].upper() + seed_type[1:]

    if unit == "packets":
        print(f"{seed_type} seeds: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{seed_type} seeds: {quantity} {unit} total")
    elif unit == "area":
        unit = "square meters"
        print(f"{seed_type} seeds: covers {quantity} {unit}")
    else:
        print("Unknown unit type")


ft_seed_inventory("tomato", 15, "packets")
ft_seed_inventory("carrot", 8, "grams")
ft_seed_inventory("lettuce", 12, "area")
