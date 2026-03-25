#include "TransactionStream.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    DataStream base;
} TransactionStream;

static char* transaction_process_batch(DataStream* self, void** databatch, size_t count) {
    self->last_batch = databatch;
    self->last_batch_count = count;
    
    for (size_t i = 0; i < count; i++) {
        const char* str = (const char*)databatch[i];
        if (strcmp(str, "buy:100") == 0 || strcmp(str, "sell:150") == 0 || strcmp(str, "buy:75") == 0) {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Type: Financial Data\nStream ID: %s", self->stream_id);
            return strdup(buffer);
        }
    }
    return strdup("ERROR: unknown data");
}

static void** transaction_filter_data(DataStream* self, void** databatch, size_t count, const char* criteria, size_t* out_count) {
    bool has_marker = false;
    size_t found = 0;
    void** filtered = malloc(sizeof(void*) * count);

    for (size_t i = 0; i < count; i++) {
        const char* str = (const char*)databatch[i];
        if (!has_marker && (strcmp(str, "buy:100") == 0 || strcmp(str, "sell:150") == 0 || strcmp(str, "buy:75") == 0)) {
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

static void* transaction_get_stats(DataStream* self) {
    TransactionStats* stats = calloc(1, sizeof(TransactionStats));
    for (size_t i = 0; i < self->last_batch_count; i++) {
        const char* str = (const char*)self->last_batch[i];
        if (strncmp(str, "buy:", 4) == 0) {
            int val = atoi(str + 4);
            stats->buy += val;
            stats->operations++;
        } else if (strncmp(str, "sell:", 5) == 0) {
            int val = atoi(str + 5);
            stats->sell += val;
            stats->operations++;
        }
    }
    stats->net_flow = stats->buy - stats->sell;
    return stats;
}

static void transaction_destroy(DataStream* self) {
    free(self->stream_id);
    free(self);
}

static const DataStreamVTable transaction_vtable = {
    .process_batch = transaction_process_batch,
    .filter_data = transaction_filter_data,
    .get_stats = transaction_get_stats,
    .destroy = transaction_destroy
};

DataStream* create_transaction_stream(const char* stream_id) {
    TransactionStream* s = malloc(sizeof(TransactionStream));
    s->base.vptr = &transaction_vtable;
    s->base.stream_id = strdup(stream_id);
    s->base.last_batch = NULL;
    s->base.last_batch_count = 0;
    return (DataStream*)s;
}
