#ifndef PROCESSING_STAGE_H
#define PROCESSING_STAGE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct ProcessingStage ProcessingStage;

typedef struct {
    void* (*process)(ProcessingStage* self, void* data);
    void  (*destroy)(ProcessingStage* self);
} ProcessingStageVTable;

struct ProcessingStage {
    const ProcessingStageVTable* vptr;
};

static inline void* stage_process(ProcessingStage* self, void* data) {
    return self->vptr->process(self, data);
}

static inline void stage_destroy(ProcessingStage* self) {
    if (self && self->vptr->destroy) {
        self->vptr->destroy(self);
    }
}

#endif
