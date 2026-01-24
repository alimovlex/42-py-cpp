#!/usr/bin/env python3


def ft_harvest_total():
    total = 0
    day = int(input("Day 1 harvest: "))
    total += day
    day = int(input("Day 2 harvest: "))
    total += day
    day = int(input("Day 3 harvest: "))
    total += day
    print(f"Total harvest: {total}")


ft_harvest_total()
