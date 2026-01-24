#!/usr/bin/env python3


def ft_count_harvest_iterative():
    days = int(input("Days until harvest: "))
    i = 1
    while i <= days:
        print(f"Day {i}")
        i += 1
    print("Harvest time!")


ft_count_harvest_iterative()
