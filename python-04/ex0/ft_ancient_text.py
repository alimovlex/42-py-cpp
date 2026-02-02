#!/usr/bin/env python3
if __name__ == "__main__":
    filename = "ancient_fragment.txt"
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print(f"Accessing storage vault: {filename}")
    try:
        with open(filename, "r") as file:
            print("Connection established...")
            print("RECOVERED DATA:")
            print(file.read())
            print("Data recovery complete. Storage unit disconnected.")
            file.close()
    except FileNotFoundError:
        print("Error: storage vault not found")
