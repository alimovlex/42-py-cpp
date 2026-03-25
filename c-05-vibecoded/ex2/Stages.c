#include "Stages.h"
#include <stdio.h>
#include <string.h>

// Input Stage
typedef struct { ProcessingStage base; } InputStage;
static void* input_process(ProcessingStage* self, void* data) {
    printf("Stage 1: Input validation and parsing\n");
    if (!data) printf("Invalid data!\n");
    return data;
}
static void input_destroy(ProcessingStage* self) { free(self); }
static const ProcessingStageVTable input_vtable = { .process = input_process, .destroy = input_destroy };
ProcessingStage* create_input_stage(void) {
    InputStage* s = malloc(sizeof(InputStage));
    s->base.vptr = &input_vtable;
    return (ProcessingStage*)s;
}

// Transform Stage
typedef struct { ProcessingStage base; } TransformStage;
static void* transform_process(ProcessingStage* self, void* data) {
    printf("Stage 2: Data transformation and enrichment\n");
    if (!data) printf("Invalid data!\n");
    return data;
}
static void transform_destroy(ProcessingStage* self) { free(self); }
static const ProcessingStageVTable transform_vtable = { .process = transform_process, .destroy = transform_destroy };
ProcessingStage* create_transform_stage(void) {
    TransformStage* s = malloc(sizeof(TransformStage));
    s->base.vptr = &transform_vtable;
    return (ProcessingStage*)s;
}

// Output Stage
typedef struct { ProcessingStage base; } OutputStage;
static void* output_process(ProcessingStage* self, void* data) {
    printf("Stage 3: Output formatting and delivery\n");
    return strdup("Processed Data Object");
}
static void output_destroy(ProcessingStage* self) { free(self); }
static const ProcessingStageVTable output_vtable = { .process = output_process, .destroy = output_destroy };
ProcessingStage* create_output_stage(void) {
    OutputStage* s = malloc(sizeof(OutputStage));
    s->base.vptr = &output_vtable;
    return (ProcessingStage*)s;
}
