#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct DataProcessor DataProcessor;

typedef struct {
    char* (*process)(DataProcessor* self, void* data);
    bool  (*validate)(DataProcessor* self, void* data);
    char* (*format_output)(DataProcessor* self, const char* result);
    void  (*destroy)(DataProcessor* self);
} DataProcessorVTable;

struct DataProcessor {
    const DataProcessorVTable* vptr;
    void* data;
    char* result;
};

static inline char* process(DataProcessor* self, void* data) {
    return self->vptr->process(self, data);
}

static inline bool validate(DataProcessor* self, void* data) {
    return self->vptr->validate(self, data);
}

static inline char* format_output(DataProcessor* self, const char* result) {
    return self->vptr->format_output(self, result);
}

static inline void destroy(DataProcessor* self) {
    if (self && self->vptr->destroy) {
        self->vptr->destroy(self);
    }
}

#endif
