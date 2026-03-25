#ifndef EVENT_STREAM_H
#define EVENT_STREAM_H

#include "DataStream.h"

typedef struct {
    int nbr_event;
    int nbr_error;
} EventStats;

DataStream* create_event_stream(const char* stream_id);

#endif
