def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    """ • Use sorted() with a lambda to sort by ’power’ level (descending)
        • Each artifact is a dict: {’name’: str, ’power’: int, ’type’: str}
        • Return the sorted list
        """
    sort_artifact = sorted(artifacts, key=lambda x: x["power"], reverse=True)
    return (sort_artifact)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    """ • Use filter() with a lambda to find mages with power >= min_power
        • Each mage is a dict: {’name’: str, ’power’: int, ’element’: str}
        • Return a list of filtered mages
        """
    filt_list = filter(lambda powerr: powerr["power"] >= min_power, mages)
    return (filt_list)


def spell_transformer(spells: list[str]) -> list[str]:
    """ • Use map() with a lambda to add "* " prefix and " *" suffix
        • Input: list of spell names (strings)
        • Return a list of transformed spell names
        """
    add_start_end = map(lambda add: f"* {add} *", spells)
    return (add_start_end)


def mage_stats(mages: list[dict]) -> dict:
    """ • Use lambdas with max(), min(), and sum() to find:
        • Most powerful mage’s power level
        • Least powerful mage’s power level
        • Average power level (rounded to 2 decimals)
        • Return dict: {’max_power’: int, ’min_power’: int, ’avg_power’: float}
        """
    powers = list(map(lambda m: m['power'], mages))

    max_power = (lambda x: max(x))(powers)
    min_power = (lambda x: min(x))(powers)
    avg_power = (lambda x: round(sum(x) / len(x), 2))(powers)

    return {
        "max_power": max_power,
        "min_power": min_power,
        "avg_power": avg_power
    }


if __name__ == "__main__":

    SPELL_NAMES = [
        "fireball", "heal", "shield"
    ]

    list_artifact = [
                    {"name": "Crystal Orb", "power": 85, "type": "artifact"},
                    {"name": "Fire Staff", "power": 92, "type": "artifact"},
                    # {"name": "Ice Wand", "power": 3, "type": "artifact"},
                    # {"name": "Lightning Rod", "power": 4, "type": "artfact"},
                    # {"name": "Earth Shield", "power": 5, "type": "artifact"},
                    # {"name": "Wind Cloak", "power": 6, "type": "artifact"},
                    # {"name": "Water Chalice", "power": 7, "type": "artfact"},
                    # {"name": "Shadow Blade", "power": 8, "type": "artifact"},
                    # {"name": "Light Prism", "power": 8, "type": "artifact"},
                    # {"name": "Storm Crown", "power": 8, "type": "artifact"}
                ]

    art_sorted = artifact_sorter(list_artifact)
    mage_sta = mage_stats(list_artifact)
    transform = spell_transformer(SPELL_NAMES)

    print("Testing artifact sorter...")
    print(f"{art_sorted[0]["name"]} ({mage_sta["max_power"]}) "
          f"comes before {art_sorted[1]["name"]} ({mage_sta["min_power"]})")
    print()
    print("Testing spell transformer...")
    print(" ".join(transform))
