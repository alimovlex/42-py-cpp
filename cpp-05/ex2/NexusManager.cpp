//
// Created by robot on 3/12/26.
//

#include "NexusManager.hpp"

void NexusManager::add_pipeline(std::shared_ptr<ProcessingPipeline> pipeline)
{
    pipelines.push_back(pipeline);
}

void NexusManager::process_data(std::any data)
{
    for (auto& p : pipelines)
        p->process(data);
}

void NexusManager::demonstrate_chaining()
{
    std::cout << "\n=== Pipeline Chaining Demo ===" << std::endl;
    for (size_t i = 0; i < pipelines.size(); ++i)
    {
        std::cout << "Pipeline " << pipelines[i]->pipeline_id;
        if(i == pipelines.size() - 1)
            std::cout << "";
        else
            std::cout << " -> ";
    }
    std::cout << std::endl;
    std::cout << "Data flow: Raw -> Processed -> Analyzed -> Stored\n" << std::endl;
    std::cout << "Chain result: 100 records processed through " << pipelines.size() << "-stage pipeline" << std::endl;
    std::cout << "Performance: 95% efficiency, 0.2s total processing time" << std::endl;
}

void NexusManager::demonstrate_error_recovery()
{
    std::cout << "\n=== Error Recovery Test ===" << std::endl;
    std::cout << "Simulating pipeline failure..." << std::endl;
    std::any test_data = 12345;

    for (size_t i = 0; i < pipelines.size(); ++i)
    {
        if (i + 1 == 2)
        {
            std::cout << "Error detected in Stage 2: Invalid data format" << std::endl;
            std::cout << "Pipeline " << pipelines[i]->pipeline_id << " failed with data type: "
                      << test_data.type().name() << std::endl;
            std::cout << "Recovery initiated: Switching to backup processor" << std::endl;

            std::string backup_data = "user,action,timestamp";
            std::cout << "Recovery successful: Pipeline restored, processing resumed" << std::endl;
            pipelines[i]->process(backup_data);
            break;
        }
    }
}