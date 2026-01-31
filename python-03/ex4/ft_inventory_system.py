#!/usr/bin/env python3

import sys


def build_inventory(arg_list):
    """Create a plain dict from ['name:qty', ...] strings."""
    inventory = dict()
    for token in arg_list:
        if ":" not in token:
            continue
        name, qty_str = token.split(":", 1)
        try:
            qty = int(qty_str)
        except ValueError:
            qty = 0
        inventory.update({name: qty})
    return inventory


def total_units(inv):
    """Sum of all quantities."""
    total = 0
    for _, qty in inv.items():
        total += qty
    return total


def most_and_least(inv):
    """Return (most_item, least_item) as (name, qty)."""
    most_name = None
    most_qty = -1
    least_name = None
    least_qty = None

    for name, qty in inv.items():
        if qty > most_qty:
            most_qty = qty
            most_name = name
        if least_qty is None or qty < least_qty:
            least_qty = qty
            least_name = name

    return (most_name, most_qty), (least_name, least_qty)


def categorize(inv):
    """Separate items into two groups."""
    moderate = dict()
    scarce = dict()
    for name, qty in inv.items():
        if qty >= 5:
            moderate.update({name: qty})
        else:
            scarce.update({name: qty})
    return {"Moderate": moderate, "Scarce": scarce}


def restock_needed(inv, threshold=2):
    """List of items whose quantity is <= threshold."""
    needed = []
    for name, qty in inv.items():
        if qty <= threshold:
            needed.append(name)
    return needed


def main():
    raw_items = sys.argv[1:]
    inventory = build_inventory(raw_items)

    total = total_units(inventory)
    unique = len(inventory)

    print("=== Inventory System Analysis ===")
    print(f"Total items in inventory: {total}")
    print(f"Unique item types: {unique}\n")
    print("=== Current Inventory ===")
    sorted_items = list(inventory.items())
    n = len(sorted_items)
    for i in range(n):
        for j in range(0, n - i - 1):
            if sorted_items[j][1] < sorted_items[j + 1][1]:
                sorted_items[j], sorted_items[j + 1] = (
                    sorted_items[j + 1],
                    sorted_items[j],
                )
    for name, qty in sorted_items:
        pct = round(100 * qty / total, 1) if total else 0
        unit_word = "unit" if qty == 1 else "units"
        print(f"{name}: {qty} {unit_word} ({pct}%)")
    print("")
    most, least = most_and_least(inventory)
    print("=== Inventory Statistics ===")
    print(f"Most abundant: {most[0]} ({most[1]} units)")
    print(f"Least abundant: {least[0]} ({least[1]} unit", end="")

    print(f"{'s' if least[1] != 1 else ''}", end="")

    print(")\n")

    categories = categorize(inventory)
    print("=== Item Categories ===")
    for cat_name, sub_dict in categories.items():
        print(f"{cat_name}: {sub_dict}")
    print("")
    needed = restock_needed(inventory)
    print("=== Management Suggestions ===")
    print(f"Restock needed: {needed}\n")

    print("=== Dictionary Properties Demo ===")
    print(f"Dictionary keys: {list(inventory.keys())}")
    print(f"Dictionary values: {list(inventory.values())}")
    sample = "sword"
    print(f"Sample lookup - '{sample}' in inventory: {sample in inventory}")


if __name__ == "__main__":
    main()
