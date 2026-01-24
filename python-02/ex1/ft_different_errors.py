#!/usr/bin/env python3


def garden_operations(exception):
    if exception is ValueError:
        num = int("abc")
        print(num)
    if exception is ZeroDivisionError:
        num = 0 / 0
        print(num)
    if exception is FileNotFoundError:
        file = open("")
        file.close()
    if exception is KeyError:
        dictionary = {"a": 5, "b": 10}
        num = dictionary["c"]
        print(num)


def test_error_types():
    print("=== Garden Error Types Demo ===\n")
    try:
        print("Testing ValueError...")
        garden_operations(ValueError)
    except ValueError as e:
        print(f"Caught exception ValueError: {str(e)}\n")
    try:
        print("Testing ZeroDivisionError...")
        garden_operations(ZeroDivisionError)
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {str(e)}\n")
    try:
        print("Testing FileNotFoundError...")
        garden_operations(FileNotFoundError)
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {str(e)}\n")
    try:
        print("Testing KeyError...")
        garden_operations(KeyError)
    except KeyError as e:
        print(f"Caught KeyError: {str(e)}\n")

    print("Testing multiple errors together...")
    try:
        n = 1 / 0
        print(n)
    except (ValueError, ZeroDivisionError):
        print("Caught an exception, but program continues!\n")

    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
