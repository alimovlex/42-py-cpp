#!/usr/bin/env python3
from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    """DataProcessor abstract base class using ABC and @abstractmethod"""

    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        pass


class NumericProcessor(DataProcessor):
    """For processing numerical value"""

    def process(self, data: Any) -> str:
        """Process the data and return result string"""
        self.data = data
        try:
            for number in data:
                if not isinstance(number, int):
                    raise ValueError("All have to be integers")
            return f"Processing data: {data}"
        except ValueError as e:
            print(f"Processing data: {data}")
            return str(e)

    def validate(self, data: Any) -> bool:
        """Validate if data is appropriate for this processor"""
        self.data = data
        checker = True
        for num in data:
            if not isinstance(num, int):
                checker = False
        if checker:
            print("Validation: Numeric data verified")
        return checker

    def format_output(self, result: str) -> str:
        """format the output string"""
        try:
            self.result = result
            lenght_data = len(self.data)
            sum_data = sum(self.data)
            avg = sum_data / lenght_data
            return (
                f"Output: Processed {lenght_data}"
                f" numeric values, sum={sum_data}, avg={float(avg)}"
            )
        except TypeError:
            return "all elements have to be int type"


class TextProcessor(DataProcessor):
    """This is for String"""

    def process(self, data: Any) -> str:
        self.data = data
        try:
            if not isinstance(data, str):
                raise Exception("It has to be a string!")
            return f'Processing data : "{data}" '
        except Exception as e:
            return str(e)

    def validate(self, data: Any) -> bool:
        checker = True
        if not isinstance(data, str):
            checker = False
        if checker:
            print("Validation: Text data verified")
        return checker

    def format_output(self, result: str) -> str:
        self.result = result
        str = "Output: Processed text :"
        length_text = len(self.data)
        nbr_of_word = 0
        for char in self.data:
            if char == " ":
                nbr_of_word += 1
        if length_text > 0:
            nbr_of_word += 1
        return f"{str} + {length_text} characters, {nbr_of_word} words"


class LogProcessor(DataProcessor):
    """The log processor"""

    def process(self, data: Any) -> str:
        self.data = data
        try:
            if "ERROR" in data:
                raise Exception("Connection timeout")
            return f'Processing data : "{data}" '
        except Exception as e:
            return f'Processing data: "ERROR: {e}"'

    def validate(self, data: Any) -> bool:
        self.data = data
        checker = True
        if not isinstance(data, str):
            checker = False
        if checker:
            print("Validation: Log entry verified")
        return checker

    def format_output(self, result: str) -> str:
        self.result = result
        if "ERROR" in self.data:
            return "Output: [ALERT] ERROR level detected: Connection timeout"
        else:
            return f"Output: [INFO] INFO level detected: {self.data}"


if __name__ == "__main__":
    """main"""
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===\n")
    list_data = [1, 2, 3, 4, 5]
    str_data = "Hello Nexus World"
    data_log = "INFO: System ready, ERROR"
    print("Initializing Numeric Processor...")
    test = NumericProcessor()
    print(test.process(list_data))
    print(test.validate(list_data))
    print(test.format_output("hello"))
    print()
    print("Initializing Text Processor...")
    test = TextProcessor()
    print(test.process(str_data))
    print(test.validate(str_data))
    print(test.format_output("hello"))
    print()
    print("Initializing Log Processor...")
    test = LogProcessor()
    print(test.process(data_log))
    print(test.validate(data_log))
    print(test.format_output(""))

    print()
    print("=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")

    polymorf_all = [NumericProcessor(), TextProcessor(), LogProcessor()]
    new_list_data = [1, 2, 3]
    new_str_data = "helloo Nexus"
    new_data_log = "System ready"
    test_data = [new_list_data, new_str_data, new_data_log]

    for i, (processor, data) in enumerate(zip(polymorf_all, test_data), 1):
        processor.validate(data)
        processor.process(data)
        result = processor.format_output("")
        print(f"Result {i}: {result}")
    print()
    print("Foundation systems online. Nexus ready for advanced streams.")
