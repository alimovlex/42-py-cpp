def mage_counter() -> callable:
    """ • Return a function that counts how many times it’s been called
        • Each call should return the current count (starting from 1)
        • The counter should persist between calls
        • Use closure to maintain state without global variables
        """
    x = 0

    def inner():
        nonlocal x
        x += 1
        return x
    return inner


def spell_accumulator(initial_power: int) -> callable:
    """ • Return a function that accumulates power over time
        • Each call adds the given amount to the total power
        • Return the new total power after each addition
        • Start with initial_power as the base
        """
    def inner(amount):
        nonlocal initial_power
        initial_power += amount
        return initial_power
    return inner


def enchantment_factory(enchantment_type: str) -> callable:
    """ • Return a function that applies the specified enchantment
        • The returned function takes an item name and
        • returns enchanted description
        • Format: "enchantment_type item_name" (e.g., "Flaming Sword")
        • Each factory creates functions with different enchantment types
        """
    def inner(item_name: str):
        return f"{enchantment_type} {item_name}"
    return inner


def memory_vault() -> dict[str, callable]:
    """ • Return a dict with ’store’ and ’recall’ functions
        • ’store’ function: takes (key, value) and stores the memory
        • ’recall’ function: takes (key) and returns
        • stored value or"Memory not found"
        • Use closure to maintain private memory storage"""
    memory = {}

    def store(key, value):
        memory[key] = value

    def recall(key):
        return memory.get(key, "Memory not found")

    return {
        "store": store,
        "recall": recall
    }


if __name__ == "__main__":

    # print("Testing mage counter...")
    # count = mage_counter()
    # for i in range(1, 4):
    #     print(f"Call{i}: {count()}")
    # _____________________________________________
    # accumulator = spell_accumulator(4)
    # print(accumulator(5))
    # print(accumulator(6))
    # print(accumulator(7))
    # print(accumulator(8))
    # ______________________________________________
    # print("Testing enchantment factory...")
    # enchant = enchantment_factory("Flaming")
    # print(enchant("Sword"))
    # enchan2 = enchantment_factory("Frozen")
    # print(enchan2("Shield"))
    # ______________________________________________
    vault = memory_vault()
    vault["store"]("spell", "Fireball")
    vault["store"]("weapon", "Sword")

    print(vault["recall"]("spell"))
    print(vault["recall"]("weapon"))
    print(vault["recall"]("armor"))
