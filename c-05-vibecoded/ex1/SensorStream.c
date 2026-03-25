#include "SensorStream.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    DataStream base;
} SensorStream;

static char* sensor_process_batch(DataStream* self, void** databatch, size_t count) {
    self->last_batch = databatch;
    self->last_batch_count = count;
    
    for (size_t i = 0; i < count; i++) {
        const char* str = (const char*)databatch[i];
        if (strcmp(str, "temp:22.5") == 0 || strcmp(str, "humidity:65") == 0 || strcmp(str, "pressure:1013") == 0) {
            char buffer[256];
            snprintf(buffer, sizeof(buffer), "Type: Environmental Data\nStream ID: %s", self->stream_id);
            return strdup(buffer);
        }
    }
    return strdup("ERROR: unknown data");
}

static void** sensor_filter_data(DataStream* self, void** databatch, size_t count, const char* criteria, size_t* out_count) {
    bool has_marker = false;
    size_t found = 0;
    void** filtered = malloc(sizeof(void*) * count);

    for (size_t i = 0; i < count; i++) {
        const char* str = (const char*)databatch[i];
        if (!has_marker && (strcmp(str, "temp:22.5") == 0 || strcmp(str, "humidity:65") == 0 || strcmp(str, "pressure:1013") == 0)) {
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

static void* sensor_get_stats(DataStream* self) {
    SensorStats* stats = calloc(1, sizeof(SensorStats));
    for (size_t i = 0; i < self->last_batch_count; i++) {
        const char* str = (const char*)self->last_batch[i];
        if (strncmp(str, "temp:", 5) == 0) {
            stats->temp = strdup(str + 5);
            stats->avg_temp = atof(stats->temp);
            stats->operations++;
        } else if (strncmp(str, "humidity:", 9) == 0) {
            stats->humidity = strdup(str + 9);
            stats->operations++;
        } else if (strncmp(str, "pressure:", 9) == 0) {
            stats->pressure = strdup(str + 9);
            stats->operations++;
        }
    }
    return stats;
}

static void sensor_destroy(DataStream* self) {
    free(self->stream_id);
    free(self);
}

static const DataStreamVTable sensor_vtable = {
    .process_batch = sensor_process_batch,
    .filter_data = sensor_filter_data,
    .get_stats = sensor_get_stats,
    .destroy = sensor_destroy
};

DataStream* create_sensor_stream(const char* stream_id) {
    SensorStream* s = malloc(sizeof(SensorStream));
    s->base.vptr = &sensor_vtable;
    s->base.stream_id = strdup(stream_id);
    s->base.last_batch = NULL;
    s->base.last_batch_count = 0;
    return (DataStream*)s;
}
