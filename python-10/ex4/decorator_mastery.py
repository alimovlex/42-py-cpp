from functools import wraps
import time


def spell_timer(func: callable) -> callable:
    """
        • Create a decorator that measures function execution time
        • Print "Casting function_name..." before execution
        • Print "Spell completed in time seconds" after execution
        • Use functools.wraps to preserve original function metadata
        • Return the original function’s result
        """
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        elapsed = end_time - start_time
        print(f"Spell completed in {elapsed:6f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> callable:
    """ • Create a decorator factory that validates power levels
        • Check if the first argument (power) is >= min_power
        • If valid, execute the function normally
        • If invalid, return "Insufficient power for this spell"
        • Use functools.wraps properly
        """
    def decorator(func: callable) -> callable:

        @wraps(func)
        def wrapper(*args, **kwargs):
            if not args:
                return "Insufficient power for this spell"
            power = args[-1]
            if power >= min_power:
                return func(*args, **kwargs)
            else:
                return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> callable:
    """ • Create a decorator that retries failed spells
        • If function raises an exception, retry up to max_attempts times
        • Print "Spell failed, retrying... (attempt n/max_attempts)"
        • If all attempts fail, return
            "Spell casting failed after max_attempts attempts"
        • If successful, return the result normally"""
    def decorator(func: callable) -> callable:

        @wraps(func)
        def wrapper(*args, **kwargs):
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(f"Spell failed, retrying..."
                              f"({attempt}/{max_attempts})")
                    else:
                        return (f"Spell casting failed after"
                                f"{max_attempts} attempts")
        return wrapper
    return decorator


class MageGuild:
    """ • validate_mage_name(name) - Static method that checks if name is valid
        • Name is valid if it’s at least 3 characters and contains
            only letters/spaces
        • cast_spell(self, spell_name, power) - Instance method
        • Should use the power_validator decorator with min_power=10
        • Return "Successfully cast spell_name with power powe"""
    def __init__(self, name: str):
        if not MageGuild.validate_mage_name(name):
            raise ValueError("Invalid mage name")
        self.name = name

    @staticmethod
    def validate_mage_name(name: str) -> bool:
        """
        Name is valid if:
        • At least 3 characters
        • Contains only letters and spaces
        """
        return (
            isinstance(name, str)
            and len(name) >= 3
            and all(char.isalpha() or char.isspace() for char in name)
        )

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


if __name__ == "__main__":

    # print("Testing spell timer...")

    # @spell_timer
    # def fireball():
    #     time.sleep(1)
    #     return "🔥 Boom!"
    # fireball()
    # print(f"Result: {fireball.__name__} cast!")
    # __________________________________________________
    # @power_validator(50)
    # def lightning(power):
    #     return f"⚡ Lightning cast with power {power}!"
    # print(lightning(80))
    # print(lightning(30))
    # __________________________________________________
    # @retry_spell(3)
    # def risky_spell():
    #     import random
    #     if random.random() < 0.7:
    #         raise ValueError("Spell fizzled!")
    #     return "✨ Spell succeeded!"
    # print(risky_spell())
    # __________________________________________________
    print("Testing MageGuild...")
    mage1 = MageGuild("Louis")
    mage2 = MageGuild("Louis")
    mage3 = MageGuild("Louis")
    print(mage1.validate_mage_name("Louis"))
    print(mage2.validate_mage_name("Louis545"))
    print(mage3.cast_spell("Fireball", 15))
    print(mage3.cast_spell("Ice Bolt", 5))
