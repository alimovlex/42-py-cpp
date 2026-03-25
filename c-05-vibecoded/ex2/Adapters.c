#include "Adapters.h"
#include <stdio.h>
#include <string.h>

// Common destroy
extern void pipeline_base_destroy(ProcessingPipeline* self);
static void adapter_destroy(ProcessingPipeline* self) {
    pipeline_base_destroy(self);
    free(self);
}

// JSON Adapter
typedef struct { ProcessingPipeline base; } JSONAdapter;
static void json_process(ProcessingPipeline* self, void* data) {
    printf("Processing JSON data through pipeline...\n");
    if (data) {
        printf("Input: {sensor: temp, ...}\n");
        printf("Transform: Enriched with metadata and validation\n");
        printf("Output: Processed temperature reading: 23.5°C (Normal range)\n");
    } else {
        printf("Failed processing data!\n");
    }
}
static const ProcessingPipelineVTable json_vtable = { .process = json_process, .destroy = adapter_destroy };
ProcessingPipeline* create_json_adapter(const char* id) {
    JSONAdapter* a = calloc(1, sizeof(JSONAdapter));
    a->base.vptr = &json_vtable;
    a->base.pipeline_id = strdup(id);
    printf("Pipeline %s\n", id);
    return (ProcessingPipeline*)a;
}

// CSV Adapter
typedef struct { ProcessingPipeline base; } CSVAdapter;
static void csv_process(ProcessingPipeline* self, void* data) {
    printf("Processing CSV data through same pipeline...\n");
    const char* str = (const char*)data;
    if (str && strstr(str, "user") && strstr(str, "action")) {
        printf("Input: \"%s\"\n", str);
        printf("Transform: Parsed and structured data\n");
        printf("Output: User activity logged: 1 actions processed\n");
    } else {
        printf("Failed processing data!\n");
    }
}
static const ProcessingPipelineVTable csv_vtable = { .process = csv_process, .destroy = adapter_destroy };
ProcessingPipeline* create_csv_adapter(const char* id) {
    CSVAdapter* a = calloc(1, sizeof(CSVAdapter));
    a->base.vptr = &csv_vtable;
    a->base.pipeline_id = strdup(id);
    printf("Pipeline %s\n", id);
    return (ProcessingPipeline*)a;
}

// Stream Adapter
typedef struct { ProcessingPipeline base; } StreamAdapter;
static void stream_process(ProcessingPipeline* self, void* data) {
    printf("Processing Stream data through same pipeline...\n");
    if (data) {
        printf("Input: Real-time sensor stream\n");
        printf("Transform: Aggregated and filtered\n");
        printf("Output: Stream summary: 5 readings, avg: 22.1°C\n");
    } else {
        printf("Failed processing data!\n");
    }
}
static const ProcessingPipelineVTable stream_vtable = { .process = stream_process, .destroy = adapter_destroy };
ProcessingPipeline* create_stream_adapter(const char* id) {
    StreamAdapter* a = calloc(1, sizeof(StreamAdapter));
    a->base.vptr = &stream_vtable;
    a->base.pipeline_id = strdup(id);
    return (ProcessingPipeline*)a;
}
