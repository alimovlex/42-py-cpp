#ifndef NUMERIC_PROCESSOR_H
#define NUMERIC_PROCESSOR_H

#include "DataProcessor.h"

typedef struct {
    int* values;
    size_t count;
} IntVector;

DataProcessor* create_numeric_processor(void);

#endif
