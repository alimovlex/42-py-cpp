#!/usr/bin/env python3
import sys

if __name__ == "__main__":
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===\n")
    id = input("Input Stream active. Enter archivist ID: ")
    status = input("Input Stream active. Enter status report: ")

    str1 = "[STANDARD] Archive status from " + f"{id}: {status}"
    str2 = "[ALERT] System diagnostic: Communication channels verified"
    str3 = "[STANDARD] Data transmission complete"

    sys.stdout.write(f"{str1}\n")
    sys.stderr.write(f"{str2}\n")
    sys.stdout.write(f"{str3}\n")

    print("Three-channel communication test successful.")
