#include <stdio.h>
#include <string.h>
#include "Stages.h"
#include "Adapters.h"
#include "NexusManager.h"

int main(void) {
    printf("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM (C VERSION) ===\n\n");
    printf("Initializing Nexus Manager...\n");
    printf("Pipeline capacity: 1000 streams/second\n\n");

    const char* dummy_data = "dummy";
    const char* data_csv = "user,action,timestamp";

    ProcessingStage* input = create_input_stage();
    stage_process(input, (void*)dummy_data);
    
    ProcessingStage* trans = create_transform_stage();
    stage_process(trans, (void*)dummy_data);
    
    ProcessingStage* output = create_output_stage();
    char* out_res = (char*)stage_process(output, (void*)dummy_data);
    free(out_res);

    stage_destroy(input);
    stage_destroy(trans);
    stage_destroy(output);

    printf("\n=== Multi-Format Data Processing ===\n\n");

    ProcessingPipeline* json_adapter = create_json_adapter("A");
    pipeline_process(json_adapter, (void*)dummy_data);
    printf("\n");

    ProcessingPipeline* csv_adapter = create_csv_adapter("B");
    pipeline_process(csv_adapter, (void*)data_csv);
    printf("\n");

    ProcessingPipeline* stream_adapter = create_stream_adapter("C");
    pipeline_process(stream_adapter, (void*)dummy_data);
    printf("\n");

    NexusManager* nexus = create_nexus_manager();
    nexus_add_pipeline(nexus, json_adapter);
    nexus_add_pipeline(nexus, csv_adapter);
    nexus_add_pipeline(nexus, stream_adapter);

    nexus_demonstrate_chain(nexus);
    nexus_demonstrate_error(nexus);

    printf("\nNexus Integration complete. All systems operational\n");

    nexus_destroy(nexus);
    return 0;
}
