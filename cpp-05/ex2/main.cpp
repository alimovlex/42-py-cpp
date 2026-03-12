//
// Created by robot on 3/12/26.
//
#include "InputStage.hpp"
#include "TransformStage.hpp"
#include "OutputStage.hpp"
#include "JSONAdapter.hpp"
#include "StreamAdapter.hpp"
#include "CSVAdapter.hpp"
#include "NexusManager.hpp"

int main(int argc, char** argv)
{
    std::cout << "=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n" << std::endl;
    std::cout << "Initializing Nexus Manager..." << std::endl;
    std::cout << "Pipeline capacity: 1000 streams/second\n" << std::endl;

    std::map<std::string, std::any> data = {{"sensor", "temp"}, {"value", 23.5}, {"unit", "C"}};
    std::string data_csv = "user,action,timestamp";

    InputStage input; input.process(data);
    TransformStage trans; trans.process(data);
    OutputStage output; output.process(data);

    std::cout << "\n=== Multi-Format Data Processing ===\n" << std::endl;

    auto json_adapter = std::make_shared<JSONAdapter>("A");
    json_adapter->process(data);
    std::cout << std::endl;

    auto csv_adapter = std::make_shared<CSVAdapter>("B");
    csv_adapter->process(data_csv);
    std::cout << std::endl;

    auto stream_adapter = std::make_shared<StreamAdapter>("C");
    stream_adapter->process("Real-time sensor stream");
    std::cout << std::endl;

    NexusManager nexus;
    nexus.add_pipeline(json_adapter);
    nexus.add_pipeline(csv_adapter);
    nexus.add_pipeline(stream_adapter);

    nexus.demonstrate_chaining();
    nexus.demonstrate_error_recovery();

    std::cout << "\nNexus Integration complete. All systems operational" << std::endl;

    return 0;
}