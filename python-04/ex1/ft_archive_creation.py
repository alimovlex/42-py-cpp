#!/usr/bin/env python3

if __name__ == "__main__":
    file_name = "new_discovery.txt"
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===\n")
    print(f"Initializing new storage unit: {file_name}")
    i = 1

    data = [
        "New quantum algorithm discovered",
        "Efficiency increased by 347%",
        "Archived by Data Archivist trainee",
    ]

    with open(file_name, "w") as file:
        print("RECOVERED DATA:")
        try:
            print("Storage unit created successfully...\n")
            print("Inscribing preservation data...")

            for s in data:
                file.write(f"[ENTRY {i}] {s}\n")
                print(f"[ENTRY {i}] {s}, ")
                i += 1
            print()
            print("Data inscription complete. Storage unit sealed.")
            print(f"Archive '{file_name}' ready for long preservation")
        except FileNotFoundError:
            print("Error: storage vault not found")
