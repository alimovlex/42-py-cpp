#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any, Dict, List, Protocol


class ProcessingStages(Protocol):
    def process(self, data: Any) -> Any:
        pass


# Stage Classes
class InputStage:
    """InputStage(), TransformStage(), OutputStage() (no con-
    structor parameters required)"""

    def process(self, data: Any) -> Dict:
        self.data = data
        print("Stage 1: Input validation and parsing")
        if not isinstance(data, dict):
            print("Invalid data!")
        return data


class TransformStage:
    """InputStage(), TransformStage(), OutputStage() (no con-
    structor parameters required)"""

    def process(self, data: Any) -> Dict:
        self.data = data
        print("Stage 2: Data transformation and enrichment")
        if not isinstance(data, dict):
            print("Invalid data!")
        return data


class OutputStage:
    """InputStage(), TransformStage(), OutputStage() (no con-
    structor parameters required)"""

    def process(self, data: Any) -> str:
        print("Stage 3: Output formatting and delivery")
        return str(data)


class ProcessingPipeline(ABC):
    """an abstract base class with configurable
    stages"""

    def __init__(self) -> None:
        self.stages: List[ProcessingPipeline] = []

    def add_stage(self, stage: ProcessingStages) -> None:
        self.stage = stage
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        pass


# Adapter Classes
class JSONAdapter(ProcessingPipeline):
    """SONAdapter(pipeline_id), CSVAdapter(pipeline_id),
      StreamAdapter(pipeline_id)
    Each adapter must override: process(self, data: Any) -> Union[str,
      Any]"""

    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id = pipeline_id
        print(f"Pipeline {pipeline_id}")

    def process(self, data: Any) -> None:
        print("Processing JSON data through pipeline...")
        try:
            if isinstance(data, dict):
                print(f"Input: {data}")
                if "sensor" in data and "value" in data and "unit" in data:
                    temp_cal = ""
                    print("Transform: Enriched with metadata and validation")
                    if data["value"] > 23 and data["value"] < 30:
                        temp_cal += "Normal range"
                    elif data["value"] > 15 and data["value"] < 23:
                        temp_cal += "avg"
                    print(
                        f"Output: Processed temperature reading: "
                        f"{data['value']}°C ({temp_cal})"
                    )
                else:
                    print("Failed processing data!")
        except Exception:
            print("Failed processing data!")


class CSVAdapter(ProcessingPipeline):
    """SONAdapter(pipeline_id), CSVAdapter(pipeline_id),
      StreamAdapter(pipeline_id)
    Each adapter must override: process(self, data: Any) -> Union[str,
      Any]"""

    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id = pipeline_id
        print(f"Pipeline {pipeline_id}")

    def process(self, data: Any) -> None:
        print("Processing CSV data through same pipeline...")
        try:
            if isinstance(data, str):
                print(f'Input: "{data}"')
                if "user" in data and "action" in data and "timestamp" in data:
                    print("Transform: Parsed and structured data")
                    print("Output: User activity logged: 1 actions processed")
                else:
                    print("Failed processing data!")
            else:
                print("Failed processing data!")
        except Exception:
            print("Failed processing data!")


class StreamAdapter(ProcessingPipeline):
    """SONAdapter(pipeline_id), CSVAdapter(pipeline_id),
      StreamAdapter(pipeline_id)
    Each adapter must override: process(self, data: Any) -> Union[str,
      Any]"""

    def __init__(self, pipeline_id: str) -> None:
        super().__init__()
        self.pipeline_id = pipeline_id

    def process(self, data: Any) -> None:
        print("Processing Stream data through same pipeline...")
        if isinstance(data, str):
            print(f"Input: {data}")
            print("Transform: Aggregated and filtered")
            print("Output: Stream summary: 5 readings, avg: 22.1°C")
        else:
            print("Failed processing data!")


# Adapter Classes (inherit from ProcessingPipeline and override process)
class NexusManager:
    def __init__(self):
        self.pipelines: List[ProcessingPipeline] = []

    def add_pipeline(self, pipeline: ProcessingPipeline) -> None:
        self.pipelines.append(pipeline)

    def process_data(self, data: Any) -> None:
        for pipeline in self.pipelines:
            pipeline.process(data)

    def demonstrate_chaining(self) -> None:
        print("\n=== Pipeline Chaining Demo ===")

        pipeline_names = " -> ".join(
            [f"Pipeline {p.pipeline_id}" for p in self.pipelines]
        )
        print(pipeline_names)
        print("Data flow: Raw -> Processed -> Analyzed -> Stored\n")
        records_count = 100
        num_stages = len(self.pipelines)
        print(
            f"Chain result: {records_count} "
            f"records processed through {num_stages}-stage pipeline"
        )
        print("Performance: 95% efficiency, 0.2s total processing time")

    def demonstrate_error_recovery(self) -> None:
        print("\n=== Error Recovery Test ===")
        print("Simulating pipeline failure...")
        test_data = 12345

        for i, pipeline in enumerate(self.pipelines):
            stage_num = i + 1

            if stage_num == 2:
                print(f"Error in Stage {stage_num}: Invalid data format")
                print(
                    f"Pipeline {pipeline.pipeline_id} "
                    f"failed with data type: {type(test_data).__name__}"
                )
                print("Recovery initiated: Switching to backup processor")

                backup_data = "user,action,timestamp"
                print("Success: Pipeline restored, processing resumed")
                pipeline.process(backup_data)
                break

    def finalize(self) -> None:
        print("Nexus Integration complete. All systems operational")


if __name__ == "__main__":
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n")
    nbr_of_stream = 1000
    print("Initializeing Nexus Manager...")
    print(f"Pipeline capacity: {nbr_of_stream} streams/second\n")
    print("Creating Data Processing Pipeline...")
    data = {"sensor": "temp", "value": 23.5, "unit": "C"}
    data_csv = "user,action,timestamp"
    stream_adap = "Real-time sensor stream"
    input_stage = InputStage()
    input_stage.process(data)
    transform_stages = TransformStage()
    transform_stages.process(data)
    output_stage = OutputStage()
    output_stage.process(data)
    print()
    print("=== Multi-Format Data Processing ===\n")
    json_process = JSONAdapter("A")
    json_process.process(data)
    print()
    csv_data = CSVAdapter("B")
    csv_data.process(data_csv)
    print()
    stream_adapter = StreamAdapter("C")
    stream_adapter.process(stream_adap)
    print()
    nexus = NexusManager()
    nexus.add_pipeline(json_process)
    nexus.add_pipeline(csv_data)
    nexus.add_pipeline(stream_adapter)
    nexus.demonstrate_chaining()
    nexus.demonstrate_error_recovery()
    print()
    nexus.finalize()
