from functools import reduce, partial, lru_cache, singledispatch
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    """ • Use functools.reduce to combine all spell powers
        • Support operations: "add", "multiply", "max", "min"
        • Use operator module functions (add, mul, etc.)
        • Return the final reduced value
        """
    if operation == "add":
        return reduce(operator.add, spells)
    elif operation == "multiply":
        return reduce(operator.mul, spells)
    elif operation == "max":
        return reduce(max, spells)
    elif operation == "min":
        return reduce(min, spells)


def partial_enchanter(base_enchantment: callable) -> dict[str, callable]:
    """ • Take a base enchantment function that needs (power, element, target)
        • Use functools.partial to create specialized versions
        • Return dict with keys: ’fire_enchant’, ’ice_enchant’,
            ’lightning_enchant’
        • Each should be a partial with power=50 and the respective element
        """
    return {
        "fire_enchant": partial(base_enchantment, 50, "fire"),
        "ice_enchant": partial(base_enchantment, 50, "ice"),
        "lightning_enchant": partial(base_enchantment, 50, "lightning")
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    """ • Use functools.lru_cache decorator for memoization
        • Implement fibonacci sequence calculation
        • The cache should improve performance for repeated calls
        • Return the nth fibonacci number
        """
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 1:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> callable:
    """ • Use functools.singledispatch to create a spell system
        • Handle different types: int (damage spell),
            str (enchantment), list (multi-cast)
        • Return the dispatcher function
        • Each type should have appropriate spell behavior
        """

    @singledispatch
    def cast(spell):
        return "Unknown spell type"

    @cast.register
    def _(spell: int):
        return f"Damage spell deals {spell} damage!"

    @cast.register
    def _(spell: str):
        return f"Enchantment spell casts '{spell}'!"

    @cast.register
    def _(spell: list):
        return f"Multi-cast spell with {len(spell)} spells!"

    return cast


if __name__ == "__main__":

    # print("Testing spell reducer...")
    # lst = [10, 20, 30, 40]
    # ope = spell_reducer(lst, "add")
    # print(f"sum: {ope}")
    # ope2 = spell_reducer(lst, "multiply")
    # print(f"Product: {ope2}")
    # ope3 = spell_reducer(lst, "max")
    # print(f"Max: {ope3}")
    # ________________________________________

    # def base_enchantment(power, element, target):
    #     return f"{power} {element} enchantment on {target}"
    # enchants = partial_enchanter(base_enchantment)
    # print(enchants["fire_enchant"]("sword"))
    # print(enchants["ice_enchant"]("shield"))
    # print(enchants["lightning_enchant"]("armor"))
    # _________________________________________

    # print("Testing memoized fibonacci...")
    # print(f"Fib(10) {memoized_fibonacci(10)}")
    # print(f"Fib(15) {memoized_fibonacci(15)}")
    # __________________________________________

    dispatcher = spell_dispatcher()
    print(dispatcher(50))
    print(dispatcher("Flaming Sword"))
    print(dispatcher([10, 20, 30]))
    print(dispatcher(3.14))
