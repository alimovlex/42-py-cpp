#include "EventStream.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    DataStream base;
} EventStream;

static char* event_process_batch(DataStream* self, void** databatch, size_t count) {
    self->last_batch = databatch;
    self->last_batch_count = count;
    
    for (size_t i = 0; i < count; i++) {
        const char* str = (const char*)databatch[i];
        if (strcmp(str, "login") == 0 || strcmp(str, "error") == 0 || strcmp(str, "logout") == 0) {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Type: System Events\nStream ID: %s", self->stream_id);
            return strdup(buffer);
        }
    }
    return strdup("ERROR: unknown data");
}

static void** event_filter_data(DataStream* self, void** databatch, size_t count, const char* criteria, size_t* out_count) {
    bool has_marker = false;
    size_t found = 0;
    void** filtered = malloc(sizeof(void*) * count);

    for (size_t i = 0; i < count; i++) {
        const char* str = (const char*)databatch[i];
        if (!has_marker && (strcmp(str, "login") == 0 || strcmp(str, "error") == 0 || strcmp(str, "logout") == 0)) {
            has_marker = true;
        }
        
        if (!criteria || strstr(str, criteria)) {
            filtered[found++] = (void*)str;
        }
    }

    if (!has_marker) {
        free(filtered);
        *out_count = 0;
        return NULL;
    }

    *out_count = found;
    return filtered;
}

static void* event_get_stats(DataStream* self) {
    EventStats* stats = calloc(1, sizeof(EventStats));
    for (size_t i = 0; i < self->last_batch_count; i++) {
        const char* str = (const char*)self->last_batch[i];
        if (strcmp(str, "login") == 0 || strcmp(str, "error") == 0 || strcmp(str, "logout") == 0) {
            stats->nbr_event++;
            if (strcmp(str, "error") == 0) {
                stats->nbr_error++;
            }
        }
    }
    return stats;
}

static void event_destroy(DataStream* self) {
    free(self->stream_id);
    free(self);
}

static const DataStreamVTable event_vtable = {
    .process_batch = event_process_batch,
    .filter_data = event_filter_data,
    .get_stats = event_get_stats,
    .destroy = event_destroy
};

DataStream* create_event_stream(const char* stream_id) {
    EventStream* s = malloc(sizeof(EventStream));
    s->base.vptr = &event_vtable;
    s->base.stream_id = strdup(stream_id);
    s->base.last_batch = NULL;
    s->base.last_batch_count = 0;
    return (DataStream*)s;
}
