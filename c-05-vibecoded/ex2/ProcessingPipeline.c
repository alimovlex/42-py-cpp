#include "ProcessingPipeline.h"
#include <string.h>

void pipeline_add_stage(ProcessingPipeline* self, ProcessingStage* stage) {
    if (self->stage_count == self->stage_capacity) {
        self->stage_capacity = self->stage_capacity == 0 ? 4 : self->stage_capacity * 2;
        self->stages = realloc(self->stages, sizeof(ProcessingStage*) * self->stage_capacity);
    }
    self->stages[self->stage_count++] = stage;
}

void pipeline_base_destroy(ProcessingPipeline* self) {
    for (size_t i = 0; i < self->stage_count; i++) {
        stage_destroy(self->stages[i]);
    }
    free(self->stages);
    free(self->pipeline_id);
}
