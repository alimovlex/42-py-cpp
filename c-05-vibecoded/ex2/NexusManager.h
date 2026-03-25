#ifndef NEXUS_MANAGER_H
#define NEXUS_MANAGER_H

#include "ProcessingPipeline.h"

typedef struct {
    ProcessingPipeline** pipelines;
    size_t count;
    size_t capacity;
} NexusManager;

NexusManager* create_nexus_manager(void);
void nexus_add_pipeline(NexusManager* self, ProcessingPipeline* pipeline);
void nexus_process_data(NexusManager* self, void* data);
void nexus_demonstrate_chain(NexusManager* self);
void nexus_demonstrate_error(NexusManager* self);
void nexus_destroy(NexusManager* self);

#endif
