#ifndef STREAM_PROCESSOR_H
#define STREAM_PROCESSOR_H

#include "DataStream.h"

typedef struct {
    DataStream** streams;
    size_t count;
    size_t capacity;
} StreamProcessor;

StreamProcessor* create_stream_processor(void);
void add_stream(StreamProcessor* self, DataStream* stream);
void process_unified(StreamProcessor* self, void*** data_batches, size_t* batch_counts, size_t batch_count, const char* filter_criteria);
void destroy_processor(StreamProcessor* self);

#endif
