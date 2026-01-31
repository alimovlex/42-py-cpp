#!/usr/bin/env python3

import math
import sys


def distance3D(p1: tuple, p2: tuple):
    x1, y1, z1 = p1[0], p1[1], p1[2]
    x2, y2, z2 = p2[0], p2[1], p2[2]
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2)


if __name__ == "__main__":
    print("=== Game Coordinate System ===")

    if len(sys.argv) < 2:
        print("No args supplied. Usage: python script.py <x> <y> <z>")
    else:
        x_sp, y_sp, z_sp = 0.0, 0.0, 0.0
        x1, y1, z1 = 10.0, 20.0, 5.0

        spawn_point = (x_sp, y_sp, z_sp)
        p1 = (x1, y1, z1)
        parsed_tuple = (0.0, 0.0, 0.0)
        parsed_list = []

        print(f"Position created: ({x_sp}, {y_sp}, {z_sp})")
        distance = distance3D(spawn_point, p1)

        print(f"Distance between ({x_sp}, {y_sp}, {z_sp}) ", end="")
        print(f"and ({x1}, {y1}, {z1}): {distance}")
        print("Parsing coordinates:", end="")

        for arg in sys.argv[1:]:
            print(f" {arg}", end="")
            parsed_list.append(arg)
        print()

        try:
            for s in parsed_list:
                float(s)
        except ValueError as e:
            print("Error parsing coordinates: ", end="")
            print(f"invalid literal for int() with base 10: {e}")
            print()

        if len(parsed_list) >= 3:
            parsed_tuple = (
                float(parsed_list[0]),
                float(parsed_list[1]),
                float(parsed_list[2]),
            )
        else:
            pass

        x_par, y_par, z_par = parsed_tuple[0], parsed_tuple[1], parsed_tuple[2]

        print(f"Parsed position: ({x_par}, {y_par}, {z_par})")
        distance = distance3D(spawn_point, parsed_tuple)

        print(f"Distance between ({x_sp}, {y_sp}, {z_sp}) ", end="")
        print(f"and ({x_par}, {y_par}, {z_par}) {distance}")

        arr = ["asd, def, ghi"]

        print("Parsing invalid coordinates: ", end="")
        for s in arr:
            print(f"{s} ", end="")
        print()

        try:
            for s in arr:
                float(s)
        except ValueError as e:
            print("Error parsing coordinates: ", end="")
            print(f"invalid literal for int() with base 10: {e}")

        print("Unpacking demonstration: ")
        print(f"Player at x={x_par} y={y_par} z={z_par}")
        print(f"Coordinates: X={x_par} Y={y_par} Z={z_par}")
