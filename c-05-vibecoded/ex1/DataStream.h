#ifndef DATA_STREAM_H
#define DATA_STREAM_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct DataStream DataStream;

typedef struct {
    char* (*process_batch)(DataStream* self, void** databatch, size_t count);
    void** (*filter_data)(DataStream* self, void** databatch, size_t count, const char* criteria, size_t* out_count);
    void* (*get_stats)(DataStream* self);
    void (*destroy)(DataStream* self);
} DataStreamVTable;

struct DataStream {
    const DataStreamVTable* vptr;
    char* stream_id;
    void** last_batch;
    size_t last_batch_count;
    char* last_criteria;
};

static inline char* process_batch(DataStream* self, void** databatch, size_t count) {
    return self->vptr->process_batch(self, databatch, count);
}

static inline void** filter_data(DataStream* self, void** databatch, size_t count, const char* criteria, size_t* out_count) {
    return self->vptr->filter_data(self, databatch, count, criteria, out_count);
}

static inline void* get_stats(DataStream* self) {
    return self->vptr->get_stats(self);
}

static inline void destroy_stream(DataStream* self) {
    if (self && self->vptr->destroy) {
        self->vptr->destroy(self);
    }
}

#endif
