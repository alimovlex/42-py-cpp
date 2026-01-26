#!/usr/bin/env python3

import sys

print("=== Command Quest ===")

argc = len(sys.argv)

if argc < 2:
    print("No arguments provided!")
    print(f"Program name: {sys.argv[0]}")
else:
    print(f"Program name: {sys.argv[0]}")
    print(f"Arguments received: {argc - 1}")

    arg_counter = 1
    for arg_value in sys.argv[1:]:
        print(f"Argument {arg_counter}: {arg_value}")
        arg_counter += 1

print(f"Total arguments: {argc}")
