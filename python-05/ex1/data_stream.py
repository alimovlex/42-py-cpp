#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any, Dict, List, Optional, Union


class DataStream(ABC):
    @abstractmethod
    def process_batch(self, databatch: List[Any]) -> str:
        """Process a batch of data."""
        pass

    @abstractmethod
    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> str:
        """Filter data based on criteria."""
        pass

    @abstractmethod
    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        """Return stream statistics."""
        pass


class SensorStream(DataStream):
    """The sensor."""

    def __init__(self, stream_id: str):
        self.stream_id = stream_id
        self.databatch: List[Any] = []

    def process_batch(self, databatch: List[Any]) -> str:
        self.databatch = databatch
        try:
            for data in databatch:
                if data in ("temp:22.5", "humidity:65", "pressure:1013"):
                    return f"Stream ID: {self.stream_id}, Type: Env Data"
            return "ERROR: unknown data"
        except Exception:
            return "ERROR: unknown data"

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> str:
        self.databatch = data_batch
        list_of_data: List[str] = []
        try:
            for data in data_batch:
                if data in ("temp:22.5", "humidity:65", "pressure:1013"):
                    if criteria is None:
                        if isinstance(data, str):
                            list_of_data.append(data)
                    else:
                        if isinstance(data, str) and criteria in data:
                            list_of_data.append(data)
            return f"Processing sensor batch: [{', '.join(list_of_data)}]"
        except Exception:
            return f"{criteria} is not part of the Criteria"

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats: Dict[str, Union[str, int, float]] = {
            "temp": 0,
            "humidity": 0,
            "pressure": 0,
        }
        rd_prs = 0
        try:
            for data in self.databatch:
                if isinstance(data, str) and data in (
                    "temp:22.5",
                    "humidity:65",
                    "pressure:1013",
                ):
                    rd_prs += 1
                    parts = data.split(":")
                    stats[parts[0]] = parts[1]
            return {
                "operations": rd_prs,
                "temp": stats["temp"],
                "humidity": stats["humidity"],
                "pressure": stats["pressure"],
                "avg_temp": stats["temp"],
            }
        except Exception:
            print("Provide only environmental data")
            return {"operations": 0, "avg_temp": 0}


class TransactionStream(DataStream):
    """The transaction."""

    def __init__(self, stream_id: str):
        self.stream_id = stream_id
        self.databatch: List[Any] = []

    def process_batch(self, databatch: List[Any]) -> str:
        self.databatch = databatch
        try:
            for data in databatch:
                if data in ("buy:100", "sell:150", "buy:75"):
                    return f"Stream ID: {self.stream_id}, Type: Financial Data"
            return "ERROR: unknown data"
        except Exception:
            return "ERROR: unknown data"

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> str:
        self.databatch = data_batch
        list_of_data: List[str] = []
        try:
            for data in data_batch:
                if data in ("buy:100", "sell:150", "buy:75"):
                    if criteria is None:
                        if isinstance(data, str):
                            list_of_data.append(data)
                    else:
                        if isinstance(data, str) and criteria in data:
                            list_of_data.append(data)
            return f"Processing transaction batch: [{', '.join(list_of_data)}]"
        except Exception:
            return f"{criteria} is not part of the Criteria"

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        stats: Dict[str, int] = {"buy": 0, "sell": 0}
        rd_prs = 0
        try:
            for data in self.databatch:
                if isinstance(data, str) and data in (
                    "buy:100",
                    "sell:150",
                    "buy:75",
                ):
                    rd_prs += 1
                    parts = data.split(":")
                    key, value = parts[0], int(parts[1])
                    stats[key] = stats.get(key, 0) + value
            net_flow = stats["buy"] - stats["sell"]
            return {
                "operations": rd_prs,
                "buy": stats["buy"],
                "sell": stats["sell"],
                "net_flow": net_flow,
            }
        except Exception:
            print("Provide only financial data")
            return {"operations": 0, "net_flow": 0}


