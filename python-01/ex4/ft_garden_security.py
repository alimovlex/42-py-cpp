#!/usr/bin/env python3


class SafePlant:
    def __init__(self, name, height, age):
        self.__name = name
        self.__height = height
        self.__age = age
        print(f"Plant Created: {self.__name}")

    def set_height(self, new_height):
        if new_height < 0:
            print(f"Invalid operation attempted: {new_height}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self.__height = new_height
            print(f"Height updated: {self.__height}cm [OK]")

    def set_age(self, new_age):
        if new_age < 0:
            print(f"Invalid operation attempted: {new_age}days [REJECTED]")
            print("Security: Negative age rejected")
        else:
            self.__age = new_age
            print(f"Age updated: {self.__age}days [OK]")

    def get_height(self):
        return self.__height

    def get_age(self):
        return self.__age

    def get_info(self):
        print(f"{self.__name}: {self.__height}cm, {self.__age} days")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = SafePlant("Rose", 25, 30)
    rose.set_height(25)
    rose.set_age(30)
    rose.set_height(-5)
    print()
    print("Current plant: ", end="")
    rose.get_info()
