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
        print("No arguments supplied. Usage: python your_script_name.py <x> <y> <z>")
    else:
        x_spawn, y_spawn, z_spawn = 0.0, 0.0, 0.0
        x1, y1, z1 = 10.0, 20.0, 5.0

        spawn_point = (x_spawn, y_spawn, z_spawn)
        p1 = (x1, y1, z1)
        parsed_tuple = (0.0, 0.0, 0.0)
        parsed_list = []

        print(f"Position created: ({x_spawn}, {y_spawn}, {z_spawn})")
        distance = distance3D(spawn_point, p1)

        print(
            f"Distance between ({x_spawn}, {y_spawn}, {z_spawn}) and ({x1}, {y1}, {z1}): {distance}"
        )
        print("Parsing coordinates:", end="")

        for arg in sys.argv[1:]:
            print(f" {arg}", end="")
            parsed_list.append(arg)
        print()

        try:
            for s in parsed_list:
                float(s)
        except ValueError as e:
            print(
                f"Error parsing coordinates: invalid literal for int() with base 10: {e}"
            )
            print()

        if len(parsed_list) >= 3:
            parsed_tuple = (
                float(parsed_list[0]),
                float(parsed_list[1]),
                float(parsed_list[2]),
            )
        else:
            pass

        x_parsed, y_parsed, z_parsed = parsed_tuple[0], parsed_tuple[1], parsed_tuple[2]

        print(f"Parsed position: ({x_parsed}, {y_parsed}, {z_parsed})")
        distance = distance3D(spawn_point, parsed_tuple)

        print(
            f"Distance between ({x_spawn}, {y_spawn}, {z_spawn}) and ({x_parsed}, {y_parsed}, {z_parsed}) {distance}"
        )

        arr = ["asd, def, ghi"]

        print("Parsing invalid coordinates: ", end="")
        for s in arr:
            print(f"{s} ", end="")
        print()

        try:
            for s in arr:
                float(s)
        except ValueError as e:
            print(
                f"Error parsing coordinates: invalid literal for int() with base 10: {e}"
            )

        print("Unpacking demonstration: ")
        print(f"Player at x={x_parsed} y={y_parsed} z={z_parsed}")
        print(f"Coordinates: X={x_parsed} Y={y_parsed} Z={z_parsed}")