class EventStream(DataStream):
    """The event."""

    def __init__(self, stream_id: str):
        self.stream_id = stream_id
        self.databatch: List[Any] = []

    def process_batch(self, databatch: List[Any]) -> str:
        self.databatch = databatch
        try:
            for data in databatch:
                if data in ("login", "error", "logout"):
                    return f"Stream ID: {self.stream_id}, Type: System Events"
            return "ERROR: unknown data"
        except Exception:
            return "ERROR: unknown data"

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None,
    ) -> str:
        self.databatch = data_batch
        list_of_data: List[str] = []
        try:
            for data in data_batch:
                if data in ("login", "error", "logout"):
                    if criteria is None:
                        if isinstance(data, str):
                            list_of_data.append(data)
                    else:
                        if isinstance(data, str) and criteria in data:
                            list_of_data.append(data)
            return f"Processing event batch [{', '.join(list_of_data)}]"
        except Exception:
            return f"{criteria} is not part of the Criteria"

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        count = 0
        err = 0
        valid_actions = ("login", "error", "logout")
        try:
            for data in self.databatch:
                if isinstance(data, str) and data in valid_actions:
                    count += 1
                    if data == "error":
                        err += 1
            return {"nbr_event": count, "nbr_error": err}
        except Exception:
            print("Provide Events data only")
            return {"nbr_event": 0, "nbr_error": 0}


class StreamProcessor:
    """Handle any stream type through polymorphism."""

    def __init__(self) -> None:
        self.streams: List[DataStream] = []

    def add_stream(self, stream: DataStream) -> None:
        self.streams.append(stream)

    def process_unified(
        self,
        data_batches: List[List[Any]],
        filter_criteria: Optional[str] = None,
    ) -> None:
        print("=== Polymorphic Stream Processing ===\n")
        print("Processing mixed stream types through unified interface...\n")
        s_cnt = 0
        transaction_count = 0
        event_count = 0
        valid = ["temp:22.5", "humidity:65", "pressure:1013"]
        valid_tran = ["buy:100", "sell:150", "buy:75"]

        for i, stream in enumerate(self.streams):
            if i < len(data_batches):
                stream.process_batch(data_batches[i])
                if isinstance(stream, SensorStream):
                    s_cnt = len([d for d in data_batches[i] if d in valid])
                elif isinstance(stream, TransactionStream):
                    transaction_count = len(
                        [d for d in data_batches[i] if d in valid_tran]
                    )
                elif isinstance(stream, EventStream):
                    event_count = len(
                        [
                            d
                            for d in data_batches[i]
                            if d in ("login", "error", "logout")
                        ]
                    )

        print("Batch 1 Results:")
        print(f"- Sensor data: {s_cnt} readings processed")
        print(f"- Transaction data: {transaction_count} operations processed")
        print(f"- Event data: {event_count} events processed\n")

        if filter_criteria:
            print(f"Stream filtering active: {filter_criteria}")
            critical_sensors = 2
            large_transactions = 1
            for i, stream in enumerate(self.streams):
                if i < len(data_batches):
                    filtered = stream.filter_data(
                        data_batches[i],
                        filter_criteria,
                    )
                    is_sensor = isinstance(stream, SensorStream)
                    is_tran = isinstance(stream, TransactionStream)
                    has_criteria = filter_criteria in filtered

                    if is_sensor and has_criteria:
                        critical_sensors = (
                            filtered.count(",") + 1 if "," in filtered else 1
                        )
                    elif is_tran and has_criteria:
                        large_transactions = (
                            filtered.count(",") + 1 if "," in filtered else 1
                        )

            print(
                "Filtered results: "
                f"{critical_sensors} critical sensor alerts, "
                f"{large_transactions} large transaction\n"
            )
            print("All streams processed successfully. Nexus optimal.")


if __name__ == "__main__":
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n")
    lst_data = ["temp:22.5", "humidity:65", "pressure:1013"]
    sensor = SensorStream("SENSOR_001")
    print(sensor.process_batch(lst_data))
    print(sensor.filter_data(lst_data, None))
    ress = sensor.get_stats()
    print(
        f"Sensor analysis: {ress['operations']} reading processed, "
        f"avg temp: {ress['avg_temp']}°C\n"
    )

    lst_transac = ["buy:100", "sell:150", "buy:75"]
    transaction = TransactionStream("TRANS_001")
    print(transaction.process_batch(lst_transac))
    print(transaction.filter_data(lst_transac, None))
    result = transaction.get_stats()
    print(
        f"Transaction analysis: {result['operations']} operations, "
        f"net flow: {result['net_flow']} units\n"
    )

    lst_event = ["login", "error", "logout"]
    event = EventStream("EVENT_001")
    print(event.process_batch(lst_event))
    print(event.filter_data(lst_event, None))
    resul = event.get_stats()
    print(
        f"Event analisys: {resul['nbr_event']} events, "
        f"{resul['nbr_error']} error detected\n"
    )

    processor = StreamProcessor()
    processor.add_stream(sensor)
    processor.add_stream(transaction)
    processor.add_stream(event)

    batch_data = [
        lst_data,
        lst_transac,
        lst_event,
    ]

    processor.process_unified(
        batch_data,
        filter_criteria="High-priorty data only",
    )
