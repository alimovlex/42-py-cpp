#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "ProcessingPipeline.h"

ProcessingPipeline* create_json_adapter(const char* id);
ProcessingPipeline* create_csv_adapter(const char* id);
ProcessingPipeline* create_stream_adapter(const char* id);

#endif
