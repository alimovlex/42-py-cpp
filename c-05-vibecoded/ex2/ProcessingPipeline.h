#ifndef PROCESSING_PIPELINE_H
#define PROCESSING_PIPELINE_H

#include "ProcessingStage.h"

typedef struct ProcessingPipeline ProcessingPipeline;

typedef struct {
    void (*process)(ProcessingPipeline* self, void* data);
    void (*destroy)(ProcessingPipeline* self);
} ProcessingPipelineVTable;

struct ProcessingPipeline {
    const ProcessingPipelineVTable* vptr;
    char* pipeline_id;
    ProcessingStage** stages;
    size_t stage_count;
    size_t stage_capacity;
};

void pipeline_add_stage(ProcessingPipeline* self, ProcessingStage* stage);
static inline void pipeline_process(ProcessingPipeline* self, void* data) {
    self->vptr->process(self, data);
}
static inline void pipeline_destroy(ProcessingPipeline* self) {
    if (self && self->vptr->destroy) self->vptr->destroy(self);
}

#endif
