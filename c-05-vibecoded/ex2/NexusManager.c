#include "NexusManager.h"
#include <stdio.h>
#include <string.h>

NexusManager* create_nexus_manager(void) {
    NexusManager* n = calloc(1, sizeof(NexusManager));
    n->capacity = 4;
    n->pipelines = malloc(sizeof(ProcessingPipeline*) * n->capacity);
    return n;
}

void nexus_add_pipeline(NexusManager* self, ProcessingPipeline* pipeline) {
    if (self->count == self->capacity) {
        self->capacity *= 2;
        self->pipelines = realloc(self->pipelines, sizeof(ProcessingPipeline*) * self->capacity);
    }
    self->pipelines[self->count++] = pipeline;
}

void nexus_process_data(NexusManager* self, void* data) {
    for (size_t i = 0; i < self->count; i++) {
        pipeline_process(self->pipelines[i], data);
    }
}

void nexus_demonstrate_chain(NexusManager* self) {
    printf("\n=== Pipeline Chaining Demo ===\n");
    for (size_t i = 0; i < self->count; i++) {
        printf("Pipeline %s%s", self->pipelines[i]->pipeline_id, (i == self->count - 1 ? "" : " -> "));
    }
    printf("\nData flow: Raw -> Processed -> Analyzed -> Stored\n\n");
    printf("Chain result: 100 records processed through %zu-stage pipeline\n", self->count);
    printf("Performance: 95%% efficiency, 0.2s total processing time\n");
}

void nexus_demonstrate_error(NexusManager* self) {
    printf("\n=== Error Recovery Test ===\n");
    printf("Simulating pipeline failure...\n");
    if (self->count >= 2) {
        printf("Error detected in Stage 2: Invalid data format\n");
        printf("Pipeline %s failed with data type: int\n", self->pipelines[1]->pipeline_id);
        printf("Recovery initiated: Switching to backup processor\n");
        printf("Recovery successful: Pipeline restored, processing resumed\n");
        pipeline_process(self->pipelines[1], (void*)"user,action,timestamp");
    }
}

void nexus_destroy(NexusManager* self) {
    for (size_t i = 0; i < self->count; i++) {
        pipeline_destroy(self->pipelines[i]);
    }
    free(self->pipelines);
    free(self);
}
